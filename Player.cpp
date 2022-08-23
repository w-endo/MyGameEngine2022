#include "Player.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "MiniOden.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.scale_.x = 0.5f;
    transform_.scale_.y = 0.5f;
    transform_.scale_.z = 0.5f;

    Instantiate<MiniOden>(this);
}

//�X�V
void Player::Update()
{
    transform_.rotate_.y++;

    if (Input::IsKey(DIK_LEFT))
    {
        transform_.position_.x -= 0.1f;
    }
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.position_.x += 0.1f;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        GameObject* pBullet = Instantiate<Bullet>(pParent_);
        pBullet->SetPosition(transform_.position_);

    }

    if (Input::IsKey(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TEST);
    }
}

//�`��
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void Player::Release()
{
}