#pragma once
#include <Windows.h>

enum class LButtonState
{
	DBClick,
	Down,
	Up,
	Idle,
};
enum class RButtonState
{
	DBClick,
	Down,
	Up,
	Idle,
};

class CInputManager
{
public:
	void setCurDownKey(WPARAM a_KeyInfo) { m_CurDownKey = a_KeyInfo; }
	void setCurUpKey(WPARAM a_KeyInfo) { m_CurUpKey = a_KeyInfo; }
	void setMousePosition(LPARAM a_MouseInfo) {
		m_fMouseX = LOWORD(a_MouseInfo);
		m_fMouseY = HIWORD(a_MouseInfo);
	}
	void setLButtonState(LButtonState a_State) { m_eLButtonState = a_State; }
	void setRButtonState(RButtonState a_State) { m_eRButtonState = a_State; }
	
	WPARAM getCurDownKey() { return m_CurDownKey; }
	WPARAM getCurUpKey() { return m_CurUpKey; }
	float getCurMouseX() { return m_fMouseX; }
	float getCurMouseY() { return m_fMouseY; }
	LButtonState getLButtonState() { return m_eLButtonState; }
	RButtonState getRButtonState() { return m_eRButtonState; }


	CInputManager();
	~CInputManager();
private:
	WPARAM m_CurDownKey;
	WPARAM m_CurUpKey;
	
	float m_fMouseX;
	float m_fMouseY;

	LButtonState m_eLButtonState;
	RButtonState m_eRButtonState;
};

