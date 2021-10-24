cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_NAME game)

project(${PROJECT_NAME})

add_executable(game 	src/main.cpp 
	src/game.cpp					src/game.h
	src/Levels/level.h			
	src/Levels/first_level.cpp		src/Levels/first_level.h
	src/objects/AircraftParts/body.cpp		src/objects/AircraftParts/body.h
	src/objects/AircraftParts/engine.cpp	src/objects/AircraftParts/engine.h	
	src/objects/AircraftParts/wings.cpp		src/objects/AircraftParts/wings.h
	src/objects/AircraftParts/tail.cpp		src/objects/AircraftParts/tail.h
	src/objects/plane.cpp			src/objects/plane.h
	src/objects/physical_object.cpp	src/objects/physical_object.h
	src/objects/graphic_object.cpp	src/objects/graphic_object.h
	src/loads/shader.cpp 			src/loads/shader.h
	src/loads/texture.cpp 			src/loads/texture.h
	src/camera.cpp 					src/camera.h
	src/loads/resources.cpp 		src/loads/resources.h
	src/loads/stb_image.h 			src/loads/stb_image.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lGL -std=c++11")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GL_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

include_directories(external/glm)
