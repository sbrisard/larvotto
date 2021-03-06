cmake_minimum_required(VERSION 3.13)

file(READ ./metadata/version.txt METADATA_VERSION)
string(STRIP ${METADATA_VERSION} METADATA_VERSION)
file(READ ./metadata/description.txt METADATA_DESCRIPTION)
string(STRIP ${METADATA_DESCRIPTION} METADATA_DESCRIPTION)
file(READ ./metadata/author.txt METADATA_AUTHOR)
string(STRIP ${METADATA_AUTHOR} METADATA_AUTHOR)

project(
  larvotto
  VERSION ${METADATA_VERSION}
  DESCRIPTION ${METADATA_AUTHOR}
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
include(CTest)

add_compile_definitions(PROJECT_VERSION_QUOTED=\"${METADATA_VERSION}\")
add_compile_definitions(PROJECT_AUTHOR_QUOTED=\"${METADATA_AUTHOR}\")

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
