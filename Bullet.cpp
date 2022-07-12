#include "Bullet.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
    hModel_ = Model::Load("Assets/oden.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;

    SphereCollider* collision = new SphereCollider(1.0f);
    AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
    transform_.position_.z += 0.5f;

    if (transform_.position_.z > 50)
    {
        KillMe();
    }

}

//�`��
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}