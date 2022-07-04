#include "Bullet.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    hModel_ = Model::Load("Assets/oden.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
}

//更新
void Bullet::Update()
{
    transform_.position_.z += 0.5f;

    if (transform_.position_.z > 10)
    {
        KillMe();
    }

}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}