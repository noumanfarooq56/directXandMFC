#pragma once
#include <xnamath.h>

#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <string>
// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

class CDirectXdrawing
{
public:
	//Global Declarations - Interfaces//
	IDXGISwapChain* SwapChain;
	ID3D11Device* d3d11Device;

	HRESULT hr;
	ID3D11DeviceContext* d3d11DevCon;
	ID3D11RenderTargetView* renderTargetView;
	///////////////**************new**************////////////////////
	ID3D11Buffer* squareIndexBuffer;
	ID3D11Buffer* squareVertBuffer;
	///////////////**************new**************////////////////////
	ID3D11VertexShader* VS;
	ID3D11PixelShader* PS;
	ID3D10Blob* VS_Buffer;
	ID3D10Blob* PS_Buffer;
	int vCount;
	ID3D11InputLayout* vertLayout;
	// function prototypes
	void InitD3D(HWND);    // sets up and initializes Direct3D
	void CleanD3D(void);        // closes Direct3D and releases memory
	void RenderFrame(void);     // renders a single frame
	void initScene(HWND);
	void DrawScene();

	CDirectXdrawing();
	~CDirectXdrawing();
};

