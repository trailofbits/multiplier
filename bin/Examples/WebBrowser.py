# Copyright 2024, Peter Goodman. All rights reserved.

"""
This script implements a simple code browser using Python's `nicegui` package
as the GUI library.
"""

import abc
import argparse
import collections
import html
from pathlib import PurePath
from typing import Dict, Set, DefaultDict, List, Tuple, Optional, Any, Callable

import multiplier as mx
import nicegui.elements.mixins.content_element

fe = mx.frontend
ast = mx.ast

from nicegui.events import ValueChangeEventArguments
from nicegui import ui


NEXT_ID: int = 0
FILE_ID_PREFIX: str = 'file_id_'
FILE_LOCATION_CACHE = fe.FileLocationCache()
EMPTY_TOKENS = fe.TokenRange.create([])
HASH = fe.UserToken(
    kind=fe.TokenKind.HASH,
    category=fe.TokenCategory.PUNCTUATION,
    data="#"
)
COLON = fe.UserToken(
    kind=fe.TokenKind.COLON,
    category=fe.TokenCategory.PUNCTUATION,
    data=":"
)
SPACE = fe.UserToken(
    kind=fe.TokenKind.WHITESPACE,
    category=fe.TokenCategory.WHITESPACE,
    data=" "
)
TEXT_EXPANSION = fe.UserToken(
    kind=fe.TokenKind.UNKNOWN,
    category=fe.TokenCategory.UNKNOWN,
    data="expansion"
)
TEXT_DIRECTIVE = fe.UserToken(
    kind=fe.TokenKind.UNKNOWN,
    category=fe.TokenCategory.UNKNOWN,
    data="directive"
)
TEXT_NEAR = fe.UserToken(
    kind=fe.TokenKind.UNKNOWN,
    category=fe.TokenCategory.UNKNOWN,
    data="near"
)

FileOrFragment = fe.File | mx.Fragment

def next_id() -> str:
    """Generate a unique ID for an HTML node."""
    global NEXT_ID
    ret = f"t_{NEXT_ID}"
    NEXT_ID += 1
    return ret


def containing_entity(entity: Optional[mx.Entity]) -> Optional[FileOrFragment]:
    """Figure out the file containing an entity, and if that cannot be found,
    the fragment containing the entity. Returns `None` if no file or
    fragment contains the entity."""
    if isinstance(entity, (ast.Decl, ast.Stmt, ast.Designator,
                           ast.CXXBaseSpecifier, ast.CXXCtorInitializer,
                           ast.Attr)):
        fragment = mx.Fragment.containing(entity)
        return fe.File.containing(fragment) or fragment

    elif isinstance(entity, mx.Fragment):
        return fe.File.containing(entity) or entity

    elif isinstance(entity, fe.File):
        return entity

    elif isinstance(entity, fe.Macro):
        fragment = mx.Fragment.containing(entity)
        return fe.File.containing(fragment) or fragment

    return None


def file_line_col(entity: mx.Entity) -> Optional[Tuple[fe.File, int, int]]:
    """Try to get the `(file, line, column)` for an entity."""

    if isinstance(entity, fe.Compilation):
        return entity.main_source_file, 1, 1

    file: Optional[fe.File] = fe.File.containing(entity)
    if file is None:
        return None

    if isinstance(entity, fe.Token):
        tokens = fe.TokenRange.create(entity, entity)
    elif not hasattr(entity, 'tokens'):
        return None
    else:
        tokens = entity.tokens
        if tokens.empty and hasattr(entity, 'token'):
            return file_line_col(entity.token)

    if tokens.empty:
        return None

    global FILE_LOCATION_CACHE
    if line_col := tokens.file_tokens.front.location(FILE_LOCATION_CACHE):
        return (file, line_col[0], line_col[1])

    return None


def file_line_col_token_list(entity: mx.Entity, full_path=True) -> List[fe.UserToken]:
    """Return the `file:line:col` of `entity` as a list of `UserToken`,
    suitable to be used in the creation of a `TokenRange`."""

    loc = file_line_col(entity)
    if loc is None:
        return []

    file, line, col = loc

    global COLON
    path = next(file.paths)
    return [
        fe.UserToken(
            kind=fe.TokenKind.HEADER_NAME,
            category=fe.TokenCategory.FILE_NAME,
            related_entity=file,
            data=full_path and str(path) or path.name
        ),
        COLON,
        fe.UserToken(
            kind=fe.TokenKind.NUMERIC_CONSTANT,
            category=fe.TokenCategory.LINE_NUMBER,
            data=str(line)
        ),
        COLON,
        fe.UserToken(
            kind=fe.TokenKind.NUMERIC_CONSTANT,
            category=fe.TokenCategory.COLUMN_NUMBER,
            data=str(col)
        )
    ]


