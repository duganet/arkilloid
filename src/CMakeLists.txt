add_subdirectory(io)
add_subdirectory(sound)

set(
	arkilloid_SRCS
	Ball.cpp
	Bita.cpp
	Bonus.cpp
	Bonus_Die.cpp
	Bonus_Life.cpp
	Bonus_speed.cpp
	Bonus_speedDown.cpp
	Brick.cpp
	BrickBeton.cpp
	BrickControl.cpp
	BrickStrong.cpp
	Button.cpp
	Checkbox.cpp
	Game.cpp
	GameState.cpp
	Globals.cpp
	Help.cpp
	Intro.cpp
	Level.cpp
	Level_1.cpp
	Particles.cpp
	SDLUtils.cpp
	Texture.cpp
	Timer.cpp
	Title.cpp
	Window.cpp
	main.cpp
)

set(
	arkilloid_LIBS
	arkilloid_fileio
	arkilloid_sound
	glftfont
	${OPENGL_LIBRARIES}
	${SDL_LIBRARY}
	${SDLIMAGE_LIBRARY}
	${SDLMIXER_LIBRARY}
	${SDLTTF_LIBRARY}
)

include_directories(
	${LIBFILEIO_INCLUDE_DIR}
	${LIBSOUND_INCLUDE_DIR}
)
add_executable(arkilloid ${arkilloid_SRCS})
target_link_libraries(arkilloid	${arkilloid_LIBS})
install(TARGETS arkilloid RUNTIME DESTINATION ${BINDIR})
