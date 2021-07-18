cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 14)
project(main)

include_directories(StudyPractice)
include_directories(leetcode)


add_subdirectory(googletest-1.10.x)
add_subdirectory(StudyPractice)
add_subdirectory(UnitgTest)
add_subdirectory(leetcode)
add_subdirectory(LeetcodeTest)
