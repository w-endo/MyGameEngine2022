#pragma once

#include <list>
#include <string>
#include "Transform.h"
#include "Direct3D.h"

class SphereCollider;

class GameObject
{
	bool dead_;

protected:
	std::list<GameObject*> childList_;
	Transform		transform_;
	GameObject*		pParent_;
	std::string		objectName_;
	SphereCollider* pCollider_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	virtual ~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	void UpdateSub();
	virtual void Draw() = 0;
	void DrawSub();
	virtual void Release() = 0;
	void ReleaseSub();


	void KillMe();

	void SetPosition(XMFLOAT3 position);
	void SetPosition(float x, float y, float z);


	GameObject* FindChildObject(std::string objectName);
	GameObject* GetRootJob();
	GameObject* FindObject(std::string objectName);

	void AddCollider(SphereCollider* pCollider);
	void Collision(GameObject* pTarget);
	void RoundRobin(GameObject* pTarget);

	virtual void OnCollision(GameObject* pTarget) {}

	template <class T>
	GameObject* Instantiate(GameObject* parent)
	{
		T* p;
		p = new T(parent);
		p->Initialize();
		childList_.push_back(p);
		return p;
	}
};