add_executable(shuffle_solution1 shuffle_solution1.c)

add_executable(shuffle_solution2 shuffle_solution2.c)

add_library(shuffle shuffle.c)
target_include_directories(shuffle
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(shuffle_solution_db shuffle_main.c)
target_link_libraries(shuffle_solution_db PUBLIC shuffle)

add_executable(shuffle_test shuffle_test.c)
target_link_libraries(shuffle_test PUBLIC shuffle)

#define a function to simplify adding tests
function(do_shuffle_test arg result)
  add_test(NAME ShuffleTest_${arg} COMMAND shuffle_test ${arg})
  set_tests_properties(ShuffleTest_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

do_shuffle_test("ABCDEFGHIJKLMNOPQRSTUVWXYZ" "20 iterations")
do_shuffle_test("ABCDEFGHIJKLMNOPQRSTUVWXY" "-1 iterations")
