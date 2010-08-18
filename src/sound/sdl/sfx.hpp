class SoundFX {
	private:
		Mix_Chunk* sound_chunk;
	public:
		SoundFX(std::string filename);
		~SoundFX();
		void LoadFromFile(std::string filename);
		void Play();
};
