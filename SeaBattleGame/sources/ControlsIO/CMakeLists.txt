set(CONTROLS_IO_SOURCES 
    PlayerController.cpp
    ParticipantController.cpp
    BotController.cpp
    CLIInput.cpp)

set(CONTROLS_IO_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${CONTROLS_IO_INCLUDE_DIR}/ControlsIO)

set(CONTROLS_IO_HEADERS
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/ParticipantController.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/PlayerController.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/BotController.h
        ${CONTROLS_IO_INCLUDE_DIR}/ControlsIO/CLIInput.h)

add_library(ControlsIOLib OBJECT ${CONTROLS_IO_SOURCES} ${CONTROLS_IO_HEADERS})

target_include_directories(ControlsIOLib PRIVATE CONTROLS_IO_INCLUDE_DIR)