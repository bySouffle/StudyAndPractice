project(StudyPracticelib)

set(HEADER_FILES
          nnarr.h)
set(SOURCE_FILES
          nnarr.cpp split_ip.cpp split_ip.h linklist.cpp linklist.h OverloadOperator.cpp OverloadOperator.h)

add_library(StudyPracticelib STATIC ${SOURCE_FILES}  ${HEADER_FILES})