def make_token_range(prefix: List[fe.UserToken | fe.Token],
                     sep: List[fe.UserToken | fe.Token],
                     suffix: List[fe.UserToken | fe.Token]) -> fe.TokenRange:
    """Create a token range where there's a prefix, a separator, and a suffix,
    and we only want the separator if we have both a prefix and suffix."""
    if not len(prefix):
        return fe.TokenRange.create(suffix)
    elif not len(suffix):
        return fe.TokenRange.create(prefix)
    else:
        return fe.TokenRange.create(prefix + sep + suffix)


def entity_name(entity: mx.Entity, full_name=True) -> fe.TokenRange:
    """Return the name of an entity as a token range."""
    if isinstance(entity, fe.File):
        for path in entity.paths:
            return fe.TokenRange.create([
                fe.UserToken(
                    kind=fe.TokenKind.HEADER_NAME,
                    category=fe.TokenCategory.FILE_NAME,
                    related_entity=entity,
                    data=full_name and str(path) or path.name
                )
            ])
    elif isinstance(entity, mx.Fragment):
        for decl in entity.top_level_declarations:
            if isinstance(decl, ast.NamedDecl):
                return entity_name(decl, full_name)

        for tle in entity.preprocessed_code:
            if isinstance(tle, fe.MacroExpansion):
                if directive := tle.definition:
                    return make_token_range(
                        [directive.name, SPACE, TEXT_EXPANSION],
                        [SPACE, TEXT_NEAR, SPACE],
                        file_line_col_token_list(tle, full_name)
                    )
            elif isinstance(tle, fe.MacroDirective):
                return make_token_range(
                    [HASH, tle.directive_name, SPACE, TEXT_DIRECTIVE],
                    [SPACE, TEXT_NEAR, SPACE],
                    file_line_col_token_list(tle, full_name)
                )
            elif isinstance(tle, mx.Fragment):
                return entity_name(tle, full_name)
            break

    elif isinstance(entity, ast.NamedDecl):
        opts = ast.QualifiedNameRenderOptions(fully_qualified=full_name)
        return entity.qualified_name(opts)

    elif isinstance(entity, fe.DefineMacroDirective):
        name = entity.name
        return fe.TokenRange.create(name, name)

    elif isinstance(entity, fe.Compilation):
        return fe.TokenRange.create([
            fe.UserToken(
                kind=fe.TokenKind.UNKNOWN,
                category=fe.Token.categorize(entity),
                data=entity.__class__.__name__,
            ),
            SPACE,
            fe.UserToken(
                kind=fe.TokenKind.NUMERIC_CONSTANT,
                category=fe.Token.categorize(entity),
                data=str(entity.id),
                related_entity=entity
            )
        ])

    elif isinstance(entity, ast.Type):
        return entity.tokens

    return make_token_range(
        [
            fe.UserToken(
                kind=fe.TokenKind.UNKNOWN,
                category=fe.Token.categorize(entity),
                data=entity.__class__.__name__,
            ),
            SPACE,
            fe.UserToken(
                kind=fe.TokenKind.NUMERIC_CONSTANT,
                category=fe.Token.categorize(entity),
                data=str(entity.id),
                related_entity=entity
            )
        ],
        [SPACE, TEXT_NEAR, SPACE],
        file_line_col_token_list(entity, full_name)
    )


def file_tree(index: mx.Index) -> List[Dict]:
    """Generate a file tree, grouping together empty directories (sort of)
    so that it's easier to jump right into folders that contain actual files."""
    global FILE_ID_PREFIX

    has_files: Set[PurePath] = set()
    file_paths = index.file_paths

    # Create leaf nodes, and identify which directories contain at least one
    # file.
    for file_path, file_id in file_paths.items():
        has_files.add(file_path.parent)

    # Group the paths into folders that have at least one file in them. This is
    # so that we don't have to see crazy deep folder trees all the time.
    sub_lists: DefaultDict[PurePath, List[Tuple[PurePath, int]]] = collections.defaultdict(list)
    for file_path, file_id in file_paths.items():
        path = PurePath(
            len(file_path.drive) > 0 and file_path.drive or file_path.root)
        for part in file_path.parts:
            path = path / part
            if path in has_files:
                sub_lists[path].append((file_path, file_id))
                break

    roots: List[Dict] = []
    seen: Set[int] = set()

    # Build up the tree.
    for parent_path, sub_list in sub_lists.items():
        root_item = {
            'label': str(parent_path),
            'id': next_id(),
            'children': [],
        }
        roots.append(root_item)
        nodes: Dict[PurePath, Dict] = {}

        for path, file_id in sub_list:
            if file_id in seen:
                continue

            last = root_item
            full_base = parent_path
            base = PurePath()

            for part in path.relative_to(parent_path, walk_up=False).parts:
                base = base / part
                full_base = full_base / part
                item = nodes.setdefault(base, {
                    'label': str(part),
                    'id': next_id(),
                    'children': [],
                })
                if item not in last['children']:
                    last['children'].append(item)
                last = item

            del last['children']
            last['id'] = f"{FILE_ID_PREFIX}{file_id}"
            seen.add(file_id)

    return roots


