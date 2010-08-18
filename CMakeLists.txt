cmake_minimum_required(VERSION 2.6)
project(arkilloid)

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(Freetype REQUIRED)

set(GLFTFONT_INCLUDE_DIR extern/glftfont)

set(BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
set(DATADIR ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME})

set(ARKILLOID_INCLUDE_DIR src)
set(LIBIO_INCLUDE_DIR src/io)
set(LIBSOUND_INCLUDE_DIR src/sound)

add_definitions(-DDATADIR="${DATADIR}")
add_definitions(-DPACKAGE="${PROJECT_NAME}")
if(DEBUG)
	add_definitions(-DDEBUG)
	set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(
	${OPENGL_INCLUDE_DIR}
	${SDL_INCLUDE_DIR}
	${SDLIMAGE_INCLUDE_DIR}
	${SDLMIXER_INCLUDE_DIR}
	${SDLTTF_INCLUDE_DIR}
	${FREETYPE_INCLUDE_DIRS}
	${GLFTFONT_INCLUDE_DIR}
	${ARKILLOID_INCLUDE_DIR}
	${LIBIO_INCLUDE_DIR}
	${LIBSOUND_INCLUDE_DIR}
)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")


add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(data)
