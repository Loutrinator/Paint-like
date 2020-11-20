cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_STANDARD 20)

project(Paint-like)

add_executable(${PROJECT_NAME} vendor/glad/src/glad.c src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
        "vendor/glad/include"
		"vendor/glfw-3.3.2/include")

target_link_directories(${PROJECT_NAME} PRIVATE
		"vendor/glfw-3.3.2/lib")

target_link_libraries(${PROJECT_NAME} PRIVATE
		glfw3)