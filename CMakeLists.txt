cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows-static")

cmake_policy(SET CMP0091 NEW)

project(PaintLike)

add_executable(PaintLike vendor/glad/src/glad.c vendor/imgui-1.79/src/imgui.cpp vendor/imgui-1.79/src/imgui_draw.cpp vendor/imgui-1.79/src/imgui_widgets.cpp vendor/imgui-1.79/src/imgui_stdlib.cpp vendor/imgui-1.79/src/imgui_demo.cpp src/main.cpp src/Engine.cpp src/Engine.h src/Shape/Polygon.h src/ShapeRegistry.h src/Shape/Line.h src/Shape/Point.h src/Renderer.cpp src/Renderer.h  src/Settings.cpp src/Settings.h)

set_property(TARGET PaintLike PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_compile_features(PaintLike PRIVATE cxx_std_20)
target_compile_options(PaintLike PRIVATE "$<$<CONFIG:Release>:-O2>")

find_path(STB_INCLUDE_DIRS "stb.h")
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

target_include_directories(PaintLike PRIVATE
		"vendor/glad/include"
		"vendor/imgui-1.79/include"
		${STB_INCLUDE_DIRS})

target_link_libraries(PaintLike PRIVATE
		glfw
		glm)

add_custom_command(TARGET PaintLike PRE_BUILD
		COMMAND robocopy ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources /E /NS /NC /NFL /NDL /NP /NJH /NJS  || cmd /c "exit /b 0")