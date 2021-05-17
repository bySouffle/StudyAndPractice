cmake_minimum_required(VERSION 3.19)
project(StudyAndPractice)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(StudyAndPractice
        CommonElement.cpp
        CommonElement.h
        SCompositeType.cpp
        SCompositeType.h
        FileOperate.cpp
        FileOperate.h
        main.cpp
        CppBase.cpp CppBase.h DictionarySearch.cpp DictionarySearch.h heap_stack_global.cpp heap_stack_global.h LogSystem.cpp LogSystem.h CharArrStr.cpp CharArrStr.h)
