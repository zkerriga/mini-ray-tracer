project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_FILES
        color_test.cpp)

#set(LBSD_DIR /usr/lib/x86_64-linux-gnu/libbsd.so)

add_executable(Google_Tests_run ${TEST_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run test)
#target_link_libraries(Google_Tests_run ${LBSD_DIR})