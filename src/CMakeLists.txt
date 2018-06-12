
set (HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/include)
set (INCLUDES
        )
set (SOURCES
        main.cpp)

source_group (TREE ${PROJECT_SOURCE_DIR}/src/include PREFIX "Header Files" FILES ${INCLUDES})
source_group (TREE ${PROJECT_SOURCE_DIR}/src PREFIX "Source Files" FILES ${SOURCES})

add_executable (${PROJECT_NAME} ${INCLUDES} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE ${HEADERS_DIR})
target_link_libraries (${PROJECT_NAME} PRIVATE sqlite3)

add_custom_command (TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E 
    copy_if_different ${PROJECT_SOURCE_DIR}/beer.db $<TARGET_FILE_DIR:${PROJECT_NAME}>)