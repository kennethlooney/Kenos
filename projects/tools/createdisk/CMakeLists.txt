set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Set the compiler flags for EFI
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c17 -Wall -Werror -m64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS}")

add_executable(createdisk main.c)
target_include_directories(createdisk PRIVATE ../../../include)
add_custom_command(
    TARGET createdisk POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running post build scripts..."
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/../tools/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:createdisk> ${CMAKE_BINARY_DIR}/../tools
)
