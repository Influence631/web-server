cmake_minimum_required(VERSION 3.28)


PROJECT(
network 
VERSION 1.0 
LANGUAGES CXX
)

find_package(OpenSSL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

#message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
#message(STATUS "CMAKE_CURRENT_BINARY_DIR=${CMAKE_CURRENT_BINARY_DIR}")
#message(STATUS "PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
#message(STATUS "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")



#------------Server executable
add_executable(server src/Server.cpp)


target_compile_definitions(server PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)

target_link_libraries(server PRIVATE OpenSSL::SSL OpenSSL::Crypto)

#------------Client executable

add_executable(client src/Client.cpp)


target_compile_definitions(client PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)

target_link_libraries(client PRIVATE OpenSSL::SSL OpenSSL::Crypto)
