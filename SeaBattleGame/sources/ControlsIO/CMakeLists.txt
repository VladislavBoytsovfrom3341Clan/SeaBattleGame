set(CONTROLS_IO_SOURCES 
    ParticipantController.cpp
    BotController.cpp
    ConsoleDisplayer.cpp
    GameObserver.cpp
    CLIInput.cpp)

set(CONTROLS_IO_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${CONTROLS_IO_INCLUDE_DIR}/ControlsIO)

set(CONTROLS_IO_HEADERS
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/ParticipantController.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/PlayerController.hpp
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/BotController.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/GameObserver.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/ConsoleDisplayer.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/IGameDisplayer.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/ConcreteGameDisplayer.hpp
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/CLIInput.h)

add_library(ControlsIOLib OBJECT ${CONTROLS_IO_SOURCES} ${CONTROLS_IO_HEADERS})

target_include_directories(ControlsIOLib PRIVATE CONTROLS_IO_INCLUDE_DIR)