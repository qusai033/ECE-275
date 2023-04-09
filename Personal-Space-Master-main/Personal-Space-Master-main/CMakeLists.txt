cmake_minimum_required (VERSION 3.1)

project (PersonalSpace)


add_subdirectory(src)



if (TESTING OR TESTING_ONLY)
  enable_testing()
  add_compile_options(-Wall -Wextra -Wpedantic -Wfatal-errors)
  add_subdirectory(test)
endif()
