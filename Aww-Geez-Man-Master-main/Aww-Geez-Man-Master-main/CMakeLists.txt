cmake_minimum_required(VERSION 3.0)

# ECE 275 Homework: Aww Geez Man
# This homework will have students parse command line arguments and exercize
# basic loops and control flow along with basic C++ program composition with
# multiple files including the use of header files


project(AwwGeezMan CXX)

# Set the standard to be C++11
set(CMAKE_CXX_STANDARD 11)

# Enable Debug by default
set(CMAKE_BUILD_TYPE Debug)

# Enable all warnings and extra warnings
if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra)
endif()

# Add the 'src' subdirectory which contains student's code
add_subdirectory(src)


# If we're testing or if we're building docker
if (TESTING OR TESTING_ONLY)
  enable_testing()
  add_subdirectory(test)
endif()
