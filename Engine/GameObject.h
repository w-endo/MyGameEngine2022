#pragma once

#include <list>
#include <string>
#include "Transform.h"

class GameObject
{
	std::list<GameObject*> childList_;
	Transform		transform_;
	GameObject*		pParent_;
	std::string		objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
};