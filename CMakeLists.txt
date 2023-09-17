cmake_minimum_required(VERSION 3.14)
project(UTF8Lib VERSION 0.0.5)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 23)


set(BUILDING_UTF8LIB ON)

# Now, you can conditionally check its value and apply build configurations as needed.
if(BUILDING_UTF8LIB)
    add_definitions(-DBUILDING_UTF8LIB)
    message(STATUS "BUILDING_UTF8LIB is set.")
else()
    message(STATUS "BUILDING_UTF8LIB is not set.")
endif()


# Include directories
include_directories(include)

# Create the shared library
add_library(UTF8Lib SHARED
    src/UTF8Char.cpp
    src/UTF8String.cpp
)

# Decide lib subfolder based on architecture
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH_SUBFOLDER "x64")
else()
    set(ARCH_SUBFOLDER "x86")
endif()

# Install targets and generate export targets
install(TARGETS UTF8Lib EXPORT UTF8LibTargets
    LIBRARY DESTINATION lib/${ARCH_SUBFOLDER}
    ARCHIVE DESTINATION lib/${ARCH_SUBFOLDER}
    RUNTIME DESTINATION lib/${ARCH_SUBFOLDER}
    INCLUDES DESTINATION include
)

# Install header files
install(FILES include/UTF8Char.h include/UTF8String.h DESTINATION include)

# Configuration files for find_package()
# The rest remains largely unchanged, but adjust paths to be inside "cmake" directory
install(EXPORT UTF8LibTargets
    FILE UTF8LibTargets.cmake
    NAMESPACE UTF8Lib::
    DESTINATION cmake
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/UTF8LibConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfig.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfig.cmake
    DESTINATION cmake
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/UTF8LibConfigVersion.cmake
    DESTINATION cmake
)
