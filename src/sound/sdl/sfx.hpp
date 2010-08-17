#include <file.h>
#include <string>
#include <SDLUtils.h>
#include <SDL/SDL_mixer.h>

class SoundFX {
	private:
		Mix_Chunk* SoundChunk;
	public:
		SoundFX(std::string filename);
		void LoadFromFile(std::string filename);
		void Play();
};
