add_executable(ordinal_solution ordinal_solution.c)

add_executable(ordinal ordinal.c)

target_include_directories(ordinal PUBLIC
                           "${PROJECT_BINARY_DIR}/src/01_01"
                           )

#define a function to simplify adding tests
function(do_test arg result)
  add_test(NAME Comp${arg} COMMAND ordinal ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES ENVIRONMENT TESTING_ENABLED=1 PASS_REGULAR_EXPRESSION ${arg}${result}
    )
endfunction()

do_test(1 "st")
do_test(2 "nd")
do_test(3 "rd")
do_test(4 "th")
do_test(10 "th")
do_test(11 "th")
do_test(12 "th")
do_test(13 "th")
do_test(14 "th")
do_test(21 "st")
do_test(32 "nd")
do_test(43 "rd")
do_test(54 "th")
do_test(65 "th")
do_test(76 "th")
do_test(87 "th")
do_test(98 "th")
