set(
	libsound_SRCS
	sfx.cpp
)
include_directories(
	${LIBFILEIO_INCLUDE_DIR}
)
add_library(arkilloid_snd STATIC ${libsound_SRCS})
