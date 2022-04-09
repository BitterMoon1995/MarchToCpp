cmake_minimum_required(VERSION 3.19)

# (D:/Senorita/Visual Studio/Community/VC/Tools/MSVC/14.29.30037/bin/Hostx86/x86/cl.exe)

project(Diluc)
# 可以设置debug或release，盘点十大区别：
#set(CMAKE_BUILD_TYPE Debug) #Debug, Release, RelWithDebInfo, MinSizeRel
# C++版本
set(CMAKE_CXX_STANDARD 17)
add_executable(Diluc main.cpp phase1/a.cpp phase1/b.cpp phase1/c.cpp phase1/nigga.cpp phase1/nigga.h phase1/d.cpp phase2/a.cpp phase2/b.cpp phase2/c.cpp phase3/a.cpp phase3/b.cpp phase3/d.cpp phase4/a.cpp phase4/b.cpp phase4/c.cpp phase3/analyze/neco.cpp phase4/d.cpp phase3/analyze/women.cpp phase3/c.cpp phase4/e.cpp phase1/e.cpp phase1/f.cpp phase5/a.cpp phase5/b.cpp phase5/c.cpp phase6/a.cpp model/a.cpp model/Person.cpp model/Person.h phase6/b.cpp phase6/c.cpp phase6/d.cpp phase6/e.cpp phase7/a.cpp)

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

