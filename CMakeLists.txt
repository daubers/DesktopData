cmake_minimum_required(VERSION 3.5)
set(Qt5Widgets_DIR "/opt/Qt/5.6/gcc_64/lib/cmake/Qt5Widgets")
set(Qt5Core_DIR "/opt/Qt/5.6/gcc_64/lib/cmake/Qt5Core")
set(Qt5Gui_DIR "/opt/Qt/5.6/gcc_64/lib/cmake/Qt5Gui")
set(Qt5Network_DIR "/opt/Qt/5.6/gcc_64/lib/cmake/Qt5Network")
project(GithubData)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GitHub/Projects.cpp GitHub/Projects.h GitHub/Account.cpp GitHub/Account.h)
add_executable(GithubData ${SOURCE_FILES})
qt5_use_modules(GithubData Widgets Network)