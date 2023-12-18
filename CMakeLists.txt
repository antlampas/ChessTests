find_package(Catch2 3 REQUIRED)

set(TESTSMODULES "")

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

if("${MYDEFS}" MATCHES "TESTBOARD")
add_subdirectory(board)
set(TESTSMODULES "${TESTSMODULES} board")
endif()
if("${MYDEFS}" MATCHES "TESTTIMER")
add_subdirectory(timer)
set(TESTSMODULES "${TESTSMODULES} timer")
endif()
if("${MYDEFS}" MATCHES "TESTTURNMANAGER")
add_subdirectory(turnManager)
set(TESTSMODULES "${TESTSMODULES} turnManager")
endif()

message("${TESTSMODULES}")