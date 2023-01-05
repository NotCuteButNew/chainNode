cmake_minimum_required ( VERSION 3.0.0 )
project ( mychain VERSION 0.1.0 LANGUAGES CXX )

include ( CTest )
enable_testing ()

add_subdirectory ( chain )

include_directories ( chain/include )

add_executable ( mychain main.cpp )

target_link_libraries ( ${PROJECT_NAME} chain )

set ( CPACK_PROJECT_NAME ${PROJECT_NAME} )
set ( CPACK_PROJECT_VERSION ${PROJECT_VERSION} )
include ( CPack )
