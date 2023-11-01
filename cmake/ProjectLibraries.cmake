# dont clutter the compile_commands file with libraries
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

add_library(project_libraries INTERFACE)

include(FetchContent)

find_package(Threads REQUIRED)
target_link_libraries(project_libraries INTERFACE Threads::Threads)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  target_link_libraries(project_options INTERFACE OpenMP::OpenMP_CXX)
endif()

if(UNIX)
  target_link_libraries(project_options INTERFACE stdc++fs)
endif()

# declaration

# fmt
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 9.1.0)

# spdlog
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.11.0)

# make available

# fmt
FetchContent_MakeAvailable(fmt)
get_target_property(fmt_includes fmt INTERFACE_INCLUDE_DIRECTORIES)
set_target_properties(fmt PROPERTIES INTERFACE_SYSTEM_INCLUDE_DIRECTORIES
                                     "${fmt_includes}")
target_link_libraries(project_libraries INTERFACE fmt)

# spdlog
FetchContent_MakeAvailable(spdlog)
get_target_property(spdlog_includes spdlog INTERFACE_INCLUDE_DIRECTORIES)
set_target_properties(spdlog PROPERTIES INTERFACE_SYSTEM_INCLUDE_DIRECTORIES
                                        "${spdlog_includes}")
target_link_libraries(project_libraries INTERFACE spdlog)

# set compile commands back to on
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
