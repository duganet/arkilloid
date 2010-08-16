set(glftfont_SRCS
	glftfont/GLFT_Font.cpp
)

add_library (glftfont STATIC
	${glftfont_SRCS}
)

target_link_libraries (glftfont)
