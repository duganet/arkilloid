set(
	libsound_SRCS
	sound.cpp
	sdl/sfx.cpp
)

add_library(arkilloid_sound STATIC ${libsound_SRCS})
