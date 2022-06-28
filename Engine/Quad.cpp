#include "Quad.h"
#include "Camera.h"


//コンストラクタ
Quad::Quad(): 
	vertexNum_(0),	vertices_(nullptr),	pVertexBuffer_(nullptr),
	indexNum(0), index_(nullptr), pIndexBuffer_(nullptr),
	pConstantBuffer_(nullptr),
	pTexture_(nullptr)
{
}

//デストラクタ
Quad::~Quad()
{
	Release();
}

//初期化
HRESULT Quad::Initialize()
{
	//頂点情報
	InitVertexData();					//データを用意して
	if (FAILED(CreateVertexBuffer()))	//頂点バッファ作成
	{
		return E_FAIL;
	}

	//インデックス情報
	InitIndexData();					//データを用意して
	if (FAILED(CreateIndexBuffer()))	//インデックスバッファ作成
	{
		return E_FAIL;
	}

	//コンスタントバッファ作成
	if (FAILED(CreateConstantBuffer()))
	{
		return E_FAIL;
	}

	//テクスチャのロード
	if (FAILED(LoadTexture()))
	{
		return E_FAIL;
	}

	return S_OK;
}


//描画
void Quad::Draw(Transform& transform)
{
	Direct3D::SetShader(SHADER_3D);

	//コンスタントバッファに情報を渡す
	PassDataToCB(transform);

	//頂点バッファ、インデックスバッファ、コンスタントバッファをパイプラインにセット
	SetBufferToPipeline();

	//描画
	Direct3D::pContext->DrawIndexed(indexNum, 0, 0);
}

//解放
void Quad::Release()
{
	SAFE_DELETE_ARRAY(vertices_);
	SAFE_DELETE_ARRAY(index_);
	SAFE_DELETE(pTexture_);
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}














///////////////ここからはprivate関数///////////////

//頂点情報の準備
void Quad::InitVertexData()
{
	// 頂点情報
	VERTEX vertices[] =
	{
		XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f),// 四角形の頂点（左上）
		XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),  XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）
		XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),  XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f),// 四角形の頂点（右下）
		XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）		
	};

	//頂点の数
	vertexNum_ = sizeof(vertices) / sizeof(VERTEX);	//全データのサイズ　÷　1頂点分のサイズ　＝　頂点数

	//メンバ変数へコピー
	vertices_ = new VERTEX[vertexNum_];				//必要なサイズの配列にして
	memcpy(vertices_, vertices, sizeof(vertices));	//コピー
}

//頂点バッファを作成
HRESULT Quad::CreateVertexBuffer()
{
	HRESULT hr;
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices_;
	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"頂点バッファの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}
	return S_OK;
}

//インデックス情報を準備
void Quad::InitIndexData()
{
	int index[] = { 0,2,3, 0,1,2 };

	//インデックス数
	indexNum = sizeof(index) / sizeof(int);

	//メンバ変数へコピー
	index_ = new int[indexNum];
	memcpy(index_, index, sizeof(index));
}

//インデックスバッファを作成
HRESULT Quad::CreateIndexBuffer()
{
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(int) * indexNum;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index_;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;

	HRESULT hr;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"インデックスバッファの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}
	return S_OK;
}

//コンスタントバッファ作成
HRESULT Quad::CreateConstantBuffer()
{
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// コンスタントバッファの作成
	HRESULT hr;
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"コンスタントバッファの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}
	return S_OK;
}

//テクスチャをロード
HRESULT Quad::LoadTexture()
{
	pTexture_ = new Texture;

	HRESULT hr;
	hr = pTexture_->Load(L"Assets\\Dice.png");
	if (FAILED(hr))
	{
		MessageBox(NULL, L"テクスチャの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}
	return S_OK;
}

//コンスタントバッファに各種情報を渡す
void Quad::PassDataToCB(Transform transform)
{
	transform.Calclation();
	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(transform.GetWorldMatrix() * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	cb.matNormal = XMMatrixTranspose(transform.GetNormalMatrix());


	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// データを値を送る

	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);

	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);

	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
}

//各バッファをパイプラインにセット
void Quad::SetBufferToPipeline()
{
	//頂点バッファ
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// インデックスバッファーをセット
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//コンスタントバッファ
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
}

