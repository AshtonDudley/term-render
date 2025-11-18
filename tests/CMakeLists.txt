# tests/CMakeLists.txt
# For example using a test executable
add_executable(${PROJECT_NAME}_tests
    # list your test .cpp files here, e.g. tests/test_main.cpp
)

target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME})

add_test(NAME run_unit_tests COMMAND ${PROJECT_NAME}_tests)

