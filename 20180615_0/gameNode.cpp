#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{

}

// �ʱ�ȭ �Լ�
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

	//�Ŵ����� ����Ѵٸ�
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

//�޸� ���� �Լ�
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
	//�ʱ�ȭ���ٶ� GetDC�� ��������Ƿ� DC�������ش�
	ReleaseDC(_hWnd, _hdc);
}

//����
void gameNode::update(void)	  
{
	KEYMANAGER->update();
	SOUNDMANAGER->update();
}

//�׸���
void gameNode::render(void)
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;		//���� �� �� �غ��ÿ�1
	

	switch (iMessage)
	{
	case WM_CREATE:
	{
		
	}
	break;
		//�� ó�� �����찡 �����Ǹ� �� �� �� ����ȴ�	
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