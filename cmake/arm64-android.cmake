message("use toolchain file arm64-android.cmake")

if(NOT DEFINED ENV{ANDROID_NDK})
    message(FATAL_ERROR "ENV ANDROID_NDK not set")
endif()

set(ANDROID_NDK $ENV{ANDROID_NDK} CACHE PATH "Android ndk path" FORCE)
set(ANDROID_ABI arm64-v8a CACHE STRING "Android ABI" FORCE)
set(ANDROID_NATIVE_API_LEVEL android-24 CACHE STRING "Android API LEVEL" FORCE)
set(ANDROID_STL c++_shared CACHE STRING "Android C++ runtime linkage" FORCE)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Android build type" FORCE)
set(ORIGINAL_ANDROID_TOOLCHAIN_FILE ${ANDROID_NDK}/build/cmake/android.toolchain.cmake CACHE STRING "Android toolchain file" FORCE)
SET(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "Makefile log verbose")
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Export compile commands to file")

include(${ORIGINAL_ANDROID_TOOLCHAIN_FILE})

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

