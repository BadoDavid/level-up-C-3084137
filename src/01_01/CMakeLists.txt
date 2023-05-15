add_executable(ordinal_solution ordinal_solution.c)

option(USE_CTEST "Use Ctest" OFF)

configure_file(ordinal.h.in ordinal.h)

add_executable(ordinal ordinal.c)

target_include_directories(ordinal PUBLIC
                           "${PROJECT_BINARY_DIR}/src/01_01"
                           )

if(USE_CTEST)

include(CTest)

add_test(NAME Usage COMMAND ordinal 25)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "25th"
  )

# define a function to simplify adding tests
# function(do_test target arg result)
#   add_test(NAME Comp${arg} COMMAND ${target} ${arg})
#   set_tests_properties(Comp${arg}
#     PROPERTIES PASS_REGULAR_EXPRESSION ${result}
#     )
# endfunction()

endif()
