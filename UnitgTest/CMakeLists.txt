project(PracticeTEST)


set(gtest_SOURCES /googletest-1.10.x/googletest)
include_directories(${gtest_SOURCES}/include ${gtest_SOURCES})

set(beTest /UnitgTest )
include_directories($beTest})

set(testSource
        test1.cpp)
add_executable(PracticeTEST ${testSource})

target_link_libraries(PracticeTEST StudyPracticelib)
target_link_libraries(PracticeTEST gtest gtest_main )
