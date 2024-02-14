add_library(director director.cc director.h)
target_link_libraries(director PUBLIC activity)
target_include_directories(director PUBLIC ${CMAKE_CURRENT_LIST_DIR})