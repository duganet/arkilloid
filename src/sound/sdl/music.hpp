class AudioMusic {
	private:
		Mix_Music* music;
	public:
		AudioMusic(std::string filename);
		~AudioMusic();
		void Play();
};
