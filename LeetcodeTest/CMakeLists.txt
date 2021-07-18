project(leetcoderun)

set(gtest_SOURCES /googletest-1.10.x/googletest)
include_directories(${gtest_SOURCES}/include ${gtest_SOURCES})

set(TEST_SOURCES LeetcodeTest.cpp)
add_executable(leetcoderun ${TEST_SOURCES})

target_link_libraries(leetcoderun leetcode )
target_link_libraries(leetcoderun gtest gtest_main)
