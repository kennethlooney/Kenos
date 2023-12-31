add_executable(createdisk main.c test.c)
target_include_directories(createdisk PRIVATE ../../../include)
add_custom_command(
    TARGET createdisk POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running post build scripts..."
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/../tools/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:createdisk> ${CMAKE_BINARY_DIR}/../tools
)
