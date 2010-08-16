find_package(OpenGL REQUIRED))
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(Freetype REQUIRED)

set (
	arkilloid_SRCS
	Ball.cpp
	Bita.cpp
	BonusControler.cpp
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
	file.cpp
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

add_executable (arkilloid
	${arkilloid_SRCS}
)
