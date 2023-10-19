cmake_minimum_required(VERSION 3.0.0)
project(BASIC VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


file(GLOB BASIC_SRC
     "*.hpp"
     "*.cpp"
)

add_executable(BASIC ${BASIC_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