class EntityViewer(abc.ABC):

    @abc.abstractmethod
    def open_entity(self, entity: mx.Entity) -> None:
        ...


class Code(nicegui.elements.mixins.content_element.ContentElement):
    def __init__(self, text: str):
        text = html.escape(text).replace('\t', '    ').replace(' ', '&nbsp;')
        super().__init__(content=text, tag='kbd')


def on_click_file(index: mx.Index, code_viewer: EntityViewer) -> Callable[..., Any]:
    """Create an event that opens a file."""

    def do_event(event):
        """When a file is clicked, trigger a refresh of the code view"""
        global FILE_ID_PREFIX

        if not isinstance(event, ValueChangeEventArguments):
            return

        if not event.value.startswith(FILE_ID_PREFIX):
            return

        if file := index.file(int(event.value[len(FILE_ID_PREFIX):])):
            code_viewer.open_entity(file)

    return do_event


def on_click_token(entity: mx.Entity, code_viewer: EntityViewer) -> Callable[..., Any]:
    """Create an event that is triggered when a nentity is clicked."""
    def do_event(event):
        code_viewer.open_entity(entity)
    return do_event


class TokenTreeVisitor(fe.TokenTreeVisitor):
    """Custom version of `TokenTreeVisitor` that allows us to control the
    expansion behaviour when serializing a `fe.TokenTree` into a
    `fe.TokenRange`. More precise control can be had by manually traversing
    the token tree."""

    def should_expand(self, sub: fe.MacroSubstitution) -> bool:

        # Always expand the sequence of tokens that makes up a file path into
        # a `HEADER_NAME` token inside of an `#include`-like directive.
        if parent := sub.parent:
            if isinstance(parent, fe.IncludeLikeMacroDirective):
                return True
        return super().should_expand(sub)


class CodeTabs(EntityViewer):
    """Render out tabs of code. This tries to preference showing files, and
    failing that, shows fragments (all by way of `containing_entity`)."""

    def __init__(self):
        with ui.row().classes('w-full items-start'):
            self.tabs = ui.tabs().classes('w-full')
            self.panels = ui.tab_panels().classes('w-full')
        self.containers: Dict[int, Tuple[ui.tab, ui.tab_panel]] = {}

    def render_panel(self, panel: ui.tab_panel, container: mx.Entity,
                     entity: mx.Entity):
        tt: fe.TokenTree = fe.TokenTree.create(container)
        vis = TokenTreeVisitor()
        for tok in tt.serialize(vis):
            sep = False
            related_entity: Optional[mx.Entity] = tok.related_entity
            on_click: Optional[Callable[..., Any]] = None
            classes = tok.category.name
            if isinstance(related_entity,
                          (ast.NamedDecl, fe.File, fe.DefineMacroDirective)):
                classes += ' cursor-pointer'
                on_click = on_click_token(related_entity, self)

            for data in tok.data.split('\n'):
                if sep:
                    ui.element('br')
                sep = True
                if not len(data):
                    continue
                with Code(data) as code:
                    code.classes(classes)
                    if related_entity is not None:
                        code.on('click', on_click)

    def open_entity(self, entity: mx.Entity) -> None:
        """Try to open an entity."""
        container = containing_entity(entity)
        if container is None:
            return

        container_id: int = container.id
        if container_id not in self.containers:
            with self.tabs:
                tab = ui.tab(entity_name(container, not isinstance(container, fe.File)).data)
            with self.panels:
                panel = ui.tab_panel(tab)

                # NOTE(pag): Tags inside of the panel seem to inherit/compute
                #            `display: block;`, which makes the `span` tags of
                #            the `Text` class render one per line. Use the
                #            Tailwind `contents` class to make all the tags
                #            inside of `panel` behave more like inline elements.
                with panel.classes('w-full contents'):
                    self.render_panel(panel, container, entity)

            self.containers[container_id] = (tab, panel)
        else:
            tab, panel = self.containers[container_id]

        self.tabs.set_value(tab)
        self.panels.set_value(panel)


