set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Set the compiler flags for EFI
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -m64 -mabi=ms -ffreestanding")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS}")

# Set the linker flags for EFI
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wall -Werror -m64 -mabi=ms -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e efi_main")
set(CMAKE_EXECUTABLE_SUFFIX ".efi")
add_executable(boot efimain.c) 
set_target_properties(boot PROPERTIES OUTPUT_NAME "BOOTX64")
add_custom_command(
    TARGET boot POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running post build scripts..."
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/../image/efi/boot
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:boot> ${CMAKE_BINARY_DIR}/../image/efi/boot
)
