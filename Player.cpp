#include "Player.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");
}

//更新
void Player::Update()
{
    transform_.rotate_.y++;
}

//描画
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//開放
void Player::Release()
{
}