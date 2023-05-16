add_executable(ordinal_solution ordinal_solution.c)

add_library(ordinal ordinal.c)
target_include_directories(ordinal
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(ordinal_solution_db ordinal_main.c)
target_link_libraries(ordinal_solution_db PUBLIC ordinal)

add_executable(ordinal_test ordinal_test.c)
target_link_libraries(ordinal_test PUBLIC ordinal)

#define a function to simplify adding tests
function(do_ordinal_test arg result)
  add_test(NAME OrdinalTest_${arg} COMMAND ordinal_test ${arg})
  set_tests_properties(OrdinalTest_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${arg}${result}
    )
endfunction()

do_ordinal_test(1 "st")
do_ordinal_test(2 "nd")
do_ordinal_test(3 "rd")
do_ordinal_test(4 "th")
do_ordinal_test(10 "th")
do_ordinal_test(11 "th")
do_ordinal_test(12 "th")
do_ordinal_test(13 "th")
do_ordinal_test(14 "th")
do_ordinal_test(21 "st")
do_ordinal_test(32 "nd")
do_ordinal_test(43 "rd")
do_ordinal_test(54 "th")
do_ordinal_test(65 "th")
do_ordinal_test(76 "th")
do_ordinal_test(87 "th")
do_ordinal_test(98 "th")
