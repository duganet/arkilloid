#include <file.h>

class SoundFX {
	public:
		SoundFX(std::string filename);
		void LoadFromFile(std::string filename);
		void Play();
}
