#pragma once
#include "Shader.h"
#include "Camera.h"
#include "glm/glm.hpp"

struct GLFWwindow;

class Game
{
private:
	GLFWwindow* window;
	Shader* lightingShader;
	Shader* lampShader;

	Game();
	~Game();
public:
	void DrawVR(const float* view, const float* proj);

	bool Init();
	bool Shutdown();
	bool Frame();


	static Game* Instance();
};

