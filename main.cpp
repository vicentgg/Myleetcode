#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

//声明回调函数 
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// 键盘输入关闭GLFW
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//顶点着色器源码     该代码不是预编译  运行时动态编译
const char* vertexShaderSource = 
	"#version 330 core\n"
	"layout(location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";
//片段着色器源码
const char* fragmentShaderSource =
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n";


int main() {
	glfwInit(); // 初始化
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Opengl1", NULL, NULL);  //创建窗口

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);  //将当前窗口设置为上下文
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//注册回调函数

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {  //初始化GLAD 并将GLFW函数指针地址传入
		std::cout << "Faild to initialize GLAD" << std::endl;
		return -1;
	}



	//创建顶点着色器
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); //连接着色器源码
	glCompileShader(vertexShader);   //编译着色器源码

	//编译错误检查
	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //首先判断是否编译成功
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog); //获取错误信息
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
	}

	//创建片段着色器
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//编译错误检查
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infolog); 
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl;
	}

	//创建一个着色器程序
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	//将着色器链接到程序上
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//检测链接着色器程序是否失败
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		std::cout << "ERROR::SHADER::PROGREM::LINKED_FAILED\n" << infolog << std::endl;
	}
	//删除着色器程序
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


		
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   

	};

	unsigned int indices[] = { // 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	unsigned int VBO, EBO, VAO;
	glGenVertexArrays(1, &VAO); //生成一个顶点数组对象
	glGenBuffers(1, &VBO); //生成一个缓冲对象
	glGenBuffers(1, &EBO); 
	glBindVertexArray(VAO);   // 开始绑定

	/* 0.复制顶点数组到缓冲中 供opengl使用 */
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  //绑定顶点缓冲对象
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);  //绑定索引缓冲对象

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //将数据复制到当前绑定缓冲
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* 1. 设置顶点属性指针 */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  //解释顶点数据
	glEnableVertexAttribArray(0);  //启用顶点数据
	
	glBindBuffer(GL_ARRAY_BUFFER, 0); //解绑缓冲对象

	glBindVertexArray(0); //解绑顶点数组对象


	// render loop
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);  // 输入

		//渲染指令
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0 ,3);

		glfwSwapBuffers(window);  //颜色双缓冲 
		glfwPollEvents(); //检查触发事件
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);

	glfwTerminate(); // 释放资源
	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
