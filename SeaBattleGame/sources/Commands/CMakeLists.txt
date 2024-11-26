set(COMMANDS_SOURCES 
    PlaceShipCommand.cpp
    AttackCommand.cpp)

set(COMMANDS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${COMMANDS_INCLUDE_DIR}/Commands)

set(COMMANDS_HEADERS
        ${COMMANDS_INCLUDE_DIR}/Commands/ICommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/PlaceShipCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/AttackCommand.h)

add_library(CommandsLib OBJECT ${COMMANDS_SOURCES} ${COMMANDS_HEADERS})

target_include_directories(CommandsLib PRIVATE COMMANDS_INCLUDE_DIR)