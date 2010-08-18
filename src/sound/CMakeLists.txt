set(
	libsound_SRCS
	sound.cpp
	sdl/audio.cpp
	sdl/music.cpp
	sdl/sfx.cpp
)

add_library(arkilloid_sound STATIC ${libsound_SRCS})
