cmake_minimum_required(VERSION 3.8)

project(app)

# Set the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
  # Default setting
  message(STATUS "Target system is Linux")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
  # Windows
  message(STATUS "Target system is Windows")
  # Set which compilers to use for C and C++
  set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
  set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
  # Set where the target environment located
  set(CMAKE_FIND_ROOT_PATH  /usr/x86_64-w64-mingw32)
  # adjust the default behavior of the FIND_XXX() commands:
  # search programs in the host environment
  set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
  # search headers and libraries in the target environment
  set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
  set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
else()
  # Default setting
endif()


add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/imagesource.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/aui.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/configloader.cpp
)


target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
)