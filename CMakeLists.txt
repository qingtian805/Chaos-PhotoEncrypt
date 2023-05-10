cmake_minimum_required(VERSION 3.0.0)

project(chaos-photo-enc VERSION 0.0.0)

set(OpenCV_DIR ${PROJECT_SOURCE_DIR}/opencv/build)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} 
                    ${PROJECT_SOURCE_DIR}/include 
                    ${PROJECT_SOURCE_DIR}/include/chaos-rng
                    ${PROJECT_SOURCE_DIR}/include/chaos-arnold)# -I

set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS} -g) #DEBUG
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS} -O2) #RELEASE

file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/*.c
)#搜索src中所有可编译文件
file(GLOB SRC_RNG
    ${PROJECT_SOURCE_DIR}/src/chaos-rng/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/chaos-rng/*.c)
file(GLOB SRC_ARNOLD
    ${PROJECT_SOURCE_DIR}/src/chaos-arnold/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/chaos-arnold/*.c)

#一些小程序
add_executable(fpoint-checker fpoint-checker.cpp)
add_executable(type-bit type-bit.cpp)

add_executable(chaos-bt-test chaos-bt-test.cpp ${SRC_RNG}) #基本类型测试
add_executable(chaos-rng-perc-test chaos-rng-perc-test.cpp ${SRC_RNG}) #随机数生成器精度测试
add_executable(chaos-rng-sped-test chaos-rng-sped-test.cpp ${SRC_RNG}) #随机数生成器速度测试
add_executable(chaos-rng-rand-test chaos-rng-rand-test.cpp ${SRC_RNG}) #随机数生成器随机性测试
add_executable(chaos-rng-func-test chaos-rng-func-test.cpp ${SRC_RNG}) #随机数生成器整合功能测试
add_executable(chaos-enc-test chaos-enc-test.cpp ${SRC_FILES} ${SRC_RNG} ${SRC_ARNOLD})
add_executable(chaos-dec-test chaos-dec-test.cpp ${SRC_FILES} ${SRC_RNG} ${SRC_ARNOLD})
add_executable(chaos-arnold-test chaos-arnold-test.cpp ${SRC_ARNOLD})
add_executable(chaos-ranenc-test chaos-ranenc-test.cpp ${SRC_FILES} ${SRC_RNG})

#一些技术测试
add_executable(argv-test argv-test.cpp)
add_executable(opencv-test opencv-test.cpp)
add_executable(opencv-test2 opencv-test2.cpp)

target_link_libraries(chaos-enc-test ${OpenCV_LIBS})
target_link_libraries(chaos-dec-test ${OpenCV_LIBS})
target_link_libraries(opencv-test ${OpenCV_LIBS})
target_link_libraries(opencv-test2 ${OpenCV_LIBS})
target_link_libraries(chaos-arnold-test ${OpenCV_LIBS})
target_link_libraries(chaos-ranenc-test ${OpenCV_LIBS})
