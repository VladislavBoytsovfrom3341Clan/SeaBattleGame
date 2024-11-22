set(ABILITIES_SOURCES 
        AbilityManager.cpp
        AbilityFactory.cpp
        AbilitySettingsVisitor.cpp
        AbilityResultHandler.cpp
        DoubleDamage.cpp
        DoubleDamageSettings.cpp
        Scanner.cpp
        ScannerSettings.cpp
        ScannerResult.cpp
        Shelling.cpp
        ShellingSettings.cpp)

set(ABILITIES_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${ABILITIES_INCLUDE_DIR}/Abilities
        ${ABILITIES_INCLUDE_DIR}/Battlefield
        ${ABILITIES_INCLUDE_DIR}/Battleship 
        ${ABILITIES_INCLUDE_DIR}/Exceptions)

set(ABILITIES_HEADERS
        ${ABILITIES_INCLUDE_DIR}/Abilities/AbilityFactory.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/AbilityManager.h 
        ${ABILITIES_INCLUDE_DIR}/Abilities/IAbility.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/IVisitor.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/IAbilitySettings.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/AbilityResultHandler.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/AbilitySettingsVisitor.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/DoubleDamage.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/DoubleDamageSettings.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/Scanner.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/ScannerResult.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/ScannerSettings.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/Shelling.h
        ${ABILITIES_INCLUDE_DIR}/Abilities/ShellingSettings.h)

add_library(AbilitiesLib OBJECT ${ABILITIES_SOURCES} ${ABILITIES_HEADERS})

target_include_directories(AbilitiesLib PRIVATE ABILITIES_INCLUDE_DIR)