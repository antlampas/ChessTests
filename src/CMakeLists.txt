#FALP Chess © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

set(libraries "")

if("${MYDEFS}" MATCHES "TESTBOARD")
    add_subdirectory(board board)
    list(APPEND libraries "boardTests")
endif()
if("${MYDEFS}" MATCHES "TESTTIMER")
    add_subdirectory(timer timer)
    list(APPEND libraries "timerTests")
endif()
if("${MYDEFS}" MATCHES "TESTTURNMANAGER")
    add_subdirectory(turnManager turnManager)
    list(APPEND libraries "turnManagerTests")
endif()