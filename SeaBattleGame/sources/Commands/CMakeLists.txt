set(COMMANDS_SOURCES
    DoubleDamageCommand.cpp
    ScannerCommand.cpp
    ShellingCommand.cpp
    PlaceShipCommand.cpp
    SaveCommand.cpp
    LoadCommand.cpp
    AttackCommand.cpp)

set(COMMANDS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${COMMANDS_INCLUDE_DIR}/Commands)

set(COMMANDS_HEADERS
        ${COMMANDS_INCLUDE_DIR}/Commands/ICommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/SaveCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/LoadCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/DoubleDamageCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/ScannerCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/ShellingCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/PlaceShipCommand.h
        ${COMMANDS_INCLUDE_DIR}/Commands/AttackCommand.h)

add_library(CommandsLib OBJECT ${COMMANDS_SOURCES} ${COMMANDS_HEADERS})

target_include_directories(CommandsLib PRIVATE COMMANDS_INCLUDE_DIR)