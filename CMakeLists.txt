cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_FILES Board.cpp Board.h Game.cpp Game.h Player.cpp Player.h Point.cpp Point.h Logic.h ReversiLogic.cpp ReversiLogic.h LocalPlayer.cpp LocalPlayer.h Drawer.h ConsoleDrawer.cpp ConsoleDrawer.h AIPlayer.cpp AIPlayer.h
        RemotePlayer.cpp RemotePlayer.h RemoteGameClient.cpp RemoteGameClient.h LocalClientPlayer.cpp LocalClientPlayer.h)
set(TEST_FILES tests/test_Point.cpp tests/main_test.cpp tests/test_Board.cpp tests/test_ReversiLogic.cpp tests/test_AIPlayer.cpp)

add_executable(Reversi ${SOURCE_FILES} main.cpp GameMenuController.cpp GameMenuController.h)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES} tests/main_test.cpp)
target_link_libraries(ReversiTest gtest gtest_main)