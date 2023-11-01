enable_testing()

# add custom check target, builds and tests all tests

# processor count detection and option
include(ProcessorCount)
ProcessorCount(proc_count)
set(CTEST_JOB_COUNT
    "${proc_count}"
    CACHE STRING "number of jobs that run the tests")

set(check_args -j${CTEST_JOB_COUNT} --output-on-failure ${CTEST_EXTRA_ARGS})

add_custom_target(
  check
  COMMAND
    ${CMAKE_COMMAND} -E env
    $<$<BOOL:${ENABLE_SANITIZER_ADDRESS}>:ASAN_OPTIONS=fast_unwind_on_malloc=0,symbolize=1>
    $<$<BOOL:${ENABLE_SANITIZER_LEAK}>:LSAN_OPTIONS=suppressions=${CMAKE_SOURCE_DIR}/cmake/sanitizers/lsan.supp>
    ${CMAKE_CTEST_COMMAND} ${check_args}
  USES_TERMINAL)

if(${COVERAGE_REPORT_AVAILABLE})
  add_custom_target(
    check-coverage
    DEPENDS check
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target
            coverage-report)
endif()

# # googletest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.12.1)

# google test
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(
  WRITE ${CMAKE_BINARY_DIR}/test_get_path.cpp
  "#include <filesystem>\nstd::filesystem::path get_path() { return \"${CMAKE_SOURCE_DIR}\"; }"
)

add_executable(lab_test ${SRC_TST})
target_sources(
  lab_test
  PRIVATE ${CMAKE_BINARY_DIR}/test_get_path.cpp
          test.cpp
          test_bitmap.cpp
          test_encryption.cpp
          test_io.cpp
          test_pixel.cpp
		  
		  # for visual studio
		  ${lab_test_additional_files})
		  
target_include_directories(lab_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lab_test PRIVATE project_options project_libraries)
target_link_libraries(lab_test PRIVATE lab_lib)
target_link_libraries(lab_test PRIVATE gtest)

add_test(NAME SerialTests COMMAND lab_test)
add_dependencies(check lab_test)

get_target_property(lab_test_sources lab_test SOURCES)
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${lab_test_sources})
