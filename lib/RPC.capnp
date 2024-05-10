@0xdce3fffe4506070a;

# Include the auto-generated AST schema.
using AST = import "AST.capnp";

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc");

enum IncludePathLocation @0xde297748edec6a08 {
  absolute @0 $Cxx.name("absolute");
  sysrootRelative @1 $Cxx.name("sysroot_relative");
}

struct IncludePath @0x8b7f7dfed6973665 {
  directory @0 :Text;
  location @1 :IncludePathLocation;
}

struct CompileCommand @0xab30180088262c95 {
  sourcePath @0 :Text;
  compilerPath @1 :Text;
  workingDirectory @2 :Text;
  systemRootDirectory @3 :Text;
  systemRootIncludeDirectory @4 :Text;
  resourceDirectory @5 :Text;
  installationDirectory @6 :Text;
  systemIncludePaths @7 :List(IncludePath);
  userIncludePaths @8 :List(IncludePath);
  frameworkPaths @9 :List(IncludePath);
  arguments @10 :List(Text);
  targetTriple @11 :Text;
  auxTargetTriple @12 :Text;
}

# Used to tell us the upper bound of something, e.g. the byte offsets of the
# ends of lines, where `val` is the line number, and `offset` is the offset of
# the `\n` character.
struct UpperBound @0xdf7bccc629d6dcf9 {
  val @0 :UInt32;
  offset @1 :UInt32;
}

struct TokenContext @0xb9ff75e040124cb3 {
  
  # Index of the parent token context (shifted left by 1). Low bit is 1 if this
  # value is present.
  parentIndex @0 :UInt32;
  
  # Entity ID. This should generally be in the same fragment, but sometimes
  # isn't.
  entityId @1 :UInt64;
}

struct File @0x987f05f6a48636d5 {
  # The data of the file.
  data @0 :Text;
  
  # Tells us about the tokens inside of `data`. There is one extra element in
  # `tokenOffsets`.
  tokenKinds @1 :List(UInt16);
  tokenOffsets @2 :List(UInt32);
    
  # Byte offsets of the end of line characters. We use this to map matches in
  # files to matches in fragments, with a persistent set containing <file_id,
  # line_num, fragment_id> triples.
  eolOffsets @3 :List(UpperBound);
}

struct FileInfo @0xfd1022cb187f18f8 {
  id @0 :UInt64;
  path @1 :Text;
}

struct NestedFragment @0xd023961e5f656717 {
  # ID of this sub fragment.
  id @0 :UInt64;
  
  # Number of parsed tokens in this sub fragment. This includes parsed tokens
  # in transitively nested sub fragments.
  numParsedTokens @1 : UInt32;

  # Offset into the parsed tokens of the parent fragment where this nested
  # fragment should go.
  offsetInParsedTokenList @2 : UInt32;
}

struct Fragment @0xe5f27760091f9a3a {
  # ID of this fragment's parent, or an invalid ID.
  parentFragmentId @0 :UInt64;

  # List of C++ template fragments lexically nested inside of this fragment.
  # These are referenced by the preprocessed code.
  nestedFragments @1 :List(NestedFragment);
  
  # Inclusive range of file token IDs for the unparsed data of this fragment.
  firstFileTokenId @2 :UInt64;
  lastFileTokenId @3 :UInt64;
  
  # List of top-level declarations in this fragment.
  topLevelDeclarations @4 :List(UInt64);
  
  # List of top-level macros or tokens in this code.
  topLevelMacros @5 :List(UInt64);
  
  # This is to let us get from a "final" macro token back to a parsed token.
  # There is one for every non-parsed token token.
  macroTokenIndexToParsedTokenOffset @6 :List(UInt32);
  
  # Inverted map of macro tokens -> macro id of containing macro. The macro
  # containing the `i`th token is `macroTokenIndexToMacroId[i]`.
  macroTokenIndexToMacroId @7 :List(UInt64);
  
