@0xdce3fffe4506070a;

# Include the auto-generated AST schema.
using AST = import "AST.capnp";

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc");

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
  location @1 :AST.IncludePathLocation;
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
  language @11 :AST.TargetLanguage;
  compiler @12 :AST.CompilerName;
}

struct File @0x987f05f6a48636d5 {
  id @0 :UInt64;
  hash @1 :Text;
  tokens @2 :List(AST.Token);
}

struct FileInfo @0xfd1022cb187f18f8 {
  id @0 :UInt64;
  path @1 :Text;
}

struct Fragment @0xe5f27760091f9a3a {
  # The unique identifier for this top-level declaration.
  codeId @0 :UInt64;
  
  # ID of the first file token associated with this framgnet. We 'hang'
  # the fragment on this ID from the perspective of rendering fragments
  # in a GUI.
  fileTokenId @1 :UInt64;
  
  firstLine @2 :UInt32;
  lastLine @3 :UInt32;
  
  # Entities embedded in this code sequence.
  entities @4 :AST.EntityList;
  
  # List of top-level declarations in this code chunk.
  topLevelDeclarations @5 :List(UInt64);
  
  # List of token substitutions in this fragment.
  tokenSubstitutions @6 :List(TokenSubstitution);
  
  # List of tokens/substitution IDs in the top level.
  tokens @7 :List(UInt64);
}

interface Multiplier @0xb0c484f9ec88f1d6 {
  
  # Tell Multiplier to index a compile command.
  indexCompileCommands @0 (commands :List(CompileCommand)) -> (success :Bool);

  # Download a list of all files whose file ID is greater than or
  # equal to `minId`.
  downloadFileList @1 () -> (files: List(FileInfo));

  # Download a file by a file by an `mx::FileId`. Returns the file, and a list
  # of the fragment IDs associated with this file.
  downloadFile @2 (id :UInt64) -> (file :File, fragments :List(UInt64));

  # Download a code fragment by an `mx::FragmentId`.
  downloadFragment @3 (id: UInt64) -> (fragment :Fragment);
}
