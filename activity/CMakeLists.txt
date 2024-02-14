add_library(activity activity.cc activity.h)
target_link_libraries(activity PUBLIC $<TARGET_NAME:general>)
target_include_directories(activity PUBLIC ${CMAKE_CURRENT_LIST_DIR})
