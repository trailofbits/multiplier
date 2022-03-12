@0xdce3fffe4506070a;

# Include the auto-generated AST schema.
using AST = import "AST.capnp";

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc");

enum TargetLanguage @0xc4c51b3d0ba6bec8 {
  c @0;
  cxx @1;
}

enum CompilerName @0xaaab4e1845c0695b {
  unknown @0;
  clang @1;
  appleClang @2;
  clangCl @3;
  cl @4;
  gnu @5;
}

enum IncludePathLocation @0xf7b55ef6dc92ce2b {

  # An absolue path.
  absolute @0;
  
  # Relative to the value of `-isysroot`.
  systemRootIncludeRelative @1;
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

struct FileTokenList @0x987f05f6a48636d5 {
  fileId @0 :UInt64;
  contents @1 :Data;
  tokenKinds @2 :List(UInt16);
}

struct IndexedCode @0xe5f27760091f9a3a {
  # The unique identifier for this top-level declaration.
  topLevelDeclListId @0 :UInt64;
  
  # The ID of the translation unit containing these declarations.
  translationUnitId @1 :UInt64;
  
  # Entities embedded in this code sequence.
  entities @2 :AST.EntityList;
}

interface Multiplier @0xb0c484f9ec88f1d6 {
  
  # Tell Multiplier to index a compile command.
  indexCompileCommands @0 (commands :List(CompileCommand)) -> (success :Bool);
}
