#include "all.h"

class vis {
	private:
		GLFWwindow* window;

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	public:
		vis() {
			if (!glfwInit()) {
			    std::cout << "Failed to init GLFW" << std::endl;
			    return;
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			this->window = glfwCreateWindow(800, 600, "TrainingVisualizer", NULL, NULL);
			if (window == NULL) {
			    std::cout << "Failed to create GLFW window" << std::endl;
			    glfwTerminate();
			    return;
			}
			glfwMakeContextCurrent(window);
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // dark gray background

			
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
			    std::cout << "Failed to initialize GLAD" << std::endl; 
			    return;
			}    

			glViewport(0, 0, 400, 400);

			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		}

		void update_window() {
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		int should_window_close() {
			return glfwWindowShouldClose(this->window);
		}
		
};

extern "C" {
	vis* init_vis() {
		return new vis();
	}

	void start_vis(vis* obj) {
		obj->update_window();
	}

	void vis_exit(vis* obj) {
		delete obj;
	}

	int vis_should_window_close(vis* obj) {
		return obj->should_window_close();
	}
}

