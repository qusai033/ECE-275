cmake_minimum_required(VERSION 3.0)
project(MathOps CXX)

add_subdirectory(src)
if (TESTING OR TESTING_ONLY)
  enable_testing()
  add_subdirectory(test)
endif()
