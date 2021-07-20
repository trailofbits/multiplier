add_executable(multiplier
  src/main.cpp
)

target_link_libraries(multiplier PRIVATE
  Qt5::Core
  Qt5::Widgets
)

find_package(pasta REQUIRED)
target_link_libraries(multiplier PRIVATE
  pasta::pasta
)

find_package(TobWidgets REQUIRED)
target_link_libraries(multiplier PRIVATE
  TobWidgets
)
