cmake_minimum_required(VERSION 3.0.0)

project(chaos-photo-enc VERSION 0.0.0)

include_directories(${PROJECT_SOURCE_DIR}/include)# -I
#link_directories(${PROJECT_SOURCE_DIR}/lib)# -L

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g) #DEBUG

file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/*.c
)#搜索src中所有可编译文件

#一些小程序
add_executable(fpoint-checker fpoint-checker.cpp)
add_executable(type-bit type-bit.cpp)

add_executable(chaos-bt-test chaos-bt-test.cpp ${SRC_FILES}) #基本类型测试

#target_link_libraries(my-sm2-gektest miracl)
#target_link_libraries(my-sm2-enctest miracl)
#target_link_libraries(my-sm2-sigtest miracl)
#target_link_libraries(my-sm2-test miracl)
