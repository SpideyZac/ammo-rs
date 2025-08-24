cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(ammo LANGUAGES CXX)

cmake_policy(SET CMP0077 NEW)

# Build type defaults
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build Type" FORCE)
endif()

# Force static libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Bullet configuration
set(USE_GRAPHICAL_BENCHMARK OFF CACHE BOOL "" FORCE)
set(USE_GLUT OFF CACHE BOOL "" FORCE)
set(BUILD_MULTITHREADING OFF CACHE BOOL "" FORCE)
set(BUILD_DEMOS OFF CACHE BOOL "" FORCE)

# Source directories
set(BULLET_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ammo.js/bullet/src/)
set(AMMO_HEADER_FILE ${CMAKE_CURRENT_SOURCE_DIR}/ammo.js/ammo.h)

# Add Bullet subdirectory
add_subdirectory(ammo.js/bullet)

# Install all individual static libraries
install(TARGETS
    BulletCollision
    BulletDynamics
    BulletSoftBody
    LinearMath
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
