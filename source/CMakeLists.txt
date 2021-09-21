cmake_minimum_required(VERSION 3.2)
project(SnazeGame VERSION 1.0 LANGUAGES CXX)

#=== Main App ===

include_directories("src"
                    "lib"
                    "include")

# set the compiling flags
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-g")
set (CMAKE_CXX_FLAGS "-fsanitize=address -g")

add_executable(snaze
               src/level.cpp
               src/player.cpp
               src/snake.cpp
               src/snaze_game.cpp
               src/snaze.cpp)

# Define C++11 standard
target_compile_features(snaze PUBLIC cxx_std_17)

# The end