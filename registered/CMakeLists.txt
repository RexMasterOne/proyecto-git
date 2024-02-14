add_library(registered registered.cc registered.h)
target_link_libraries(registered PUBLIC user)
target_link_libraries(registered PUBLIC $<TARGET_NAME:general>)
target_include_directories(registered PUBLIC ${CMAKE_CURRENT_LIST_DIR})