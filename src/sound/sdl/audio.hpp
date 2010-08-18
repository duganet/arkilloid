class AudioEngine
{
	public:
		AudioEngine();
		~AudioEngine();
		//static int initted, mix_flags;
		static bool Start();
		static bool Stop();
};
