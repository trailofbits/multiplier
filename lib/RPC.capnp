@0xdce3fffe4506070a;

# Include the auto-generated AST schema.
using AST = import "AST.capnp";

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc");

enum PathKind @0xeee7ae4dc1753912 {
  unix @0 $Cxx.name("unix");
  windows @1 $Cxx.name("windows");
}

enum FileType @0xe5e5e79bb59eb81d {
  none @0 $Cxx.name("none");
  notFound @1 $Cxx.name("not_found");
  regular @2 $Cxx.name("regular");
  directory @3 $Cxx.name("directory");
  symbolicLink @4 $Cxx.name("symbolic_link");
  block @5 $Cxx.name("block");
  character @6 $Cxx.name("character");
  firstInFirstOut @7 $Cxx.name("first_in_first_out");
  socket @8 $Cxx.name("socket");
  knknown @9 $Cxx.name("knknown");
}

enum CompilerName @0xa57e0439dbff0947 {
  unknown @0 $Cxx.name("unknown");
  clang @1 $Cxx.name("clang");
  appleClang @2 $Cxx.name("apple_clang");
  clangCl @3 $Cxx.name("clang_cl");
  cl @4 $Cxx.name("cl");
  gnu @5 $Cxx.name("gnu");
}

enum IncludePathLocation @0xde297748edec6a08 {
  absolute @0 $Cxx.name("absolute");
  sysrootRelative @1 $Cxx.name("sysroot_relative");
}

enum TargetLanguage @0xeabe5088e5bc86fc {
  c @0 $Cxx.name("c");
  cxx @1 $Cxx.name("cxx");
}

enum TokenSubstitutionKind @0xa2f26f9d2081dec7 {
  macroExpansion @0 $Cxx.name("macro_expansion");
  functionLikeMacroExpansion @1 $Cxx.name("function_like_macro_expansion");
  includeExpansion @2 $Cxx.name("include_expansion");
}

struct TokenSubstitution @0xade5195a85fdc847 {
  beforeTokens @0 :List(UInt64);
  afterTokens @1 :List(UInt64);
  kind @2 :TokenSubstitutionKind;
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
  language @11 :TargetLanguage;
  compiler @12 :CompilerName;
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
  
  # Index of the aliased token context (shifted left by 1). Low bit is 1 if this
  # value is present. The `entityId` at the indexed context should match.
  aliasIndex @1 :UInt32;
  
  # Entity ID. This should generally be in the same fragment, but sometimes
  # isn't.
  entityId @2 :UInt64;
}

struct File @0x987f05f6a48636d5 {
  # Unique ID of this file. This corresponds to an `mx::FileId`.
  id @0 :UInt64;
  
  # Hash of `data`.
  hash @1 :Text;
  
  # The data of the file.
  data @2 :Text;
  
  # Tells us about the tokens inside of `data`. There is one extra element in
  # `tokenOffsets`.
  tokenKinds @3 :List(UInt16);
  tokenOffsets @4 :List(UInt32);
    
  # Byte offsets of the end of line characters. We use this to map matches in
  # files to matches in fragments, with a persistent set containing <file_id,
  # line_num, fragment_id> triples.
  eolOffsets @5 :List(UpperBound);
}

struct FileInfo @0xfd1022cb187f18f8 {
  id @0 :UInt64;
  path @1 :Text;
}

struct Fragment @0xe5f27760091f9a3a {
  # The unique identifier for this fragment (set of lexically overlapping
  # top-level declarations).
  id @0 :UInt64;
  
  # Inclusive range of file token IDs for the unparsed data of this fragment.
  firstFileTokenId @1 :UInt64;
  lastFileTokenId @2 :UInt64;
  
  # Entities embedded in this code sequence.
  declarations @3 :List(AST.Decl);
  statements @4 :List(AST.Stmt);
  types @5 :List(AST.Type);
  others @6 :List(AST.Pseudo);
  
