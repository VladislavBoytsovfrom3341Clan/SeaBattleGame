#checking the version for targeting inklude directories
cmake_minimum_required(VERSION 3.22)

#project name
project(SeaBattleGame)

#setting source, tests and headers folders
set(SOURCE_DIR ./sources)
set(INCLUDE_DIRECTORIES ./include)

#setting headers
set(HEADER_FILES ${INCLUDE_DIRECTORIES}/Battleship.h ${INCLUDE_DIRECTORIES}/ShipManager.h ${INCLUDE_DIRECTORIES}/Battlefield.h)

#setting source files
set(SOURCE_OUT ${SOURCE_DIR}/main.cpp)
set(SOURCE_LIB ${SOURCE_DIR}/Battleship.cpp ${SOURCE_DIR}/ShipManager.cpp ${SOURCE_DIR}/Battlefield.cpp ${SOURCE_DIR}/BattlefieldCell.cpp ${HEADER_FILES})

#changing executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

#compilating included source files as static library
add_library(SeaBattleGame STATIC ${SOURCE_LIB})

#retargeting headers directories
target_include_directories(SeaBattleGame PRIVATE ${INCLUDE_DIRECTORIES})

#compilating main executable file
add_executable(main ${SOURCE_OUT})

#retargeting headers directories
target_include_directories(main PRIVATE ${INCLUDE_DIRECTORIES})

#linking
target_link_libraries(main SeaBattleGame)
