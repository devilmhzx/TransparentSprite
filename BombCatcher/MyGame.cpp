#include "MyDirectX.h"

const string APPTITLE = "Transparent Sprite Demo";
const int SCREENW = 800;
const int SCREENH = 600;
LPDIRECT3DTEXTURE9 explosion = NULL;
int frame = 0;
int starttime = 0;

bool Game_Init(HWND window)
{
	//初始化D3D
	if (!Direct3D_Intit(window, SCREENW, SCREENH, false))
	{
		MessageBox(window, "Error initializing Direct3D", "Error", 0);
		return false;
	}

	//初始化操作
	if (!DirectInput_Init(window))
	{
		MessageBox(window, "Error initializing DirectInput", "Error", 0);
		return false;
	}

	//加载贴图
	explosion = LoadTexture("Explosion.png");

	return true;
}

void Game_Run(HWND window)
{
	if (!d3ddev)
	{
		return;
	}

	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 100), 1.f, 0);

	if (d3ddev->BeginScene())
	{
		spriteobj->Begin(D3DXSPRITE_ALPHABLEND);
		Sprite_Animate(frame, 0, 29, 1, starttime, 30);
		Sprite_Draw_Frame(explosion, 144, 44, frame, 512, 512, 8);

		spriteobj->End();

		d3ddev->EndScene();
		d3ddev->Present(NULL, NULL, NULL, NULL);
	}
}

void Game_End()
{
	explosion->Release();

	DirectInput_Shutdown();
	Direct3D_Shutdown();
}

