def gui(index: mx.Index):
    """Render the GUI."""
    ui.dark_mode(True)
    ui.add_css('''
        .UNKNOWN {
            color: rgb(28,1,4) !important;
        }
        
        .IDENTIFIER {
            color: rgb(114,114,114) !important;
        }
        
        .MACRO_NAME {
            color: rgb(121,244,241) !important;
        }
        
        .MACRO_PARAMETER_NAME {
            color: rgb(114,111,58) !important;
        }
        
        .MACRO_DIRECTIVE_NAME {
            color: rgb(114,111,58) !important;
            font-weight: bold;
        }
        
        .KEYWORD {
            color: rgb(181,116,122) !important;
        }
        
        .OBJECTIVE_C_KEYWORD {
            color: rgb(181,116,122) !important;
        }
        
        .BUILTIN_TYPE_NAME {
            color: rgb(115,61,60) !important;
        }
        
        .PUNCTUATION {
            color: rgb(93,93,93) !important;
        }
        
        .LITERAL {
            color: rgb(226,211,148) !important;
        }
        
        .COMMENT {
            color: rgb(105,104,97) !important;
        }
        
        .LOCAL_VARIABLE {
            color: rgb(198,125,237) !important;
        }
        
        .GLOBAL_VARIABLE {
            color: rgb(198,163,73) !important;
            font-weight: bold;
            font-style: italic;
        }
        
        .PARAMETER_VARIABLE {
            color: rgb(172,122,180) !important;
        }
        
        .FUNCTION {
            color: rgb(126,125,186) !important;
            font-weight: bold;
        }
        
        .INSTANCE_METHOD {
            color: rgb(126,125,186) !important;
            font-weight: bold;
        }
        
        .INSTANCE_MEMBER {
            color: rgb(207,130,235) !important;
        }
        
        .CLASS_METHOD {
            color: rgb(170,129,52) !important;
            font-weight: bold;
            font-style: italic;
        }
        
        .CLASS_MEMBER {
            color: rgb(170,129,52) !important;
            font-style: italic;
        }
        
        .THIS {
            color: rgb(181,116,122) !important;
        }
        
        .CLASS {
            color: rgb(0,177,110) !important;
            font-weight: bold;
        }
        
        .STRUCT {
            color: rgb(0,177,110) !important;
            font-weight: bold;
        }
        
        .UNION {
            color: rgb(0,177,110) !important;
            font-weight: bold;
        }
        
        .CONCEPT {
            color: rgb(0,177,110) !important;
            font-weight: bold;
        }
        
        .INTERFACE {
            color: rgb(0,177,110) !important;
            font-weight: bold;
        }
        
        .ENUM {
            color: rgb(175,144,65) !important;
        }
        
        .ENUMERATOR {
            color: rgb(113,163,98) !important;
            font-style: italic;
        }
        
        .NAMESPACE {
            color: rgb(95,154,160) !important;
        }
        
        .TYPE_ALIAS {
            color: rgb(3,171,108) !important;
            font-weight: bold;
        }
        
        .TEMPLATE_PARAMETER_TYPE {
            color: rgb(198,117,29) !important;
        }
        
        .TEMPLATE_PARAMETER_VALUE {
            color: rgb(174,144,65) !important;
            font-style: italic;
        }
        
        .LABEL {
            color: rgb(149,149,149) !important;
        }
        
        .WHITESPACE {
            color: rgb(93,93,93) !important;
        }
        
        .FILE_NAME {
            color: rgb(23,185,152) !important;
        }
        
        .LINE_NUMBER {
            color: rgb(109,132,140) !important;
        }
        
        .COLUMN_NUMBER {
            color: rgb(109,132,140) !important;
        }
        
        .INFORMATION {
            color: rgb(105,104,97) !important;
        }
        
        .WARNING {
            color: rgb(105,104,97);
        }
        
        .ERROR {
            color: rgb(105,104,97) !important;
        }
    ''')
    with ui.splitter(value=20).classes('w-full') as splitter:
        with splitter.after:
            code_tabs_view = CodeTabs()
        with splitter.before:
            ui.tree(file_tree(index), on_select=on_click_file(index, code_tabs_view))
    ui.run()


def main():
    """Parse the command-line arguments and render the GUI."""
    parser = argparse.ArgumentParser(description="Multiplier Code Browser")
    parser.add_argument('--db', type=str,
                        required=True,
                        help="Path to mx-index-produced database")
    args = parser.parse_args()
    gui(mx.Index.in_memory_cache(mx.Index.from_database(args.db)))


if __name__ in ("__main__", "__mp_main__"):
    main()
