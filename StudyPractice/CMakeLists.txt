project(StudyPracticelib)

set(HEADER_FILES
          nnarr.h)
set(SOURCE_FILES
          nnarr.cpp)

add_library(StudyPracticelib STATIC ${SOURCE_FILES}  ${HEADER_FILES})