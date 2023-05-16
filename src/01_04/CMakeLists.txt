add_executable(hailstone_solution hailstone_solution.c)

add_library(hailstone hailstone.c)
target_include_directories(hailstone
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(hailstone_solution_db hailstone_main.c)
target_link_libraries(hailstone_solution_db PUBLIC hailstone)

add_executable(hailstone_test hailstone_test.c)
target_link_libraries(hailstone_test PUBLIC hailstone)

#define a function to simplify adding tests
function(do_hailstone_test arg result)
  add_test(NAME HailstoneTest_${arg} COMMAND hailstone_test ${arg})
  set_tests_properties(HailstoneTest_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

do_hailstone_test(18 "Sequence length: 21")
do_hailstone_test(27 "Sequence length: 112")
