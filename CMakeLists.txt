# cmake verson，指定cmake版本 
cmake_minimum_required(VERSION 3.2)
 
# project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(OpenRGA VERSION 1.0)
 
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
 
#---------------------------libOpenRga------------------------------#

# source directory，源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
 
# set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行 的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
SET(SRC_CODE
 ${DIR_SRCS}
)

# add library
ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_CODE})


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



# 想要让用户install安装
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets 
    LIBRARY DESTINATION /usr/local/lib  # 动态库安装路径
    PUBLIC_HEADER DESTINATION /usr/local/include  # 头文件安装路径
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
    )


include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}Library
)

# message("1:${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Config.cmake.in 2:${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}LibraryConfig.cmake")

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
)