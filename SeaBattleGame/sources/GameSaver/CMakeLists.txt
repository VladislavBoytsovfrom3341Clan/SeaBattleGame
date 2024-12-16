set(GAME_SAVER_SOURCES
        FileHandler.cpp
        GameSaver.cpp)

set(GAME_SAVER_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${GAME_SAVER_INCLUDE_DIR}/GameSaver)

set(GAME_SAVER_HEADERS
        ${GAME_SAVER_INCLUDE_DIR}/GameSaver/GameSaver.h
        ${GAME_SAVER_INCLUDE_DIR}/GameSaver/FileHandler.h)

add_library(SaverLib OBJECT ${GAME_SAVER_SOURCES} ${GAME_SAVER_HEADERS})

target_include_directories(SaverLib PRIVATE GAME_SAVER_INCLUDE_DIR)