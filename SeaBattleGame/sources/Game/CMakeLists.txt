set(GAME_SOURCES 
    GameState.cpp    
    Game.cpp)

set(GAME_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${GAME_INCLUDE_DIR}/Game)

set(GAME_HEADERS
        ${GAME_INCLUDE_DIR}/Game/Game.h
        ${GAME_INCLUDE_DIR}/Game/GameState.h)

add_library(GameLib OBJECT ${GAME_SOURCES} ${GAME_HEADERS})

target_include_directories(GameLib PRIVATE GAME_INCLUDE_DIR)