# Copyright 2024, Peter Goodman. All rights reserved.

"""
This script implements a simple code browser using Python's `nicegui` package
as the GUI library.
"""
import abc
import argparse
import collections
from pathlib import PurePath
from typing import Dict, Set, DefaultDict, List, Tuple, Optional, Any, Callable, \
    Iterable

import multiplier as mx
import nicegui.elements.mixins.text_element

fe = mx.frontend
ast = mx.ast

from nicegui.events import ValueChangeEventArguments
from nicegui import ui, run

from GroupFunctions import group_functions_by_type

# import .GroupFunctions as gf

NEXT_ID: int = 0
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
TEXT_IN = fe.UserToken(
    kind=fe.TokenKind.UNKNOWN,
    category=fe.TokenCategory.UNKNOWN,
    data="in"
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
        tokens = fe.TokenRange(entity)
    elif isinstance(entity, fe.Macro):
        return file_line_col(next(entity.root.generate_use_tokens))
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
        return fe.TokenRange(name)

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

    elif isinstance(entity, ast.Stmt):
        if decl := entity.parent_declaration:
            if isinstance(decl, ast.NamedDecl):
                name = entity_name(decl, full_name)
                return make_token_range(
                    [
                        fe.UserToken(
                            kind=fe.TokenKind.UNKNOWN,
                            category=fe.TokenCategory.UNKNOWN,
                            data=entity.__class__.__name__,
                            related_entity=entity
                        ),
                    ],
                    [SPACE, TEXT_IN, SPACE],
                    [tok for tok in name]
                )


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


class Code(nicegui.elements.mixins.text_element.TextElement):
    def __init__(self, text: str, classes: str):
        super().__init__(tag='pre', text=text)
        self.classes(classes)


class CodeLink(nicegui.elements.mixins.text_element.TextElement, component='link.js'):
    def __init__(self, text: str, classes: str, line: int):
        super().__init__(tag='a', text=text)
        self._props['href'] = f'#line-{line}'
        self._props['target'] = '_self'
        self.classes(f'{classes} cursor-pointer')


def code(text: str, classes: str, related_entity: Optional[mx.Entity] = None):
    """Selectively create a `Code` or a `CodeLink`."""
    if related_entity is not None:
        line = 0
        if flc := file_line_col(related_entity):
            line = flc[1]
        return CodeLink(text, classes, line)
    else:
        return Code(text, classes)


ClickEvent = Callable[[mx.Entity], Any]
RightClickMaker = Callable[[mx.Entity], None]

class EventDispatcher:
    """Event dispatcher.

    TODO(pag): Generalize beyond clicks."""

    index: mx.Index
    click_handlers: Dict[str, ClickEvent]
    right_click_handlers: List[RightClickMaker]

    def __init__(self, index: mx.Index):
        self.index = index
        self.click_handlers = {}
        self.right_click_handlers = []

    def register_context_menu_item(self, callback: RightClickMaker):
        self.right_click_handlers.append(callback)

    def create_entity_context_menu(self, entity: mx.Entity):
        if not len(self.right_click_handlers):
            return

        with ui.context_menu():
            for item_cb in self.right_click_handlers:
                item_cb(entity)

    def register_entity_click_handler(self, id: str, handler: ClickEvent):
        """Register a handler for a click event. Handlers have names, and
        so can also be specifically invoked."""
        if id in self.click_handlers:
            old_handler = self.click_handlers[id]
            new_handler = handler
            handler = lambda e: (old_handler(e), new_handler(e))
        self.click_handlers[id] = handler

    def create_entity_click_event(self, entity: mx.Entity) -> Callable[..., Any]:
        """Create an event that is triggered when a entity is clicked."""
        def do_event(event):
            for handler in self.click_handlers.values():
                handler(entity)
        return do_event

    def create_entity_id_click_event(self, entity_id: int) -> Callable[..., Any]:
        """Create an event that is triggered when an entity is clicked,
        but where all we know about is the entity's ID. This allows us to
        avoid keeping a lot of references around in memory"""
        def do_event(event):
            self.emit_entity_id_click_event(entity_id)
        return do_event

    def create_specific_entity_id_click_event(self, id: str, entity_id: int) -> Callable[..., Any]:
        """Create an event that is triggered when an entity is clicked,
        but where all we know about is the entity's ID. This allows us to
        avoid keeping a lot of references around in memory"""
        def do_event(event):
            self.emit_specific_entity_id_click_event(id, entity_id)
        return do_event

    def emit_entity_id_click_event(self, entity_id: int):
        """Invoke all click handlers."""
        if entity := self.index.entity(entity_id):
            for handler in self.click_handlers.values():
                handler(entity)

    def emit_specific_entity_id_click_event(self, id: str, entity_id: int):
        """Invoke a specifically named click handler."""
        if id in self.click_handlers:
            handler = self.click_handlers[id]
            if entity := self.index.entity(entity_id):
                handler(entity)


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


class FileTree:
    """Renders out a file tree view."""

    ID_PREFIX: str = 'file_id_'
    events: EventDispatcher

    def __init__(self, index: mx.Index, events: EventDispatcher):
        self.events = events
        ui.link_target('file-tree')
        with ui.expansion('File Tree').classes('w-full') as file_tree:
            file_tree.open()
            ui.tree(self.build_tree(index), on_select=self.on_click_tree_item)

    def on_click_tree_item(self, event):
        """Generic event to handle clicking an entry in the file tree."""
        if not isinstance(event, ValueChangeEventArguments):
            return

        if not isinstance(event.value, str):
            return

        if not event.value.startswith(self.ID_PREFIX):
            return

        try:
            file_id = int(event.value[len(self.ID_PREFIX):])
            if file_id != 0:
                self.events.emit_entity_id_click_event(file_id)
        except:
            pass

    def build_tree(self, index: mx.Index) -> List[Dict]:
        """Generate a file tree, grouping together empty directories (sort of)
        so that it's easier to jump right into folders that contain actual
        files."""
        has_files: Set[PurePath] = set()
        file_paths = index.file_paths

        # Create leaf nodes, and identify which directories contain at least one
        # file.
        for file_path, file_id in file_paths.items():
            has_files.add(file_path.parent)

        # Group the paths into folders that have at least one file in them. This
        # is so that we don't have to see crazy deep folder trees all the time.
        sub_lists: DefaultDict[
            PurePath, List[Tuple[PurePath, int]]] = collections.defaultdict(
            list)
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
                last['id'] = f"{self.ID_PREFIX}{file_id}"
                seen.add(file_id)

        return roots


class ExpandableTree:
    index: mx.Index
    events: EventDispatcher
    id_prefix: str
    title: ui.expansion

    def __init__(self, index: mx.Index, events: EventDispatcher):
        self.index = index
        self.events = events
        self.id_prefix = f'_{next_id()}_'
        self._opened = False
        ui.link_target(self.link_target())
        with ui.expansion(self.name()) as title:
            title.classes('w-full')
            self.title = title
            self.title.set_visibility(False)
            self.update()

    @ui.refreshable
    def update(self, *args):
        if not self._opened:
            ui.skeleton().classes('w-full')
            return

        tree = ui.tree(self.generate_tree(*args),
                       on_select=self.on_click_tree_item)
        tree.add_slot('default-body', '''
                    <span :props="props">{{ props.node.description }}</span>
                ''')

    def on_click_tree_item(self, event):
        if not isinstance(event, ValueChangeEventArguments):
            return

        if not isinstance(event.value, str):
            return

        if not event.value.startswith(self.id_prefix):
            return

        try:
            entity_id = int(event.value.split('_')[-1])
            if entity_id != 0:
                self.events.emit_entity_id_click_event(entity_id)
        except:
            pass

    def open(self, *args):
        self.title.set_visibility(True)
        ui.navigate.to(f'#{self.link_target()}')
        self.title.open()
        self._opened = True
        self.update.refresh(*args)

    def entry_id(self, entity: mx.Entity | int) -> str:
        entity_id = int(isinstance(entity, mx.Entity) and entity.id or entity)
        return f'{self.id_prefix}{next_id()}_{entity_id}'

    @abc.abstractmethod
    def link_target(self) -> str:
        ...

    @abc.abstractmethod
    def name(self) -> str:
        ...

    @abc.abstractmethod
    def generate_tree(self, *args) -> List[Dict]:
        ...


class ReferenceTree(ExpandableTree):
    """Show references related to a given entity."""

    def __init__(self, index: mx.Index, events: EventDispatcher, kind: str,
                 generator: Callable[[mx.Entity], Iterable[mx.Reference]]):
        self.kind = kind
        self.generator = generator
        super().__init__(index, events)
        self.events.register_context_menu_item(self.on_right_click_entity)

    def link_target(self) -> str:
        return f'references-{self.kind}'

    def name(self) -> str:
        return f'References {self.kind.capitalize()}'

    def generate_tree(self, entity: mx.Entity) -> List[Dict]:
        self.title.set_text(
            f'References {self.kind} {entity_name(entity, False).data}')

        kinds: Dict[str, Dict] = {}
        roots = []
        for ref in self.generator(entity):
            kind_name = ref.kind.data
            if kind_name not in kinds:
                root = {
                    'label': kind_name,
                    'id': f'root_{next_id()}',
                    'children': [],
                }
                kinds[kind_name] = root
                roots.append(root)
            else:
                root = kinds[kind_name]

            entity_id = ref.referenced_entity_id
            label = f'Entity {entity_id}'
            token_data: str = ""
            ref_entity = ref.as_variant
            name: str = entity_name(ref_entity).data
            if not isinstance(ref_entity, ast.NamedDecl):
                if hasattr(ref_entity, 'tokens'):
                    token_data = (self.kind == 'to' and ref.context or ref_entity).tokens.data
                elif hasattr(ref_entity, 'use_tokens'):
                    token_data = ref_entity.use_tokens.data

            node = {
                'label': len(token_data) and token_data or (
                             len(name) and name or label
                         ),
                'id': self.entry_id(ref_entity.id),
            }

            if loc := file_line_col_token_list(ref_entity, False):
                node['description'] = fe.TokenRange.create(loc).data

            root['children'].append(node)

        return roots

    def on_right_click_entity(self, entity: mx.Entity):
        ui.menu_item(
            f'Show references {self.kind} {entity_name(entity, False).data}',
            self.make_open_references_to(entity.id)
        )

    def make_open_references_to(self, entity_id: int):
        def do_event(event):
            if entity := self.index.entity(entity_id):
                self.open(entity)
        return do_event


class ReferenceToTree(ReferenceTree):
    def __init__(self, index: mx.Index, events: EventDispatcher):
        super().__init__(index, events, 'to', mx.Reference.to)


class ReferenceFromTree(ReferenceTree):
    def __init__(self, index: mx.Index, events: EventDispatcher):
        super().__init__(index, events, 'from', mx.Reference.FROM)


class SameTypedFunctions(ExpandableTree):
    index_path: str
    grouped_functions: Optional[Dict[int, List[int]]]

    def __init__(self, index: mx.Index, events: EventDispatcher):
        super().__init__(index, events)
        self.grouped_functions = None
        self.events.register_context_menu_item(self.on_right_click_entity)

    def link_target(self) -> str:
        return 'same-typed-functions'

    def name(self) -> str:
        return 'Same Typed Functions'

    def generate_tree(self, entity: mx.Entity) -> List[Dict]:
        roots: List[Dict] = []
        if not isinstance(entity, ast.FunctionDecl):
            return roots

        if self.grouped_functions is None:
            funcs = group_functions_by_type(self.index)
            self.grouped_functions = {}
            for func_ids in funcs:
                if len(func_ids) > 1:
                    for func_id in func_ids:
                        self.grouped_functions[func_id] = func_ids

        func_name = entity_name(entity, False).data
        func_id = entity.canonical_declaration.id
        if func_id not in self.grouped_functions:
            return roots

        roots.append({
            'id': next_id(),
            'label': func_name,
            'children': []
        })

        for similar_func_id in self.grouped_functions[func_id]:
            if similar_func_id == func_id:
                continue

            similar_func = self.index.declaration(similar_func_id)
            if not isinstance(similar_func, ast.FunctionDecl):
                continue

            node: Dict = {
                'id': self.entry_id(similar_func_id),
                'label': entity_name(similar_func, True).data
            }

            if loc := file_line_col_token_list(similar_func, False):
                node['description'] = fe.TokenRange.create(loc).data

            roots[0]['children'].append(node)

        return roots

    def on_right_click_entity(self, entity: mx.Entity):
        if isinstance(entity, ast.FunctionDecl):
            ui.menu_item(
                f'Show same-typed functions to {entity_name(entity, False).data}',
                self.make_open_references_to(entity.id)
            )

    def make_open_references_to(self, entity_id: int):
        def do_event(event):
            if entity := self.index.entity(entity_id):
                self.open(entity)
        return do_event


class CodeTabs:
    """Render out tabs of code. This tries to preference showing files, and
    failing that, shows fragments (all by way of `containing_entity`)."""

    events: EventDispatcher

    def __init__(self, events: EventDispatcher):
        self.events = events
        self.containers: Dict[int, Tuple[ui.tab, ui.tab_panel]] = {}
        self.initialize(False)
        events.register_entity_click_handler('show-code-of', self.open_entity)

    @ui.refreshable
    def initialize(self, init: False):
        if not init:
            ui.skeleton().classes('w-full h-screen')
        else:
            self.tabs = ui.tabs().classes('w-full')
            self.panels = ui.tab_panels(self.tabs).classes('w-full h-dvh')

    def make_open_references_to(self, entity_id: int):
        def do_event(event):
            ui.navigate.to('#references-to')
            self.events.emit_specific_entity_id_click_event(
                'show-references-to',
                entity_id
            )
        return do_event

    def make_open_references_from(self, entity_id: int):
        def do_event(event):
            ui.navigate.to('#references-from')
            self.events.emit_specific_entity_id_click_event(
                'show-references-from',
                entity_id
            )
        return do_event

    def render_token(self, tok: fe.Token, new_line: Callable[[], None]):
        sep: bool = False
        related_entity: Optional[mx.Entity] = tok.related_entity
        on_click: Optional[Callable[..., Any]] = None
        classes: str = tok.category.name

        # If the related entity is a declaration, then map the click to
        # the canonical entity (usually the definition).
        if isinstance(related_entity, ast.NamedDecl):
            related_entity = related_entity.canonical_declaration

        # The other named clickable things will be files and macros.
        elif not isinstance(related_entity, (fe.File, fe.DefineMacroDirective)):
            related_entity = None

        if related_entity is not None:
            on_click = self.events.create_entity_id_click_event(related_entity.id)

        for data in tok.data.split('\n'):
            if sep:
                ui.element('br')
                new_line()
            sep = True
            if not len(data):
                continue
            with code(data, classes, related_entity) as c:
                if related_entity is None:
                    continue
                c.on('click', on_click)
                self.events.create_entity_context_menu(related_entity)

    def render_panel(self, container: mx.Entity, entity: mx.Entity):
        tt: fe.TokenTree = fe.TokenTree.create(container)
        vis = TokenTreeVisitor()

        def new_line(line: List[int] = [1]):
            ui.link_target(f'line-{line[0]}')
            Code(f'{line[0]:>6}  ', 'LINE_NUMBER')
            line[0] += 1

        new_line()
        for tok in tt.serialize(vis):
            self.render_token(tok, new_line)

    def open_entity(self, entity: mx.Entity) -> None:
        """Try to open an entity."""
        container = containing_entity(entity)
        if container is None:
            return

        if not len(self.containers):
            self.initialize.refresh(True)

        container_id: int = container.id
        tab_id = f'tab-{container_id}'

        if container_id not in self.containers:
            self.panels.set_value(tab_id)

            with self.tabs:
                label = entity_name(container, not isinstance(container, fe.File)).data
                tab = ui.tab(tab_id, label=label)

            with self.panels:
                panel = ui.tab_panel(tab_id)

                # NOTE(pag): Tags inside of the panel seem to inherit/compute
                #            `display: block;`, which makes the `span` tags of
                #            the `Text` class render one per line. Use the
                #            Tailwind `contents` class to make all the tags
                #            inside of `panel` behave more like inline elements.
                with panel.classes('w-full contents'):
                    self.render_panel(container, entity)

            self.containers[container_id] = (tab, panel)
        else:
            tab, panel = self.containers[container_id]

        if not isinstance(entity, fe.File):
            if flc := file_line_col(entity):
                ui.navigate.to(f'#line-{flc[1]}')
        elif isinstance(entity, fe.File):
            ui.navigate.to('#line-1')

        self.panels.set_value(tab_id)


def gui(index_path: str):
    """Render the GUI."""
    index = mx.Index.in_memory_cache(mx.Index.from_database(index_path))
    ui.dark_mode(True)
    ui.page_title('Multiplier Web Browser')
    ui.add_css('''
        .UNKNOWN {
            display: inline;
            color: rgb(28,1,4) !important;
            font-family: monospace, monospace;
        }
        
        .IDENTIFIER {
            display: inline;
            color: rgb(114,114,114) !important;
            font-family: monospace, monospace;
        }
        
        .MACRO_NAME {
            display: inline;
            color: rgb(121,244,241) !important;
            font-family: monospace, monospace;
        }
        
        .MACRO_PARAMETER_NAME {
            display: inline;
            color: rgb(114,111,58) !important;
            font-family: monospace, monospace;
        }
        
        .MACRO_DIRECTIVE_NAME {
            display: inline;
            color: rgb(114,111,58) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .KEYWORD {
            display: inline;
            color: rgb(181,116,122) !important;
            font-family: monospace, monospace;
        }
        
        .OBJECTIVE_C_KEYWORD {
            display: inline;
            color: rgb(181,116,122) !important;
            font-family: monospace, monospace;
        }
        
        .BUILTIN_TYPE_NAME {
            display: inline;
            color: rgb(115,61,60) !important;
            font-family: monospace, monospace;
        }
        
        .PUNCTUATION {
            display: inline;
            color: rgb(93,93,93) !important;
            font-family: monospace, monospace;
        }
        
        .LITERAL {
            display: inline;
            color: rgb(226,211,148) !important;
            font-family: monospace, monospace;
        }
        
        .COMMENT {
            display: inline;
            color: rgb(105,104,97) !important;
            font-family: monospace, monospace;
        }
        
        .LOCAL_VARIABLE {
            display: inline;
            color: rgb(198,125,237) !important;
            font-family: monospace, monospace;
        }
        
        .GLOBAL_VARIABLE {
            display: inline;
            color: rgb(198,163,73) !important;
            font-weight: bold;
            font-style: italic;
            font-family: monospace, monospace;
        }
        
        .PARAMETER_VARIABLE {
            display: inline;
            color: rgb(172,122,180) !important;
            font-family: monospace, monospace;
        }
        
        .FUNCTION {
            display: inline;
            color: rgb(126,125,186) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .INSTANCE_METHOD {
            display: inline;
            color: rgb(126,125,186) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .INSTANCE_MEMBER {
            display: inline;
            color: rgb(207,130,235) !important;
            font-family: monospace, monospace;
        }
        
        .CLASS_METHOD {
            display: inline;
            color: rgb(170,129,52) !important;
            font-weight: bold;
            font-style: italic;
            font-family: monospace, monospace;
        }
        
        .CLASS_MEMBER {
            display: inline;
            color: rgb(170,129,52) !important;
            font-style: italic;
            font-family: monospace, monospace;
        }
        
        .THIS {
            display: inline;
            color: rgb(181,116,122) !important;
            font-family: monospace, monospace;
        }
        
        .CLASS {
            display: inline;
            color: rgb(0,177,110) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .STRUCT {
            display: inline;
            color: rgb(0,177,110) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .UNION {
            display: inline;
            color: rgb(0,177,110) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .CONCEPT {
            display: inline;
            color: rgb(0,177,110) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .INTERFACE {
            display: inline;
            color: rgb(0,177,110) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .ENUM {
            display: inline;
            color: rgb(175,144,65) !important;
            font-family: monospace, monospace;
        }
        
        .ENUMERATOR {
            display: inline;
            color: rgb(113,163,98) !important;
            font-style: italic;
            font-family: monospace, monospace;
        }
        
        .NAMESPACE {
            display: inline;
            color: rgb(95,154,160) !important;
            font-family: monospace, monospace;
        }
        
        .TYPE_ALIAS {
            display: inline;
            color: rgb(3,171,108) !important;
            font-weight: bold;
            font-family: monospace, monospace;
        }
        
        .TEMPLATE_PARAMETER_TYPE {
            display: inline;
            color: rgb(198,117,29) !important;
            font-family: monospace, monospace;
        }
        
        .TEMPLATE_PARAMETER_VALUE {
            display: inline;
            color: rgb(174,144,65) !important;
            font-style: italic;
            font-family: monospace, monospace;
        }
        
        .LABEL {
            display: inline;
            color: rgb(149,149,149) !important;
            font-family: monospace, monospace;
        }
        
        .WHITESPACE {
            display: inline;
            color: rgb(93,93,93) !important;
            font-family: monospace, monospace;
        }
        
        .FILE_NAME {
            display: inline;
            color: rgb(23,185,152) !important;
            font-family: monospace, monospace;
        }
        
        .LINE_NUMBER {
            display: inline;
            color: rgb(109,132,140) !important;
            font-family: monospace, monospace;
        }
        
        .COLUMN_NUMBER {
            display: inline;
            color: rgb(109,132,140) !important;
            font-family: monospace, monospace;
        }
        
        .INFORMATION {
            display: inline;
            color: rgb(105,104,97) !important;
            font-family: monospace, monospace;
        }
        
        .WARNING {
            display: inline;
            color: rgb(105,104,97);
            font-family: monospace, monospace;
        }
        
        .ERROR {
            display: inline;
            color: rgb(105,104,97) !important;
            font-family: monospace, monospace;
        }
    ''')
    events = EventDispatcher(index)
    with ui.splitter(value=20).classes('w-full h-dvh') as left_right:
        with left_right.before:
            FileTree(index, events)
            ReferenceToTree(index, events)
            ReferenceFromTree(index, events)
            SameTypedFunctions(index, events)
        with left_right.after:
            CodeTabs(events)
    ui.run()


def main():
    """Parse the command-line arguments and render the GUI."""
    parser = argparse.ArgumentParser(description="Multiplier Code Browser")
    parser.add_argument('--db', type=str,
                        required=True,
                        help="Path to mx-index-produced database")
    args = parser.parse_args()
    gui(args.db)
    #run.cpu_bound(group_functions_by_type)

if __name__ in ("__main__", "__mp_main__"):
    main()
