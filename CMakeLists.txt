cmake_minimum_required(VERSION 2.8)
PROJECT(QUEUE)
INCLUDE_DIRECTORIES(
    include
    )
SET(SRC_LIST main.cpp queue.cpp)
ADD_SUBDIRECTORY(src bin)
SET(QUEUE_SOURCE_DIR src)

