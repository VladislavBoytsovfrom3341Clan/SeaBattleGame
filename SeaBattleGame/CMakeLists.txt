#checking the version for targeting inklude directories
cmake_minimum_required(VERSION 3.22)

#project name
project(SeaBattleGame)

#setting source, tests and headers folders
set(SOURCE_DIR ./sources)
set(INCLUDE_DIRECTORIES ./include)

#setting headers
file(GLOB HEADER_FILES ${INCLUDE_DIRECTORIES}/*.h)

#setting source files
file(GLOB SOURCE_LIB ${SOURCE_DIR}/*.cpp)

#changing executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

#compilating main executable file
add_executable(main ${SOURCE_LIB} ${HEADER_FILES})

#retargeting headers directories
target_include_directories(main PRIVATE ${INCLUDE_DIRECTORIES})

#linking
target_link_libraries(main)
