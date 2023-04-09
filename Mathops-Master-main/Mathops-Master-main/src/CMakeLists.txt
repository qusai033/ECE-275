if (NOT TESTING_ONLY)
  add_executable(localTest
    local_test_main.cpp)
  target_compile_options( localTest PUBLIC -std=c++17 -Wall -Wextra )
endif()
