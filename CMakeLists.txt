cmake_minimum_required (VERSION 2.6)
project (LinearAlgebra)
set (LinearAlgebra_VERSION_MAJOR 1)
set (LinearAlgebra_VERSION_MINOR 0)

include_directories ("${PROJECT_SOURCE_DIR}/matrix")
add_subdirectory(matrix)

add_executable (LinearAlgebra main.cpp)
target_link_libraries(LinearAlgebra Matrix)
