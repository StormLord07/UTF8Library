cmake_minimum_required(VERSION 3.14)
project(UTF8Lib VERSION 0.0.5)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Create the shared library
add_library(UTF8Lib SHARED
    src/UTF8Char.cpp
    src/UTF8String.cpp
)

# Install targets and generate export targets
install(TARGETS UTF8Lib EXPORT UTF8LibTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(EXPORT UTF8LibTargets
    FILE UTF8LibTargets.cmake
    NAMESPACE UTF8Lib::
    DESTINATION lib/cmake/UTF8Lib
)

# Install header files
install(FILES include/UTF8Char.h include/UTF8String.h DESTINATION include)

# Create and install the Config file
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/UTF8LibConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfig.cmake
    INSTALL_DESTINATION lib/cmake/UTF8Lib
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfig.cmake
    DESTINATION lib/cmake/UTF8Lib
)

# Generate and install the Version file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfigVersion.cmake
    DESTINATION lib/cmake/UTF8Lib
)
