add_subdirectory("src")

add_library(thirdparty_pasta INTERFACE)
target_link_libraries(thirdparty_pasta INTERFACE
  pasta_compiler
  pasta_util
)

add_library(pasta::pasta ALIAS thirdparty_pasta)
