set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header ${header_path}/Automata.h)
set(src Automata.cpp)

set(headerMenu ${header_path}/Menu.h)
set(srcMenu Menu.cpp)

add_library(Automata SHARED
  ${header}
  ${src})
  
add_library(Menu SHARED
  ${headerMenu}
  ${srcMenu})
  
target_include_directories(Automata
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
         
target_include_directories(Menu
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
         
target_link_libraries(Automata
  pthread)
target_link_libraries(Menu
  pthread)
  
add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS Automata
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
    
install(TARGETS Menu
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)

install(TARGETS ${PROJECT_NAME}.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")
install(FILES ${headerMenu} DESTINATION "${include_dest}")
