cmake_minimum_required(VERSION 3.10)
project(EjerciciosCorte3)

set(CMAKE_CXX_STANDARD 17)


add_executable(underground_system UndergroundSystem.cpp main_underground.cpp)

add_executable(atm_test ATM.cpp main_atm.cpp)


