add_executable(change_solution change_solution.c)

add_executable(change change.c)

target_include_directories(change PUBLIC
                           "${PROJECT_BINARY_DIR}/src/01_03"
                           )

# add_test(NAME Runs COMMAND change 0.49)
# set_tests_properties(Runs
#   PROPERTIES ENVIRONMENT TESTING_ENABLED=1
#   )

#define a function to simplify adding tests
function(do_test arg result)
  add_test(NAME Change_${arg} COMMAND change ${arg})
  set_tests_properties(Change_${arg}
    PROPERTIES ENVIRONMENT TESTING_ENABLED=1 PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

do_test(0.49 "*Q:1 D:2 N:0 P:4*")