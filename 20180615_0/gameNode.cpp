#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{

}

// 초기화 함수
HRESULT gameNode::init(void)  
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;
	
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	//매니져를 사용한다면
	if (_managerInit)
	{
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SOUNDMANAGER->init();
		EFFECTMANAGER->init();
		TXTDATA->init();
	}


	return S_OK;
}

//메모리 해제 함수
void gameNode::release(void)  
{

	if (_managerInit)
	{
		KillTimer(_hWnd, 1);
		KEYMANAGER->releaseSingleton();

		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();

		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();

		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();

		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();

		TXTDATA->release();
		TXTDATA->releaseSingleton();
	}
	//초기화해줄때 GetDC를 사용했으므로 DC해제해준다
	ReleaseDC(_hWnd, _hdc);
}

//연산
void gameNode::update(void)	  
{
	KEYMANAGER->update();
	SOUNDMANAGER->update();
}

//그리기
void gameNode::render(void)
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;		//조사 한 번 해보시요1
	

	switch (iMessage)
	{
	case WM_CREATE:
	{
		
	}
	break;
		//맨 처음 윈도우가 생성되면 딱 한 번 실행된다	
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
