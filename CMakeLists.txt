cmake_minimum_required(VERSION 3.19)

project(Diluc)

set(CMAKE_CXX_STANDARD 14)

add_executable(Diluc main.cpp phase1/a.cpp phase1/b.cpp phase1/c.cpp phase1/nigga.cpp phase1/nigga.h phase1/d.cpp phase2/a.cpp phase2/b.cpp phase2/c.cpp phase3/a.cpp phase3/b.cpp phase3/c.cpp phase3/d.cpp)

# gtest配置
# 编译google test，会在当前目录生成libtest.a静态库
add_subdirectory(./googletest-master)
#头文件
include_directories(${PROJECT_SOURCE_DIR}/src/include ./googletest/include)
target_link_libraries(${PROJECT_NAME} gtest)

#编译选项配置
#TOOL CHAIN为vscode时，需要配置为gbk
#同时在editor-file encoding设置编码为UTF-8
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/gbk>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/gbk>")

