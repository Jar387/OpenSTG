cmake_minimum_required(VERSION 3.0)

project(OpenSTG)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ecl DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/media DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/util DIR_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/ecl)
include_directories(${PROJECT_SOURCE_DIR}/include/media)
include_directories(${PROJECT_SOURCE_DIR}/include/util)

link_libraries(log4c)
link_libraries(SDL2)
link_libraries(SDL2_image)
link_libraries(SDL2_mixer)
link_libraries(m)

add_definitions(-std=c99 -ggdb)

add_executable(openstg ${DIR_SRCS})

