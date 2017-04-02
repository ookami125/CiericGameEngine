#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

#include "src\graphics\Window.h"
#include "src\graphics\TextureManager.h"
#include "src\maths.h"
#include "src\graphics\Shader.h"
#include "src\world\Scene.h"
#include "src\world\Entity.h"
#include "src\world\components.h"

using namespace std;
using namespace GameEngine::Graphics;
using namespace GameEngine::Maths;
using namespace GameEngine::World;
using namespace GameEngine::World::Components;
using namespace std::chrono;

static const GLfloat triangle[] = {
	 0.5f, -0.5f,  -1.0f,		1.0f,  0.0f,
	-0.5f, -0.5f,  -1.0f,		0.0f,  0.0f,
	 0.5f,  0.5f,  -1.0f,		1.0f,  1.0f,
	-0.5f, -0.5f,  -1.0f,		0.0f,  0.0f,
	-0.5f,  0.5f,  -1.0f,		0.0f,  1.0f,
	 0.5f,  0.5f,  -1.0f,		1.0f,  1.0f,
};

int main(int argc, char** argv)
{
	Window window("Test window", 800, 600);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(0.0f);
	
	//FBO fb(800, 600);
	//fb.detach();

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	window.update();
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	ShaderProgram shader("res/default.vert", "res/default.frag");
	shader.Use();

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	//TextureManager* texManager = new TextureManager();
	TextureManager::Add(Texture::LoadFromFile("res/test.png"));
	TextureManager::Add(Texture::LoadFromFile("res/test2.png"));
	TextureManager::Add(Texture::LoadFromFile("res/test3.png"));

	Scene scene;
	Entity* ent = new Entity();
	ent->AddComponent(new TransformComponent(mat4::identity()));
	ent->AddComponent(new SpriteComponent(TextureManager::Get("test.png")));
	scene.Add(ent);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_GREATER);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);

	auto started = high_resolution_clock::now();
	while (!window.closed())
	{
		auto curr = std::chrono::high_resolution_clock::now();
		float secs = (float)(duration_cast<milliseconds>(curr - started).count()) / 1000.0f;
		//cout << secs << endl;
		
		window.clear();

		scene.OnUpdate();
		scene.OnRender();

		/*
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)0);
		glEnableVertexAttribArray(1); 
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(3 * sizeof(GLfloat)));

		mat4 MVP;
		MVP = mat4::perspective(87.0f, 800.0f / 600.0f, 1.0f, 1000.0f) * mat4::translation(vec3(0.0f, 0.0f, -2.0f)) * mat4::rotation((secs + 0) * 90, vec3(0.0f,1.0f,0.0f)) * mat4::translation(vec3(0.0f, 0.0f, -0.1f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Id, "MVP"), 1, GL_FALSE, (GLfloat*)&MVP);	 
		glUniform1i(glGetUniformLocation(shader.Id, "tex"), tex1);									 
		glDrawArrays(GL_TRIANGLES, 0, 6);															 

		MVP = mat4::perspective(87.0f, 800.0f / 600.0f, 1.0f, 1000.0f) * mat4::translation(vec3(0.0f, 0.0f, -2.0f)) * mat4::rotation((secs + 1) * 90, vec3(0.0f, 1.0f, 0.0f)) * mat4::translation(vec3(0.0f, 0.0f, -0.1f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Id, "MVP"), 1, GL_FALSE, (GLfloat*)&MVP);
		glUniform1i(glGetUniformLocation(shader.Id, "tex"), tex1);
		glDrawArrays(GL_TRIANGLES, 0, 6);
																									 
		MVP = mat4::perspective(87.0f, 800.0f / 600.0f, 1.0f, 1000.0f) * mat4::translation(vec3(0.0f, 0.0f, -2.0f)) * mat4::rotation((secs + 2) * 90, vec3(0.0f, 1.0f, 0.0f)) * mat4::translation(vec3(0.0f, 0.0f, -0.1f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Id, "MVP"), 1, GL_FALSE, (GLfloat*)&MVP);
		glUniform1i(glGetUniformLocation(shader.Id, "tex"), tex1);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		MVP = mat4::perspective(87, 800.0f / 600.0f, 1.0f, 1000.0f) * mat4::translation(vec3(0, 0, -2)) * mat4::rotation((secs + 3) * 90, vec3(0, 1, 0)) * mat4::translation(vec3(0, 0, -0.1));
		glUniformMatrix4fv(glGetUniformLocation(shader.Id, "MVP"), 1, GL_FALSE, (GLfloat*)&MVP);
		glUniform1i(glGetUniformLocation(shader.Id, "tex"), tex1);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		*/
		window.update();
	}
	glDisable(GL_TEXTURE_2D);
	
	return 0;
}