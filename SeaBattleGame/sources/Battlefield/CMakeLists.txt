set(BATTLEFIELD_SOURCES 
        Battlefield.cpp
        BattlefieldCell.cpp)

set(BATTLEFIELD_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${BATTLEFIELD_INCLUDE_DIR}/Battleship ${BATTLEFIELD_INCLUDE_DIR}/Battlefield ${BATTLEFIELD_INCLUDE_DIR}/Exceptions)

set(BATTLEFIELD_HEADERS
        ${BATTLEFIELD_INCLUDE_DIR}/Battlefield/Battlefield.h
        ${BATTLEFIELD_INCLUDE_DIR}/Exceptions/OutOfRangeAttackException.h
        ${BATTLEFIELD_INCLUDE_DIR}/Exceptions/ShipPlacementException.h)

add_library(BattlefieldLib OBJECT ${BATTLEFIELD_SOURCES} ${BATTLEFIELD_HEADERS})

target_include_directories(BattlefieldLib PRIVATE BATTLEFIELD_INCLUDE_DIR)