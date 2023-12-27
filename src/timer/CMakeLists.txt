get_directory_property(MYDEFS COMPILE_DEFINITIONS)

if("${MYDEFS}" MATCHES "TESTTIMER")
add_executable(timerTests)
target_link_libraries(timerTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(timerTests PUBLIC timer)
endif()