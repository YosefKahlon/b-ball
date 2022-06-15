cmake_minimum_required(VERSION 3.16)
project(b_ball)

set(CMAKE_CXX_STANDARD 14)

add_executable(b_ball main.cpp sources/Team.cpp sources/Team.hpp sources/Game.cpp sources/Game.hpp sources/League.cpp sources/League.hpp sources/Schedule.cpp sources/Schedule.hpp)
