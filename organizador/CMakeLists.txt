add_library(organizador organizador.cc organizador.h)
target_link_libraries(organizador PUBLIC activity)
target_include_directories(organizador PUBLIC ${CMAKE_CURRENT_LIST_DIR})