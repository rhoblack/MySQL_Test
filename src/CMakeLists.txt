add_executable(${PROJECT_NAME}
    main.cpp
)

include_directories (/usr/include/mysql)

add_compile_options(-Wall)

target_link_libraries(${PROJECT_NAME} PUBLIC
    mysqlclient
)

# link_libraries(mysqlclient)

# target_include_directories(${PROJECT_NAME} PUBLIC
#     ./
#     #/usr/include/mysql
# )

# target_compile_options(${PROJECT_NAME} PUBLIC
#     -Wall
# )



