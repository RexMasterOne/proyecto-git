add_executable(prueba_activity prueba_activity.cc)
target_link_libraries(prueba_activity PUBLIC activity)
    
add_executable(main main.cc)
target_link_libraries(main PUBLIC activity)
target_link_libraries(main PUBLIC director)
target_link_libraries(main PUBLIC $<TARGET_NAME:general>)
target_link_libraries(main PUBLIC organizador)
target_link_libraries(main PUBLIC registered)
target_link_libraries(main PUBLIC user)

set(MY_FILES_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
file(MAKE_DIRECTORY ${MY_FILES_DIRECTORY})

file(WRITE ${MY_FILES_DIRECTORY}/user.txt "")
file(WRITE ${MY_FILES_DIRECTORY}/actividades.txt "")
file(WRITE ${MY_FILES_DIRECTORY}/preinscripciones.txt "")