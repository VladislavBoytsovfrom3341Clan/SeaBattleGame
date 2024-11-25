#checking the version for targeting include directories
cmake_minimum_required(VERSION 3.22)

#project name
project(SeaBattleGame)

#setting source, tests and headers folders
set(SOURCE_DIR ./sources)
set(INCLUDE_DIRECTORIES ./include)

#changing executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

include_directories(${INCLUDE_DIRECTORIES} ${INCLUDE_DIRECTORIES}/Battleship 
        ${INCLUDE_DIRECTORIES}/Battlefield 
        ${INCLUDE_DIRECTORIES}/Abilities 
        ${INCLUDE_DIRECTORIES}/Exceptions
        ${INCLUDE_DIRECTORIES}/Game
        ${INCLUDE_DIRECTORIES}/Participant
        ${INCLUDE_DIRECTORIES}/Commands
        ${INCLUDE_DIRECTORIES}/ControlsIO)

add_subdirectory(${SOURCE_DIR})

#compilating main executable file
add_executable(main ${SOURCE_DIR}/main.cpp)

#retargeting headers directories
target_include_directories(main PRIVATE ${INCLUDE_DIRECTORIES})

#linking
target_link_libraries(main PRIVATE AbilitiesLib BattlefieldLib BattleshipLib ExceptionsLib GameLib ParticipantLib CommandsLib ControlsIOLib)
