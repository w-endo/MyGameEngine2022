#include "Dice.h"

//���_���̏���
void Dice::InitVertexData()
{
	// ���_���
	VERTEX vertices[] =
	{
		//�O(1)
		{ XMVectorSet(-1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, -1.0f, 0.0f)},	// 0
		{ XMVectorSet(1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, -1.0f, 0.0f)},	// 1
		{ XMVectorSet(1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, -1.0f, 0.0f)},	// 2
		{ XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f , 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, -1.0f, 0.0f)},	// 3

		//�E(2)
		{ XMVectorSet(1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f),	XMVectorSet(1.0f , 0.0f, 0.0f, 0.0f)},	// 4
		{ XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),		XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f),	XMVectorSet(1.0f , 0.0f, 0.0f, 0.0f)},	// 5
		{ XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),		XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(1.0f , 0.0f, 0.0f, 0.0f)},	// 6
		{ XMVectorSet(1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(1.0f , 0.0f, 0.0f, 0.0f)},	// 7

		//��(3)
		{ XMVectorSet(-1.0f,  1.0f,  1.0f, 0.0f),	XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f),	XMVectorSet(-1.0f , 0.0f, 0.0f, 0.0f)},	// 8
		{ XMVectorSet(-1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f),	XMVectorSet(-1.0f , 0.0f, 0.0f, 0.0f)},	// 9
		{ XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f),	XMVectorSet(-1.0f , 0.0f, 0.0f, 0.0f)},	// 10
		{ XMVectorSet(-1.0f, -1.0f,  1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(-1.0f , 0.0f, 0.0f, 0.0f)},	// 11

		//��(4)
		{ XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),		XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, 1.0f, 0.0f)},	// 12
		{ XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, 1.0f, 0.0f)}, 	// 13
		{ XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(1.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, 1.0f, 0.0f)},	// 14
		{ XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),		XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , 0.0f, 1.0f, 0.0f)},// 15

		//��(5)
		{ XMVectorSet(-1.0f, 1.0f,  1.0f, 0.0f),	XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , 1.0f, 0.0f, 0.0f)},	// 16
		{ XMVectorSet(1.0f, 1.0f,  1.0f, 0.0f),		XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , 1.0f, 0.0f, 0.0f)},  // 17
		{ XMVectorSet(1.0f, 1.0f, -1.0f, 0.0f),		XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , 1.0f, 0.0f, 0.0f)},  // 18
		{ XMVectorSet(-1.0f, 1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , 1.0f, 0.0f, 0.0f)},	// 19

		//��(6)
		{ XMVectorSet(-1.0f, -1.0f,  -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , -1.0f, 0.0f, 0.0f)},  // 20
		{ XMVectorSet(1.0f, -1.0f,  -1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f , -1.0f, 0.0f, 0.0f)},	// 21
		{ XMVectorSet(1.0f, -1.0f,   1.0f, 0.0f),	XMVectorSet(0.5f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , -1.0f, 0.0f, 0.0f)},	// 22
		{ XMVectorSet(-1.0f, -1.0f,   1.0f, 0.0f),	XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f , -1.0f, 0.0f, 0.0f)},  // 23
	};

	//���_�̐�
	vertexNum_ = sizeof(vertices) / sizeof(VERTEX);	//�S�f�[�^�̃T�C�Y�@���@1���_���̃T�C�Y�@���@���_��

	//�����o�ϐ��փR�s�[
	vertices_ = new VERTEX[vertexNum_];				//�K�v�ȃT�C�Y�̔z��ɂ���
	memcpy(vertices_, vertices, sizeof(vertices));	//�R�s�[
}


//�C���f�b�N�X��������
void Dice::InitIndexData()
{
	int index[] = { 0,1,2, 0,2,3, 4,5,6, 4,6,7, 8,9,10, 8,10,11, 12,13,14, 12,14,15, 16,17,18, 16,18,19, 20,21,22, 20,22,23, };

	//�C���f�b�N�X��
	indexNum = sizeof(index) / sizeof(int);

	//�����o�ϐ��փR�s�[
	index_ = new int[indexNum];
	memcpy(index_, index, sizeof(index));
}
