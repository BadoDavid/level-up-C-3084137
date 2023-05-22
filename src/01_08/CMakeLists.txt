add_executable(playlist_shuffle_challenge shuffle_challenge.c)

add_executable(playlist_shuffle_solution shuffle_solution.c)

add_library(playlist_shuffle shuffle.c)
target_include_directories(playlist_shuffle
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

add_executable(playlist_shuffle_solution_db shuffle_main.c)
target_link_libraries(playlist_shuffle_solution_db PUBLIC playlist_shuffle)

# No tests are included
