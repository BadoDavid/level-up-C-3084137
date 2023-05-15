add_executable(centering_solution centering_solution.c)

add_executable(centering centering.c)

target_include_directories(centering PUBLIC
                           "${PROJECT_BINARY_DIR}/src/01_02"
                           )

# No tests are created
