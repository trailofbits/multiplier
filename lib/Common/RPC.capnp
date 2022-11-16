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

# # Must be kept in sync wiht `mx::TokenSubstitutionKind`.
# enum TokenSubstitutionKind @0xa2f26f9d2081dec7 {
#   
#   otherDirective @0 $Cxx.name("other_directive");
#   defineDirective @1 $Cxx.name("define_directive");
#   undefDirective @2 $Cxx.name("undef_directive");
#   pragmaDirective @3 $Cxx.name("pragma_directive");
#   c99PragmaDirective @4 $Cxx.name("c99_pragma_directive");
#   microsoftPragmaDirective @5 $Cxx.name("microsoft_pragma_directive");
#   ifDirective @6 $Cxx.name("if_directive");
#   ifdefDirective @7 $Cxx.name("ifdef_directive");
#   ifndefDirective @8 $Cxx.name("ifndef_directive");
#   elifDirective @9 $Cxx.name("elif_directive");
#   elifdefDirective @10 $Cxx.name("elifdef_directive");
#   elifndefDirective @11 $Cxx.name("elifndef_directive");
#   elseDirective @12 $Cxx.name("else_directive");
#   endifDirective @13 $Cxx.name("endif_directive");
#   includeDirective @14 $Cxx.name("include_directive");
#   macroDirective @15 $Cxx.name("macro_directive");
#   macroParameterDirective @16 $Cxx.name("macro_parameter_directive");
#   vaOptDirective @17 $Cxx.name("va_opt_directive");
#   vaOptArgumentDirective @18 $Cxx.name("va_opt_argument_directive");
#   macroArgumentDirective @19 $Cxx.name("macro_argument_directive");
#   stringifyDirective @20 $Cxx.name("stringify_directive");
#   concatenateDirective @21 $Cxx.name("concatenate_directive");
#   substituteDirective @22 $Cxx.name("substitute_directive");
# }

struct TokenSubstitution @0xade5195a85fdc847 {
  beforeTokens @0 :List(UInt64);
  afterTokens @1 :List(UInt64);
#  kind @2 :TokenSubstitutionKind;
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
  attributes @6 :List(AST.Attr);
  others @7 :List(AST.Pseudo);
  
  # List of top-level declarations in this code chunk.
  topLevelDeclarations @8 :List(UInt64);
  
  # List of token substitutions in this fragment.
  tokenSubstitutions @9 :List(TokenSubstitution);
  
  # The actual parsed tokens, as a text buffer. Each token is separated by a
  # single space. There are no newlines, except those that might be inside of
  # character/string literals.
  parsedTokenData @10 :Text;
  
  # List of parsed token kinds in this fragment.
  tokenKinds @11 :List(UInt16);
  
  # List of offsets of the beginning of tokens. There is one extra element in
  # here than there are tokens, which represents the size of the data.
  tokenOffsets @12 :List(UInt32);
  
  # List of token IDs for file tokens corresponding with the parsed tokens.
  fileTokenIds @13 :List(UInt64);
  
  # List of token contexts. 
  tokenContexts @14 :List(TokenContext);
  
  # List of offsets of token contexts for each of the tokens.
  tokenContextOffsets @15 :List(UInt32);
  
  # List of tokens/substitution IDs in the top level.
  unparsedTokens @16 :List(UInt64);

  # Source IR in text format
  mlir @17 :Text;
}
