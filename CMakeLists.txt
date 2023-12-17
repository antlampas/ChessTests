find_package(Catch2 3 REQUIRED)

set(TESTSMODULES "")

if(DEFINED BOARDTEST)
add_subdirectory(board)
set(TESTSMODULES "${TESTSMODULES} board")
endif()

if(DEFINED TIMERTEST)
add_subdirectory(timer)
set(TESTSMODULES "${TESTSMODULES} timer")
endif()

if(DEFINED TURNMANAGERTEST)
add_subdirectory(turnManager)
set(TESTSMODULES "${TESTSMODULES} turnManager")
endif()

message("${TESTSMODULES}")

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PUBLIC "${TESTSMODULES}")