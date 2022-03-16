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
  tokens @2 :List(AST.FileToken);
}

struct IndexedCode @0xe5f27760091f9a3a {
  # The unique identifier for this top-level declaration.
  codeId @0 :UInt64;
  
  # # The ID of the translation unit containing these declarations.
  # translationUnitId @1 :UInt64;
  
  # Entities embedded in this code sequence.
  entities @1 :AST.EntityList;
}

interface Multiplier @0xb0c484f9ec88f1d6 {
  
  # Tell Multiplier to index a compile command.
  indexCompileCommands @0 (commands :List(CompileCommand)) -> (success :Bool);
}
