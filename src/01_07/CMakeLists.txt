add_executable(leapyear_solution leapyear_solution.c)

add_library(leapyear leapyear.c)
target_include_directories(leapyear
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(leapyear_solution_db leapyear_main.c)
target_link_libraries(leapyear_solution_db PUBLIC leapyear)

add_executable(leapyear_test leapyear_test.c)
target_link_libraries(leapyear_test PUBLIC leapyear)

#define a function to simplify adding tests
function(do_leapyear_test arg result)
  add_test(NAME leapyearTest_${arg} COMMAND leapyear_test ${arg})
  set_tests_properties(leapyearTest_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

do_leapyear_test(1600 "true")
do_leapyear_test(1700 "false")
do_leapyear_test(1800 "false")
do_leapyear_test(1900 "false")
do_leapyear_test(2000 "true")
do_leapyear_test(2100 "false")
