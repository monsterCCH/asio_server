cmake_minimum_required(VERSION 3.16)

project(asio_async_client)


#设置程序头文件及源文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/source SRC_FILES)

#编译可执行程序
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME})