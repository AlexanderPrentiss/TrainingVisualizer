#include "vis.hpp"

class vis {
	private:
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	public:
		GLFWwindow* window;
		int window_failed {0};
		int glad_failed {0};
		int glfw_failed {0};

		vis() {
			if (!glfwInit()) {
			    std::cout << "Failed to init GLFW" << std::endl;
			    this->glfw_failed = 1;
			    return;
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			this->window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
			if (window == NULL) {
			    std::cout << "Failed to create GLFW window" << std::endl;
			    this->glad_failed = 1;
			    glfwTerminate();
			    return;
			}
			glfwMakeContextCurrent(window);

			
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
			    std::cout << "Failed to initialize GLAD" << std::endl; 
			    this->glad_failed = 1;
			    return;
			}    

			glViewport(0, 0, 400, 400);

			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		}

		void open_window() {
			while(!glfwWindowShouldClose(this->window)) {
				glfwSwapBuffers(window);
				glfwPollEvents();
			}
		}

		int is_glad_failed() {
			return this->glad_failed;
		}

		int is_window_failed() {
			return this->window_failed;
		}
		
};

extern "C" {
	vis* init_vis() {
		return new vis();
	}

	void start_vis(vis* obj) {
		obj->open_window();
	}
}

