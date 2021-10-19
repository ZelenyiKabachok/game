cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_NAME game)

project(${PROJECT_NAME})

add_executable(game 	src/main.cpp 
	src/gravity_object.cpp	src/gravity_object.h
	src/sprite.cpp		src/sprite.h
	src/camera.cpp 		src/camera.h
	src/shader.cpp 		src/shader.h
	src/texture.cpp 	src/texture.h
	src/resources.cpp 	src/resources.h
	src/loads/stb_image.h 	src/loads/stb_image.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lGL")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GL_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

include_directories(external/glm)
