cmake_minimum_required(VERSION 3.16)

project(OpenSTG C)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ecl DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/media DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/util DIR_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(OpenSSL REQUIRED Crypto)

link_libraries(log4c)
link_libraries(SDL2)
link_libraries(SDL2_image)
link_libraries(SDL2_mixer)
link_libraries(m)

add_definitions(-std=c99 -ggdb -Wall)
add_definitions(-DOPENSSL_API_COMPAT=0x10101000L)


add_executable(openstg ${DIR_SRCS})

target_link_libraries(openstg PRIVATE OpenSSL::Crypto)
