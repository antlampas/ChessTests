get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_executable(timerTests)
target_link_libraries(timerTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(timerTests PUBLIC timer)

add_test(NAME timerTests COMMAND timerTests)