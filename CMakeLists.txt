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

add_definitions(-DDATADIR="${DATADIR}")
add_definitions(-DPACKAGE="${PROJECT_NAME}")

include_directories(
	${OPENGL_INCLUDE_DIR}
	${SDL_INCLUDE_DIR}
	${SDLIMAGE_INCLUDE_DIR}
	${SDLMIXER_INCLUDE_DIR}
	${SDLTTF_INCLUDE_DIR}
	${FREETYPE_INCLUDE_DIRS}
	${GLFTFONT_INCLUDE_DIR}
)

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(data)
