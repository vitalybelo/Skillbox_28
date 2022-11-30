cmake_minimum_required(VERSION 3.23)

add_executable(Skillbox_28
        main.cpp
        use_lib.cpp
        SwimmingPool.cpp

        )

target_include_directories(Skillbox_28 PUBLIC ${INCLUDE_DIR})