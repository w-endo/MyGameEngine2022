#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//�v���C���[���Ǘ�����N���X
class MiniOden : public GameObject
{
    Fbx* pFbx;
public:
    //�R���X�g���N�^
    MiniOden(GameObject* parent);

    //�f�X�g���N�^
    ~MiniOden();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};