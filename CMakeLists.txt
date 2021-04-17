cmake_minimum_required(VERSION 3.16)
#程序名称
project(asio_server)
#设置C++标准
set(CMAKE_CXX_STANDARD 11)

#静态库输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
#动态库输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin)
#执行程序输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置编译选项
set(CMAKE_CXX_FLAGS "-O2 -g -Wall")


#设置第三方库基础路径
set(THIRD_PARTY_LIB_BASE "/usr/local")
#设置第三方库
set(THIRD_PARTY_LIBS
        ${THIRD_PARTY_LIB_BASE}/boost1.74.0)

#设置第三库头文件路径和库路径
set(THIRD_PARTY_LIBS_INC ${THIRD_PARTY_LIBS})
set(THIRD_PARTY_LIBS_LINK ${THIRD_PARTY_LIBS})
set(THIRD_PARTY_LIBS_LINK_64 ${THIRD_PARTY_LIBS_LINK})

list(TRANSFORM THIRD_PARTY_LIBS_INC APPEND "/include")
list(TRANSFORM THIRD_PARTY_LIBS_LINK APPEND "/lib")
list(TRANSFORM THIRD_PARTY_LIBS_LINK_64 APPEND "/lib64")

include_directories(${THIRD_PARTY_LIBS_INC})
link_directories(${THIRD_PARTY_LIBS_LINK_64})
link_directories(${THIRD_PARTY_LIBS_LINK})

#设置链接库
set(LINK_OBJ
        boost_thread boost_system boost_regex pthread)

link_libraries(${LINK_OBJ})

#设置子模块目录
add_subdirectory(module/asio_sync_client)
add_subdirectory(module/asio_sync_server)

