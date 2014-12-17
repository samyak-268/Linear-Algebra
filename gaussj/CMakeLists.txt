add_library(GaussJ gaussj.cpp)
add_library(GaussJAbKDs gaussj_AbKDs.cpp)
target_link_libraries(GaussJ Matrix)
target_link_libraries(GaussJAbKDs Matrix)