  # List of top-level declarations in this code chunk.
  topLevelDeclarations @7 :List(UInt64);
  
  # List of token substitutions in this fragment.
  tokenSubstitutions @8 :List(TokenSubstitution);
  
  # The actual parsed tokens, as a text buffer. Each token is separated by a
  # single space. There are no newlines, except those that might be inside of
  # character/string literals.
  parsedTokenData @9 :Text;
  
  # List of parsed token kinds in this fragment.
  tokenKinds @10 :List(UInt16);
  
  # List of offsets of the beginning of tokens. There is one extra element in
  # here than there are tokens, which represents the size of the data.
  tokenOffsets @11 :List(UInt32);
  
  # List of token IDs for file tokens corresponding with the parsed tokens.
  fileTokenIds @12 :List(UInt64);
  
  # List of token contexts. 
  tokenContexts @13 :List(TokenContext);
  
  # List of offsets of token contexts for each of the tokens.
  tokenContextOffsets @14 :List(UInt32);
  
  # List of tokens/substitution IDs in the top level.
  unparsedTokens @15 :List(UInt64);

  # Source IR in text format
  mlir @16 :Text;
}

struct RegexMatch @0xc119a143d978fd1e {
  fileId @0 :UInt64;
  fragmentId @1 :UInt64;
}

struct SymbolMatch @0xb119a123d978fd1e {
  # Entity id of the symbol
  entityId @0 :UInt64;
  # Symbol name
  symbol   @1 :Text;
  # Symbol kind
  kind     @2 :Text;
}

interface Multiplier @0xb0c484f9ec88f1d6 {

  hello @0 () -> (versionNumber: UInt32);
  
  # Tell Multiplier to index a compile command.
  indexCompileCommands @1 (commands :List(CompileCommand)) -> (success :Bool);

  # Download a list of all files whose file ID is greater than or
  # equal to `minId`.
  downloadFileList @2 () -> (versionNumber :UInt32, files: List(FileInfo));

  # Download a file by a file by an `mx::FileId`. Returns the file, and a list
  # of the fragment IDs associated with this file.
  downloadFile @3 (id :UInt64) -> (versionNumber :UInt32, file :Data);

  # Download a code fragment by an `mx::FragmentId`.
  downloadFragment @4 (id: UInt64) -> (versionNumber :UInt32, fragment :Data);

  # Search code fragments that match with the query.
  weggliQueryFragments @5 (query :Text, isCpp :Bool) ->  (versionNumber :UInt32, fragmentIds :List(UInt64));
 
  # Query for a regular expression match, and return the list of fragment ids
  # overlapping with the matches.
  regexQueryFragments @6 (regex :Text) -> (versionNumber :UInt32, fragmentIds :List(UInt64));
  
  # Expand a list of redeclarations to try to cover all redeclarations across
  # all translation units. The first redeclaration in the list should be the
  # definition.
  findRedeclarations @7 (declId :UInt64) -> (versionNumber :UInt32, redeclarationIds :List(UInt64));
  
  # Given a list of declaration IDs that all logically represent the same
  # declaration, return a list of fragment IDs that contain some kind of use
  # of the declarations.
  findUses @8 (redeclarationIds :List(UInt64)) -> (versionNumber :UInt32, fragmentIds :List(UInt64));
  
  # Given a list of declaration IDs that all logically represent the same
  # declaration, return a list of statement entity ids that reference any of
  # the declarations. This focuses on `DeclRefExpr` and `MemberExpr` references.
  findReferences @9 (redeclarationIds :List(UInt64)) -> (versionNumber :UInt32, fragmentIds :List(UInt64));

  # Find the list of fragment IDs associated with a specific file.
  findFileFragments @10 (fileId :UInt64) -> (versionNumber :UInt32, fragmentIds :List(UInt64));

  # Find the entity ids from the given symbol name
  findSymbols @11 (query :Text) -> (symbols :List(SymbolMatch));
}
