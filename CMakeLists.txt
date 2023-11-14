# cmake verson，指定cmake版本 
cmake_minimum_required(VERSION 3.2)
 
# project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(OpenRGA)
 
SET(CMAKE_CXX_STANDARD 11) # 设置c++版本为c11 


# 定义一个选项，用于控制生成何种类型的Makefile
option(USE_DEBUG "Build with debug flags" ON)

# 在Debug模式下添加调试标志，优化标志，和gtest
if(USE_DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    set(CMAKE_BUILD_TYPE Release)
endif()



# head file path，头文件目录
INCLUDE_DIRECTORIES(
 include
)
 
# source directory，源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
 
# set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行 的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
SET(SRC_CODE
 ${DIR_SRCS}
)

# add library
ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_CODE})



# 链接libfuse3库和pthread库
# find_package(PkgConfig)
# # pkg_search_module(自定义名  必需项  查找库名)
# pkg_search_module(FUSE REQUIRED fuse3)

# target_include_directories(${EXE_INIT} PUBLIC ${FUSE_INCLUDE_DIRS})
# target_link_libraries(${EXE_INIT} PUBLIC ${FUSE_LIBRARIES})


# find_package(Threads REQUIRED)
# target_link_libraries(${EXE_INIT} PUBLIC Threads::Threads)
# target_link_libraries(${LIB_FUC} PUBLIC Threads::Threads)

# target_link_libraries(${EXE_FS} ${LIB_FUC} )

# 查找OpenCV包
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBRARIES})

# 查找librga包
find_package(PkgConfig)
# pkg_search_module(自定义名  必需项  查找库名)

pkg_search_module(RGA REQUIRED librga)
set (RGA_INCLUDE_DIRS /usr/include/rga/)
target_include_directories(${PROJECT_NAME} PUBLIC ${RGA_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${RGA_LIBRARIES})
message("1:${RGA_INCLUDE_DIRS} 2:${RGA_LIBRARIES}")


# 想要让用户install安装
install(TARGETS ${PROJECT_NAME}
     EXPORT ${PROJECT_NAME}Targets 
     LIBRARY DESTINATION /usr/local/lib  # 动态库安装路径
     PUBLIC_HEADER DESTINATION /usr/local/include  # 头文件安装路径
)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)