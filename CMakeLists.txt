cmake_minimum_required(VERSION 3.14)

# set the project name
project(ChaosGame)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(matplotplusplus
  GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
  GIT_TAG origin/master # or whatever tag you want
)

FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
  FetchContent_Populate(matplotplusplus)
  add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()



add_library(
  ChaosGame
  classes/ChaosGame.hpp
  classes/ChaosGame.cpp
)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE ChaosGame)
target_link_libraries(main PUBLIC matplot)
