add_executable(king_solution king_solution.c)

add_library(king king.c)
target_include_directories(king
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(king_solution_db king_main.c)
target_link_libraries(king_solution_db PUBLIC king)

# No CTests included
