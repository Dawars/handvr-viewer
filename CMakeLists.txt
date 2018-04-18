cmake_minimum_required(VERSION 3.9)
project(handvr-viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-pedantic)
#add_compile_options(-Werror)
add_compile_options(-Werror=unused-variable)
#add_compile_options(-fno-elide-constructors)
add_compile_options(-O0)

# Leap
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")
set(CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE STRING "" FORCE) #Disables MinSizeRel & MaxSpeedRel
set(CMAKE_INCLUDE_CURRENT_DIR ON) #essentially the same as include_directories(.) in every subdir
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_FLAGS -stdlib=libc++)
find_package(Leap REQUIRED)
include_directories(${Leap_INCLUDE_DIR})

# Qt
set(RESOURCE_FOLDER res)
set(RESOURCE_FILES ${RESOURCE_FOLDER}/resources.qrc)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
#find_package(Qt5Core REQUIRED)
#find_package(Qt5Quick REQUIRED)


set(UI_FILES src/ui/mainwindow.ui src/ui/mydialog.ui)
set(SOURCE_FILES
        src/main.cpp
        src/ui/mainwindow.cpp src/ui/mainwindow.h
        src/ui/mydialog.cpp src/ui/mydialog.h
        src/mano/Mano.cpp src/mano/Mano.h
        src/sensor/leapmotion/LeapHandController.cpp src/sensor/leapmotion/LeapHandController.h
        src/ui/widgets/HandWidget.cpp src/ui/widgets/HandWidget.h
        src/util/LogHandler.cpp src/util/LogHandler.h
        src/sensor/leapmotion/LeapProvider.cpp src/sensor/leapmotion/LeapProvider.h
        src/sensor/leapmotion/LeapServiceProvider.cpp src/sensor/leapmotion/LeapServiceProvider.h
        src/sensor/leapmotion/HandRepresentation.cpp src/sensor/leapmotion/HandRepresentation.h
        src/sensor/leapmotion/HandPool.cpp src/sensor/leapmotion/HandPool.h
        src/sensor/leapmotion/HandModelBase.cpp src/sensor/leapmotion/HandModelBase.h
        src/sensor/leapmotion/HandModel.cpp src/sensor/leapmotion/HandModel.h
        src/sensor/leapmotion/FingerModel.cpp src/sensor/leapmotion/FingerModel.h
        src/sensor/leapmotion/SkeletalHand.cpp src/sensor/leapmotion/SkeletalHand.h src/sensor/leapmotion/SkeletalFinger.cpp src/sensor/leapmotion/SkeletalFinger.h)
include_directories(src/ui/widgets/)

add_executable(handvr-viewer ${SOURCE_FILES} ${RESOURCE_FILES} ${UI_FILES} ${RESOURCE_FILES})

target_link_libraries(handvr-viewer Eigen3::Eigen)
target_link_libraries(handvr-viewer Qt5::Widgets Qt5::Gui)
target_link_libraries(handvr-viewer ${Leap_BUILD_LIBRARIES} )
