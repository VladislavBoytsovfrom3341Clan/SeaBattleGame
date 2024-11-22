set(EXCEPTIONS_SOURCES 
        NoAbilityException.cpp
        OutOfRangeAttackException.cpp
        ShipPlacementException.cpp)

set(EXCEPTIONS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${EXCEPTIONS_INCLUDE_DIR}/Exceptions ${EXCEPTIONS_INCLUDE_DIR}/Battlefield)

set(EXCEPTIONS_HEADERS
        ${EXCEPTIONS_INCLUDE_DIR}/Exceptions/NoAbilityException.h
        ${EXCEPTIONS_INCLUDE_DIR}/Exceptions/OutOfRangeAttackException.h
        ${EXCEPTIONS_INCLUDE_DIR}/Exceptions/ShipPlacementException.h
        ${EXCEPTIONS_INCLUDE_DIR}/Battlefield/Battlefield.h)

add_library(ExceptionsLib OBJECT ${EXCEPTIONS_SOURCES} ${EXCEPTIONS_HEADERS})

target_include_directories(ExceptionsLib PRIVATE EXCEPTIONS_INCLUDE_DIR)