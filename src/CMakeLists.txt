add_library(cirqueue cirqueue.cpp)
target_include_directories(cirqueue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(large_table large_table.cpp)
target_include_directories(large_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_library(run_app run_app.cpp)
target_link_libraries(run_app PUBLIC cirqueue)
target_link_libraries(run_app PUBLIC large_table)