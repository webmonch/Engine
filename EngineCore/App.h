#pragma once

#include "LibHeader.h"
#include <Windows.h>

#include <GL/glew.h>
#include <GL/GL.h>
#include "SceneManager.h"
#include "GlRender.h"
#include "BaseMeshManager.h"
#include "LuaBinding.h"


class App
{
public:
	~App();

	static ENGINECORE_API int Start();
	static ENGINECORE_API void Init(HWND hwnd);

	static void Render();
	static void ExecuteLogic();

	//TODO(vlad): move this to external functions
public:
	//TODO(vlad): used to reload scripts when game is in GAME mode, not editor
	//static void ScheduleReload() { _reloadrRequired = true; }
	static void ReloadScene();

private:
	App();

	static void InitInternal();
	static void InitManagers();
	

private:
	static HWND				  _hwnd;
	static HDC				  _hdc;
	static SceneManager		* _sceneManager;
	static GlRender			* _renderer;
	static BaseMeshManager	* _meshManager;

	static bool				  _reloadrRequired;
};

