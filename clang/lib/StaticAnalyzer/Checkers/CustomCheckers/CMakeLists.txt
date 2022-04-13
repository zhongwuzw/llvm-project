IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    SET(CMAKE_SHARED_LINKER_FLAGS "-undefined dynamic_lookup")
ENDIF()

add_clang_library(CustomCheckers
    CustomCheckersRegistry.cpp
    CustomMainCallChecker.cpp
    ObjcUIViewControllerInitializeOverrideChecker.cpp
    SHARED
)
