cmake_minimum_required(VERSION 2.6)
project(arkilloid)

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(Freetype REQUIRED)

set(GLFTFONT_INCLUDE_DIR extern/glftfont)

set(DATA_DIR share/arkilloid)
set(DATA_FONTS_SUFFIX fonts)
set(DATA_IMAGES_SUFFIX images)
set(DATA_MAPS_SUFFIX maps)
set(DATA_MUSIC_SUFFIX sounds/music)
set(DATA_SOUNDFX_SUFFIX sounds/sfx)
set(DATA_FONTS_DIR ${DATA_DIR}/${DATA_FONTS_SUFFIX})
set(DATA_IMAGES_DIR ${DATA_DIR}/${DATA_IMAGES_SUFFIX})
set(DATA_MAPS_DIR ${DATA_DIR/${DATA_MAPS_SUFFIX})
set(DATA_MUSIC_DIR ${DATA_DIR}/${DATA_MUSIC_SUFFIX})
set(DATA_SOUNDFX_DIR ${DATA_DIR}/${DATA_SOUNDFX_SUFFIX})

add_definitions(-DDATADIR="${CMAKE_INSTALL_PREFIX}/${DATA_DIR}")
add_definitions(-DPACKAGE="arkilloid")

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