  # List of token contexts. There is one token context per parsed token.
  # Non-parsed tokens don't have token contexts. Whitespace doesn't have
  # context.
  parsedTokenContexts @8 :List(TokenContext);
  
  # List of offsets of token contexts for each of the tokens.
  #
  # Indexed by `ParsedTokenId::offset`.
  parsedTokenContextOffsets @9 :List(UInt32);
  
  # The actual parsed tokens, as a text buffer. Each token is separated by a
  # single space. There are no newlines, except those that might be inside of
  # character/string literals.
  #
  # The data of the macro tokens. For the following substition tree:
  #
  #                   A * C D
  #                    / \
  #                   B   E
  #
  # We lay out the data as follows:
  #
  #                   A E C D B
  #
  # The parsed tokens correspond to stuff in `A E C D`, and `B` comes after.
  tokenData @10 :Text;
  
  # Offsets of the beginning of tokens into `tokenData`. There is one extra
  # element in here than there are tokens, which represents the size of the data.
  tokenOffsets @11 :List(UInt32);
  
  # List of macro token kinds in this fragment.
  tokenKinds @12 :List(UInt16);
  
  # Every macro token is associated with an ID. The id is one of:
  #
  #   - FileTokenId:         This macro token is derived from a file token.
  #   - MacroTokenId:        This macro token is a copy of another macro token.
  #   - MacroId: This macro token is derived in some way from its
  #                          parent substitution. E.g. stringize, concat, etc.
  derivedTokenIds @13 :List(UInt64);
  
  # The single best related entity ID to the corresponding token. This helps
  # with improving the speed of syntax highlighting.
  relatedEntityId @14 :List(UInt64);
  
  # The translation unit from which this fragment was derived. We can find
  # the compile command for a fragment there, if we need to reproduce the
  # TU, and we can find its MLIR representation there too.
  compilationId @15 :UInt64;

  # The entities from this fragment. These are lists-of-lists. The top-level
  # lists are indexed by entity kind. The nested list is all entities in this
  # fragment of that kind.
  decls @16 :List(List(AST.Decl));
  stmts @17 :List(List(AST.Stmt));
  attrs @18 :List(List(AST.Attr));
  macros @19 :List(List(AST.Macro));
  templateArguments @20 :List(AST.TemplateArgument);
  templateParameterLists @21 :List(AST.TemplateParameterList);
  cXXBaseSpecifiers @22 :List(AST.CXXBaseSpecifier);
  designators @23 :List(AST.Designator);
  cXXCtorInitializers @24 :List(AST.CXXCtorInitializer);

  # These are lists. When things in the AST need a list of stuff, they store
  # them in here.
  textLists @25 :List(Text);
  uInt64Lists @26 :List(UInt64);
}

struct Compilation @0xc8b5fa5dd0739e82 {
  
  # List of fragments associated with this compilation.
  fragmentIds @0 :List(UInt64);
  
  # List of files associated with this compilation.
  fileIds @1 :List(UInt64);

  # The ID of the main source file associated with this compilation.
  mainFileId @2 :UInt64;
  
  # The compile command for this compilation unit.
  command @3 :CompileCommand;
  
  # Source IR in text format
  mlir @4 :Text;
} 

struct Type @0xd2d91de1b5fe2e03 {
  
  # List of token contexts.
  typeTokenContexts @0 :List(TokenContext);
  
  # List of offsets of token contexts for each of the tokens.
  #
  # Indexed by `TypeTokenId::offset`.
  typeTokenContextOffsets @1 :List(UInt32);
  
  # The type token data in text buffer format.
  tokenData @2 :Text;
  
  # Offsets of the beginning of tokens into `tokenData`. There is one extra
  # element in here than there are tokens, which represents the size of the data.
  tokenOffsets @3 :List(UInt32);
  
  # List of token kinds in this type fragment.
  tokenKinds @4 :List(UInt16);
  
  # The single best related entity ID to the corresponding token. This helps
  # with improving the speed of syntax highlighting.
  relatedEntityId @5 :List(UInt64);

  type @6 :AST.Type;
}