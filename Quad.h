#pragma once
#include "Direct3D.h"
#include "Texture.h"
#include "Transform.h"

//�R���X�^���g�o�b�t�@�[
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;		//���[���h�E�r���[�E�v���W�F�N�V�����̍����s��
	XMMATRIX	matNormal;
};
//���_���
struct VERTEX
{
	XMVECTOR position;	//�ʒu
	XMVECTOR uv;		//UV
	XMVECTOR normal;	//�@��
};





//�l�p�`�|���S���i�O�p�`���Q���j��`�悷��N���X
class Quad
{
protected:	
	DWORD	vertexNum_;		//���_��
	VERTEX* vertices_;		//���_���
	ID3D11Buffer*	pVertexBuffer_;		//���_�o�b�t�@

	DWORD indexNum;			//�C���f�b�N�X��
	int*	index_;			//�C���f�b�N�X���
	ID3D11Buffer*	pIndexBuffer_;		//�C���f�b�N�X�o�b�t�@

	ID3D11Buffer*	pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture*		pTexture_;		//�e�N�X�`��


public:
	Quad();
	~Quad();

	//�������i�|���S����\�����邽�߂̊e����������j
	//�ߒl�F�����^���s
	HRESULT Initialize();

	//�`��
	//�����FworldMatrix	���[���h�s��
	void Draw(Transform& transform);

	//���
	void Release();



private:
	//---------Initialize����Ă΂��֐�---------
	virtual void InitVertexData();		//���_���̏���
	HRESULT CreateVertexBuffer();		//���_�o�b�t�@���쐬

	virtual void InitIndexData();		//�C���f�b�N�X��������
	HRESULT CreateIndexBuffer();		//�C���f�b�N�X�o�b�t�@���쐬

	HRESULT CreateConstantBuffer();		//�R���X�^���g�o�b�t�@�쐬
	
	HRESULT LoadTexture();				//�e�N�X�`�������[�h


	//---------Draw�֐�����Ă΂��֐�---------
	void PassDataToCB(Transform transform);	//�R���X�^���g�o�b�t�@�Ɋe�����n��
	void SetBufferToPipeline();							//�e�o�b�t�@���p�C�v���C���ɃZ�b�g
};