cmake_minimum_required ( VERSION 3.0.0 )
project ( chain VERSION 0.1.0 LANGUAGES CXX )

include_directories ( include )

aux_source_directory ( include all_hpp )
aux_source_directory ( src all_cpp )

add_library(${PROJECT_NAME} ${all_cpp} ${all_hpp})