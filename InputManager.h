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
	void setCurDownKey(WPARAM a_KeyInfo) { _curDownKey = a_KeyInfo; }
	void setCurUpKey(WPARAM a_KeyInfo) { _curUpKey = a_KeyInfo; }
	void setMousePosition(LPARAM a_MouseInfo) {
		_mouseX = LOWORD(a_MouseInfo);
		_mouseY = HIWORD(a_MouseInfo);
	}
	void setLButtonState(LButtonState a_State) { _lButtonState = a_State; }
	void setRButtonState(RButtonState a_State) { _rButtonState = a_State; }
	
	WPARAM getCurDownKey() { return _curDownKey; }
	WPARAM getCurUpKey() { return _curUpKey; }
	float getCurMouseX() { return _mouseX; }
	float getCurMouseY() { return _mouseY; }
	LButtonState getLButtonState() { return _lButtonState; }
	RButtonState getRButtonState() { return _rButtonState; }


	CInputManager();
	~CInputManager();
private:
	WPARAM _curDownKey;
	WPARAM _curUpKey;
	
	float _mouseX;
	float _mouseY;

	LButtonState _lButtonState;
	RButtonState _rButtonState;
};

