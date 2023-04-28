cmake_minimum_required(VERSION 3.0.0)

project(chaos-photo-enc VERSION 0.0.0)

set(OpenCV_DIR ${PROJECT_SOURCE_DIR}/opencv/build)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)# -I

set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS} -g) #DEBUG
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS} -O2) #RELEASE

file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/*.c
)#搜索src中所有可编译文件

#一些小程序
add_executable(fpoint-checker fpoint-checker.cpp)
add_executable(type-bit type-bit.cpp)

add_executable(chaos-bt-test chaos-bt-test.cpp ${SRC_FILES}) #基本类型测试
add_executable(chaos-rng-perc-test chaos-rng-perc-test.cpp ${SRC_FILES}) #随机数生成器精度测试
add_executable(chaos-rng-sped-test chaos-rng-sped-test.cpp ${SRC_FILES}) #随机数生成器速度测试
add_executable(chaos-rng-rand-test chaos-rng-rand-test.cpp ${SRC_FILES}) #随机数生成器随机性测试
add_executable(chaos-rng-func-test chaos-rng-func-test.cpp ${SRC_FILES}) #随机数生成器整合功能测试
add_executable(chaos-impc-test chaos-impc-test.cpp ${SRC_FILES})

#一些技术测试
add_executable(argv-test argv-test.cpp)
add_executable(opencv-test opencv-test.cpp)
add_executable(opencv-test2 opencv-test2.cpp)

target_link_libraries(chaos-impc-test ${OpenCV_LIBS})
target_link_libraries(opencv-test ${OpenCV_LIBS})
target_link_libraries(opencv-test2 ${OpenCV_LIBS})
