cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dsac)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(dsac src/main.cpp
                    src/box_optimizer.cpp
                    src/cart_analysis.cpp
                    src/customer_loyalty.cpp
                    src/api_monitor.cpp
                    )

add_executable(my_test 
                src/box_optimizer.cpp
                src/cart_analysis.cpp
                src/customer_loyalty.cpp
                src/api_monitor.cpp
                tests/test.cpp
                )

enable_testing()
add_test(NAME my_test COMMAND my_test)