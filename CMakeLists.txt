cmake_minimum_required(VERSION 3.0)

project(OpenSTG)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR}/include)

link_libraries(log4c)
link_libraries(SDL2)
link_libraries(SDL2_image)

add_definitions(-g -std=c99)

add_executable(openstg ${DIR_SRCS})

