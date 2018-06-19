#pragma once
#include "gameNode.h"
#include "starScene.h"
#include "selectScene.h"

class playGround : public gameNode
{
private:
	gameNode* _currentScene;

	gameNode* _star;
	gameNode* _select;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	playGround();
	~playGround();
};

