#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//�v���C���[���Ǘ�����N���X
class Bullet : public GameObject
{
    Fbx* pFbx;
    int hModel_;
public:
    //�R���X�g���N�^
    Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};