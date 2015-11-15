#pragma once
#include <fmod.h>

class CSoundManager
{
public:
	bool Init();
	FMOD_SOUND* getFMOD_SOUND(const char* a_sFileName, bool repeat);
	void playSound(FMOD_SOUND* a_pSound);
	void stopSound();
	void Update();
	void Release();

	CSoundManager();
	~CSoundManager();

public:
	bool m_bIsSoundOn;

	FMOD_SYSTEM* m_pSoundSystem;
	FMOD_CHANNEL* m_pChannel;

};

