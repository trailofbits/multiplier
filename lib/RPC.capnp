@0xdce3fffe4506070a;

# Include the auto-generated AST schema.
using AST = import "AST.capnp";

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc");

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
  
  # Entities embedded in this code sequence.
  entities @1 :AST.EntityList;
  
  # List of top-level declarations in this code chunk.
  topLevelDeclarations @2 :List(UInt64);
}

interface Multiplier @0xb0c484f9ec88f1d6 {
  
  # Tell Multiplier to index a compile command.
  indexCompileCommands @0 (commands :List(CompileCommand)) -> (success :Bool);

  # Download a list of all files whose file ID is greater than or
  # equal to `minId`.
  downloadFileList @1 () -> (files: List(FileInfo));

  # Download a file by a file ID.
  downloadFile @2 (id :UInt64) -> (file: File);

  # Download a file that contains a given file token.
  downloadFileContainingEntity @3 (id :UInt64) -> (file: File);

  # Download indexed code that contains some entity.
  downloadFragmentContainingEntity @4 (id: UInt64) -> (code: Fragment);
}
