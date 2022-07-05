#pragma once
#include "GameObject.h"
class SceneManager :public GameObject
{
public:
	SceneManager(GameObject* parent);
	~SceneManager();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

