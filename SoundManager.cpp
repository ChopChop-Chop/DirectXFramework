#include "SoundManager.h"
#include <Windows.h>

CSoundManager::CSoundManager()
{
	m_bIsSoundOn = false;
}


CSoundManager::~CSoundManager()
{
}

bool CSoundManager::Init()
{
	FMOD_System_Create(&m_pSoundSystem);
	FMOD_System_Init(m_pSoundSystem, 1, FMOD_INIT_NORMAL, NULL);

	return true;
}
FMOD_SOUND* CSoundManager::getFMOD_SOUND(const char* a_sFileName, bool repeat)
{
	FMOD_SOUND* temp;
	if (repeat)
	{
		FMOD_System_CreateSound(m_pSoundSystem, a_sFileName, FMOD_LOOP_NORMAL, 0, &temp);
	}
	else
	{
		FMOD_System_CreateSound(m_pSoundSystem, a_sFileName, FMOD_DEFAULT, 0, &temp);
	}

	return temp;
}
void CSoundManager::playSound(FMOD_SOUND* a_pSound)
{
	FMOD_System_PlaySound(m_pSoundSystem, FMOD_CHANNEL_FREE, a_pSound, 0, &m_pChannel);
	m_bIsSoundOn = true;
}
void CSoundManager::stopSound()
{
	FMOD_Channel_Stop(m_pChannel);
	m_bIsSoundOn = false;
}
void CSoundManager::Update()
{
	if (m_bIsSoundOn)
	{
		FMOD_System_Update(m_pSoundSystem);
	}
}
void CSoundManager::Release()
{
	FMOD_System_Close(m_pSoundSystem);
	FMOD_System_Release(m_pSoundSystem);
}