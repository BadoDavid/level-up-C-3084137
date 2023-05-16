add_executable(change_solution change_solution.c)

add_library(change change.c)
target_include_directories(change
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(change_solution_db change_main.c)
target_link_libraries(change_solution_db PUBLIC change)

add_executable(change_test change_test.c)
target_link_libraries(change_test PUBLIC change)

#define a function to simplify adding tests
function(do_change_test arg result)
  add_test(NAME ChangeTest_${arg} COMMAND change_test ${arg})
  set_tests_properties(ChangeTest_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

do_change_test(0.49 "Q:1 D:2 N:0 P:4")
do_change_test(1.27 "Q:5 D:0 N:0 P:2")
do_change_test(0.75 "Q:3 D:0 N:0 P:0")
do_change_test(1.31 "Q:5 D:0 N:1 P:1")
do_change_test(0.83 "Q:3 D:0 N:1 P:3")