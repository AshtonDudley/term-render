# tests/CMakeLists.txt

# Create a test executable for your vector / math code
add_executable(vector_tests
    test_vector.cpp                         # this file will live in the tests/ folder
)

target_include_directories(vector_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(vector_tests
    PRIVATE term_render_core
)

# Register the test with CTest
add_test(NAME vector_tests COMMAND vector_tests)

