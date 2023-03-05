cmake_minimum_required(VERSION 2.8.9)

project (GenericKdTree)
# add_executable(hello helloworld.cpp)
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(testkd tests/TestMain.cpp)

target_link_libraries(testkd PRIVATE Catch2::Catch2WithMain)

