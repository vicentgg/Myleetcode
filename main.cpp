#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

//�����ص����� 
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// ��������ر�GLFW
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//������ɫ��Դ��     �ô��벻��Ԥ����  ����ʱ��̬����
const char* vertexShaderSource = 
	"#version 330 core\n"
	"layout(location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";
//Ƭ����ɫ��Դ��
const char* fragmentShaderSource =
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n";


int main() {
	glfwInit(); // ��ʼ��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Opengl1", NULL, NULL);  //��������

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);  //����ǰ��������Ϊ������
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//ע��ص�����

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {  //��ʼ��GLAD ����GLFW����ָ���ַ����
		std::cout << "Faild to initialize GLAD" << std::endl;
		return -1;
	}



	//����������ɫ��
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); //������ɫ��Դ��
	glCompileShader(vertexShader);   //������ɫ��Դ��

	//���������
	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //�����ж��Ƿ����ɹ�
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog); //��ȡ������Ϣ
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
	}

	//����Ƭ����ɫ��
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//���������
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infolog); 
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl;
	}

	//����һ����ɫ������
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	//����ɫ�����ӵ�������
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//���������ɫ�������Ƿ�ʧ��
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		std::cout << "ERROR::SHADER::PROGREM::LINKED_FAILED\n" << infolog << std::endl;
	}
	//ɾ����ɫ������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


		
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   

	};

	unsigned int indices[] = { // ע��������0��ʼ! 
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};

	unsigned int VBO, EBO, VAO;
	glGenVertexArrays(1, &VAO); //����һ�������������
	glGenBuffers(1, &VBO); //����һ���������
	glGenBuffers(1, &EBO); 
	glBindVertexArray(VAO);   // ��ʼ��

	/* 0.���ƶ������鵽������ ��openglʹ�� */
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  //�󶨶��㻺�����
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);  //�������������

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //�����ݸ��Ƶ���ǰ�󶨻���
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* 1. ���ö�������ָ�� */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  //���Ͷ�������
	glEnableVertexAttribArray(0);  //���ö�������
	
	glBindBuffer(GL_ARRAY_BUFFER, 0); //��󻺳����

	glBindVertexArray(0); //��󶥵��������


	// render loop
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);  // ����

		//��Ⱦָ��
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0 ,3);

		glfwSwapBuffers(window);  //��ɫ˫���� 
		glfwPollEvents(); //��鴥���¼�
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);

	glfwTerminate(); // �ͷ���Դ
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
