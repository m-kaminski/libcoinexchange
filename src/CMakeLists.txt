cmake_minimum_required(VERSION 3.14)
project(libbitcoinexchange)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )

FetchContent_MakeAvailable(googletest)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) 
                         # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

enable_testing()
include(GoogleTest)
include_directories(include/)
add_subdirectory(libsrc)
add_subdirectory(example)

add_subdirectory(unit_test)