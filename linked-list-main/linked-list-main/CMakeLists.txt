cmake_minimum_required(VERSION 3.8)
project(Project_1_LinkedList CXX)


if (NOT TESTING_ONLY)
  add_subdirectory(src)
endif()

if (TESTING OR TESTING_ONLY)
  enable_testing()
  add_subdirectory(test)
endif()
