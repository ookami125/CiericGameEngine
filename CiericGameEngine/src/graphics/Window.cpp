#include "Window.h"

namespace GameEngine::Graphics
{
	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
			m_Keys[i] = 0;
		for (int i = 0; i < MAX_BUTTONS; i++)
			m_MouseButtons[i] = 0;
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::isKeyPressed(uint32_t keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode]>0;
	}

	bool Window::isMouseButtonPressed(uint32_t button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button]>0;
	}

	void Window::getMousePosition(double & x, double & y) const
	{
		x = mx;
		y = my;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			cout << "Failed to initialize GLFW!" << endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			cout << "Failed to initialize window!" << endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_size_callback);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		glfwWindowHint(GLFW_DEPTH_BITS, 32);

		if (glewInit() != GLEW_OK)
		{
			cout << "Failed to initialize GLEW!" << endl;
			return false;
		}

		cout << "GL_VERSION: " << glGetString(GL_VERSION) << endl;
		
		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window)==GL_TRUE;
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glViewport(0, 0, m_Width, m_Height);
		glfwSwapBuffers(m_Window);
	}

	void window_size_callback(GLFWwindow *window, int width, int height)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Keys[key] = (action != GLFW_RELEASE);
	}

	void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = (action != GLFW_RELEASE);
	}

	void cursor_position_callback(GLFWwindow *window, double mx, double my)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = mx;
		win->my = my;
	}
};