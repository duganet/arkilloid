class AudioSoundFX {
	private:
		Mix_Chunk* sound_chunk;
	public:
		AudioSoundFX(std::string filename);
		AudioSoundFX(){};
		~AudioSoundFX();
		void LoadFromFile(std::string filename);
		void Play();
};
