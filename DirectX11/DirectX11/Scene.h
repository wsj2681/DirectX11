#pragma once
#include "DX11Device.h"
#include "Camera.h"
#include "Model.h"

class Scene
{
public:
	Scene() = default;
	Scene(HWND hWnd);
	~Scene();

	void Render();
private:
	HWND hWnd;
	
	unique_ptr<DX11Device> device;
	unique_ptr<Camera> camera;
	Model* model = nullptr;

	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyBoardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool IsMouseOverModel(HWND hWnd, int mouseX, int mouseY);
	const LPWSTR& OpenFileDialog(HWND hWnd);

public:
	LRESULT OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
};

