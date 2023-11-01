cmake_minimum_required(VERSION 3.10)
project(pp-lab)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# enable_language(CUDA)

include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# project options
add_library(project_options INTERFACE)

# enable cache system
include(cmake/Cache.cmake)

# Add linker configuration
include(cmake/Linker.cmake)
configure_linker(project_options)

# make libraries available
include(cmake/ProjectLibraries.cmake)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

include(cmake/VisualStudio.cmake)

# utilities
include(cmake/Utils.cmake)

add_subdirectory(source)

add_subdirectory(benchmark)
add_subdirectory(test)
