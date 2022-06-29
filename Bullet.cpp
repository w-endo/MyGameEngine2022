#include "Bullet.h"
#include "Engine/Input.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet")
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
}

//更新
void Bullet::Update()
{
    transform_.position_.z += 0.5f;


}

//描画
void Bullet::Draw()
{
    pFbx->Draw(transform_);
}

//開放
void Bullet::Release()
{
}