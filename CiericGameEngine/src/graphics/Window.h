#pragma once
#ifndef GL_GLEW
#define GL_GLEW
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

namespace GameEngine::Graphics
{

#define MAX_KEYS	1024
#define MAX_BUTTONS 7

	class Window
	{
	public: //Variables

	private: //Variables
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;

		int m_Keys[MAX_KEYS];
		int m_MouseButtons[MAX_BUTTONS];
		double mx, my;
	public: //Methods
		Window(const char *title, int width, int height);
		~Window();
		void clear() const;
		bool closed() const;
		void update();

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }
		bool isKeyPressed(uint32_t keycode) const;
		bool isMouseButtonPressed(uint32_t button) const;
		void getMousePosition(double &x, double &y) const;
	private: //Methods
		bool init();
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void window_size_callback(GLFWwindow *window, int width, int height);
		friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow *window, double mx, double my);
		//static void onResize(GLFWwindow *window, int width, int height);
	};

};

