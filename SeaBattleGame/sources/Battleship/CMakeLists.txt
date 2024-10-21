set(BATTLESHIP_SOURCES 
        Battleship.cpp
        ShipManager.cpp)

set(BATTLESHIP_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${BATTLESHIP_INCLUDE_DIR}/Battleship ${BATTLESHIP_INCLUDE_DIR}/Battlefield)

set(BATTLESHIP_HEADERS
        ${BATTLESHIP_INCLUDE_DIR}/Battleship/Battleship.h
        ${BATTLESHIP_INCLUDE_DIR}/Battleship/ShipManager.h)

add_library(BattleshipLib OBJECT ${BATTLESHIP_SOURCES} ${BATTLESHIP_HEADERS})

target_include_directories(BattleshipLib PRIVATE BATTLESHIP_INCLUDE_DIR)