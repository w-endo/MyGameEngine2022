#pragma once
#include "Direct3D.h"
#include "Texture.h"
#include "Transform.h"

//コンスタントバッファー
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;		//ワールド・ビュー・プロジェクションの合成行列
	XMMATRIX	matNormal;
};
//頂点情報
struct VERTEX
{
	XMVECTOR position;	//位置
	XMVECTOR uv;		//UV
	XMVECTOR normal;	//法線
};





//四角形ポリゴン（三角形を２枚）を描画するクラス
class Quad
{
protected:	
	DWORD	vertexNum_;		//頂点数
	VERTEX* vertices_;		//頂点情報
	ID3D11Buffer*	pVertexBuffer_;		//頂点バッファ

	DWORD indexNum;			//インデックス数
	int*	index_;			//インデックス情報
	ID3D11Buffer*	pIndexBuffer_;		//インデックスバッファ

	ID3D11Buffer*	pConstantBuffer_;	//コンスタントバッファ

	Texture*		pTexture_;		//テクスチャ


public:
	Quad();
	~Quad();

	//初期化（ポリゴンを表示するための各種情報を準備）
	//戻値：成功／失敗
	HRESULT Initialize();

	//描画
	//引数：worldMatrix	ワールド行列
	void Draw(Transform& transform);

	//解放
	void Release();



private:
	//---------Initializeから呼ばれる関数---------
	virtual void InitVertexData();		//頂点情報の準備
	HRESULT CreateVertexBuffer();		//頂点バッファを作成

	virtual void InitIndexData();		//インデックス情報を準備
	HRESULT CreateIndexBuffer();		//インデックスバッファを作成

	HRESULT CreateConstantBuffer();		//コンスタントバッファ作成
	
	HRESULT LoadTexture();				//テクスチャをロード


	//---------Draw関数から呼ばれる関数---------
	void PassDataToCB(Transform transform);	//コンスタントバッファに各種情報を渡す
	void SetBufferToPipeline();							//各バッファをパイプラインにセット
};