cmake_minimum_required(VERSION 2.8)

project(Donkey2)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})
#set(CMAKE_VERBOSE_MAKEFILE YES)

#### QT
find_package(Qt4 REQUIRED)

#### Glut and OpenGL
#find_package(GLUT)
#find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(QGLViewer)

#### Only require GLUT but not necessarily Xmu
#if(NOT GLUT_FOUND)
#    message(FATAL_ERROR "Could not find GLEW.")
#endif(NOT GLUT_FOUND)

if(NOT QGLVIEWER_FOUND)
  message(FATAL_ERROR "Could not find QGLViewer.")
endif(NOT QGLVIEWER_FOUND)

include(${QT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/src 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${QT_INCLUDES} 
    ${GLEW_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${QGLVIEWER_INCLUDE_DIR})

set(Donkey2_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/viewer.cpp
    src/particle.cpp
    src/timestep.cpp
    src/dataset.cpp
  )
set(Donkey2_HEADERS
    src/mainwindow.h
   )
set(Donkey2_FORMS
    src/mainwindow.ui
   )

file(COPY
    star.png
    star128.png
    testfile.xyzw
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

QT4_WRAP_CPP(Donkey2_HEADERS_MOC ${Donkey2_HEADERS})
QT4_WRAP_UI(Donkey2_FORMS_HEADERS ${Donkey2_FORMS})

add_executable(Donkey2 ${Donkey2_SOURCES} ${Donkey2_HEADERS_MOC} ${Donkey2_FORMS_HEADERS})
set_source_files_properties(${Donkey2_SOURCES} PROPERTIES LANGUAGE CXX)
target_link_libraries(Donkey2 
    ${QT_LIBRARIES}
    ${QGLVIEWER_LIBRARIES} 
   # ${GLUT_LIBRARY}
   # ${GLEW_LIBRARY}
    ${OPENGL_LIBRARIES})


 
