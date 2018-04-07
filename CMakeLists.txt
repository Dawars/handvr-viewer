cmake_minimum_required(VERSION 3.9)
project(handvr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-pedantic)
#add_compile_options(-Werror)
#add_compile_options(-O0)

# Leap
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")
set(CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE STRING "" FORCE) #Disables MinSizeRel & MaxSpeedRel
set(CMAKE_INCLUDE_CURRENT_DIR ON) #essentially the same as include_directories(.) in every subdir
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_FLAGS -stdlib=libc++)
find_package(Leap REQUIRED)
include_directories(${Leap_INCLUDE_DIR})

# Qt
#set(RESOURCE_FOLDER res)
#set(RESOURCE_FILES ${RESOURCE_FOLDER}/resources.qrc)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
#find_package(Qt5Core REQUIRED)
#find_package(Qt5Quick REQUIRED)


set(UI_FILES mainwindow.ui mydialog.ui)
set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h mydialog.cpp mydialog.h mano/Mano.cpp mano/Mano.h sensor/leapmotion/LeapData.cpp sensor/leapmotion/LeapData.h)

add_executable(handvr ${SOURCE_FILES} ${RESOURCE_FILES} ${UI_FILES})

target_link_libraries(handvr Eigen3::Eigen)
target_link_libraries(handvr Qt5::Widgets Qt5::Gui)
target_link_libraries(handvr ${Leap_BUILD_LIBRARIES} )
