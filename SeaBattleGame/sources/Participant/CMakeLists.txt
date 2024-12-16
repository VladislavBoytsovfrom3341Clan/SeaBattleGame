set(PARTICIPANT_SOURCES 
        Player.cpp
        Bot.cpp
        Participant.cpp)

set(PARTICIPANT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${PARTICIPANT_INCLUDE_DIR}/Participant)

set(PARTICIPANT_HEADERS
        ${PARTICIPANT_INCLUDE_DIR}/Participant/Participant.h
        ${PARTICIPANT_INCLUDE_DIR}/Participant/Player.h
        ${PARTICIPANT_INCLUDE_DIR}/Participant/Bot.h)

add_library(ParticipantLib OBJECT ${PARTICIPANT_SOURCES} ${PARTICIPANT_HEADERS})

target_include_directories(ParticipantLib PRIVATE PARTICIPANT_INCLUDE_DIR)