
# --- Set include directories
#
include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/lib/Windows/include
)


# --- Set compile options
#
if(APPLE)
  set(CMAKE_C_FLAGS "-Wall -g")
  add_definitions("-std=c++14")
endif()


# --- Load Source Files
#
file(GLOB SRCS
  *.cpp
  Audio/*.cpp
)

file(GLOB HEAD
  *.h  *.hpp
  Audio/*.h Audio/*.hpp
)


# --- Set Source Files to Project
#
add_executable(Audio ${SRCS} ${HEAD})


# --- Find Libraries
#
if (APPLE)
  find_library(COCOA_LIBRARY     Cocoa)
  find_library(OpenGL_LIBRARY    OpenGL)
  find_library(IOKIT_LIBRARY     IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)
  set(EXTRA_LIBS
    ${COCOA_LIBRARY}
    ${OpenGL_LIBRARY}
    ${IOKIT_LIBRARY}
    ${COREVIDEO_LIBRARY}
    ${CMAKE_SOURCE_DIR}/lib/OSX/libglfw3.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libfreetype.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libFTGL.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libAntTweakBar.a
  )
elseif(MSVC)
  set(EXTRA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/OpenGL32.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/freetyped.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/ftgld.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/glfw3d.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/AntTweakBar64.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/OpenAL32.lib
  )
endif()


# --- Set Library to project
#
target_link_libraries(Audio ${EXTRA_LIBS})


# --- copy AntTweakBar.dll to dir[vs2015/src/Debug]
#
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/vs2015/src/Debug)
execute_process(COMMAND
  cp ${CMAKE_SOURCE_DIR}/lib/Windows/lib/AntTweakBar64.dll
     ${CMAKE_SOURCE_DIR}/vs2015/src/Debug
)
execute_process(COMMAND
  cp ${CMAKE_SOURCE_DIR}/lib/Windows/lib/OpenAL32.dll
     ${CMAKE_SOURCE_DIR}/vs2015/src/Debug
)
execute_process(COMMAND
  cp ${CMAKE_SOURCE_DIR}/lib/Windows/lib/wrap_oal.dll
     ${CMAKE_SOURCE_DIR}/vs2015/src/Debug
)
