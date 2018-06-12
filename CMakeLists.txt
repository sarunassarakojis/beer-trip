cmake_minimum_required (VERSION 3.10 FATAL_ERROR)

project (beer-router LANGUAGES CXX)

find_package (sqlite3 REQUIRED)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory (src/)
