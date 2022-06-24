#pragma once

#include <d3d11.h>
#include <assert.h>

#include <DirectXMath.h>

using namespace DirectX;

#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr;}
#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p != nullptr){ delete[] p; p = nullptr;}

//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

enum SHADER_TYPE
{
	SHADER_2D,
	SHADER_3D,
	SHADER_MAX
};


namespace Direct3D
{
	extern ID3D11Device* pDevice;				//�f�o�C�X
	extern ID3D11DeviceContext* pContext;		//�f�o�C�X�R���e�L�X�g


	//������
	HRESULT Initialize(int winW, int winH, HWND hWnd);

	//�V�F�[�_�[����
	HRESULT InitShader();
	HRESULT InitShader3D();
	HRESULT InitShader2D();

	void SetShader(SHADER_TYPE type);


	//�`��J�n
	void BeginDraw();

	//�`��I��
	void EndDraw();

	//���
	void Release();
};