#include "Enemy.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy")
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.position_.z = 20.0f;


    SphereCollider* collision = new SphereCollider(1.0f);
    AddCollider(collision);
}

//更新
void Enemy::Update()
{

}

//描画
void Enemy::Draw()
{
    pFbx->Draw(transform_);
}

//開放
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    KillMe();
    pTarget->KillMe();
}
