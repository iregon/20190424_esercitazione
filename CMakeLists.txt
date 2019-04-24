cmake_minimum_required(VERSION 3.13)
project(fattori_primi C)

set(CMAKE_C_STANDARD 99)

add_executable(fattori_primi main.c factors_queue.c factors_queue.h)