cmake_minimum_required(VERSION 3.16)
project(b_ball)

set(CMAKE_CXX_STANDARD 14)

add_executable(b_ball main.cpp Team.cpp Team.hpp Game.cpp Game.hpp League.cpp League.hpp Schedule.cpp Schedule.hpp season.cpp season.hpp)
