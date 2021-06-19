#include <cmath>
#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
using namespace std;
int a;
float width = 1000;
float height = 600;
double interval = 1.0/60;
float theta_z = 0.0f;
float spin_theta = 0.0f;
float x = 0.0f;
float y = 0.0f;
float z = 0.0f;
glm::mat4 view_z = glm::mat4(1.0f);
glm::mat4 trans = glm::mat4(1.0f);
glm::mat4 trans_x = glm::mat4(1.0f);
glm::mat4 trans_y = glm::mat4(1.0f);
glm::mat4 trans_z = glm::mat4(1.0f);
glm::mat4 spin =glm::mat4(1.0f);
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    const float Speed = 0.005f;
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        trans_x = glm::mat4(1.0f);
        x -= Speed;
        trans_x = glm::translate(trans_x, glm::vec3(x, 0.0f, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(x, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
        trans_x = glm::mat4(1.0f);
        x += Speed;
        trans_x = glm::translate(trans_x, glm::vec3(x, 0.0f, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(x, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
    {
        trans_y = glm::mat4(1.0f);
        y -= Speed;
        trans_y = glm::translate(trans_y, glm::vec3(0.0f, y, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, y, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
    {
        trans_y = glm::mat4(1.0f);
        y += Speed;
        trans_y = glm::translate(trans_y, glm::vec3(0.0f, y, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, y, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
        trans_z = glm::mat4(1.0f);
        z -= Speed;
        trans_z = glm::translate(trans_z, glm::vec3(0.0f, 0.0f, z));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, z),glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        trans_z = glm::mat4(1.0f);
        z += Speed;
        trans_z = glm::translate(trans_z, glm::vec3(0.0f, 0.0f, z));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, z),glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.8f, 0.0f, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.8f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
        trans_x = glm::mat4(1.0f);
        trans_y = glm::mat4(1.0f);
        trans_z = glm::mat4(1.0f);
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(-0.8f, 0.0f, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(-0.8f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
        trans_x = glm::mat4(1.0f);
        trans_y = glm::mat4(1.0f);
        trans_z = glm::mat4(1.0f);
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, 0.5f, 0.0f));
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.5f, 0.5f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
        trans_x = glm::mat4(1.0f);
        trans_y = glm::mat4(1.0f);
        trans_z = glm::mat4(1.0f);
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    if(glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        trans = glm::mat4(1.0f);
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
        trans_x = glm::mat4(1.0f);
        trans_y = glm::mat4(1.0f);
        trans_z = glm::mat4(1.0f);
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        trans_x = glm::mat4(1.0f);
        x += Speed;
        trans_x = glm::translate(trans_x, glm::vec3(x, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        trans_x = glm::mat4(1.0f);
        x -= Speed;
        trans_x = glm::translate(trans_x, glm::vec3(x, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        trans_y = glm::mat4(1.0f);
        y += Speed;
        trans_y = glm::translate(trans_y, glm::vec3(0.0f, y, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        trans_y = glm::mat4(1.0f);
        y -= Speed;
        trans_y = glm::translate(trans_y, glm::vec3(0.0f, y, 0.0f));
    } 
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        trans_z = glm::mat4(1.0f);
        z += Speed;
        trans_z = glm::translate(trans_z, glm::vec3(0.0f, 0.0f, z));
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        trans_z = glm::mat4(1.0f);
        z -= Speed;
        trans_z = glm::translate(trans_z, glm::vec3(0.0f, 0.0f, z));
    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        theta_z += 5;
        trans_x = glm::mat4(1.0f);
        trans_y = glm::mat4(1.0f);
        trans_z = glm::mat4(1.0f);
        trans = glm::mat4(1.0f);
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
        view_z[0][0] = cos(glm::radians(theta_z));
        view_z[0][1] = -sin(glm::radians(theta_z));
        view_z[1][0] = sin(glm::radians(theta_z));
        view_z[1][1] = cos(glm::radians(theta_z));
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        spin_theta += 5;
        float cam_x = sin(glm::radians(spin_theta));
        float cam_z = cos(glm::radians(spin_theta));
        spin = glm::lookAt(glm::vec3(cam_x, 0.0f, cam_z),glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
    }  
}

const char *vertexShaderSource ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "uniform mat4 view_z;\n"
    "uniform mat4 trans;\n"
    "uniform mat4 trans_x;\n"
    "uniform mat4 trans_y;\n"
    "uniform mat4 trans_z;\n"
    "uniform mat4 spin;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = spin*view_z*trans*trans_x*trans_y*trans_z*vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";

const char *vertexShaderSource1 ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "uniform mat4 view_z;\n"
    "uniform mat4 trans;\n"
    "uniform mat4 trans_x;\n"
    "uniform mat4 trans_y;\n"
    "uniform mat4 trans_z;\n"
    "uniform mat4 spin;\n"
    "out vec2 ourtex;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = spin*view_z*trans*trans_x*trans_y*trans_z*vec4(aPos, 1.0);\n"
    "   ourtex = aTexCoord;\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0f);\n"
    "}\n\0";

const char *fragmentShaderSource1 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 ourtex;\n"
    "uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    "   FragColor = texture(ourTexture, ourtex);\n"
    "}\n\0";

int main()
{
    while(1)
    {
        theta_z = 0.0f;
        view_z = glm::mat4(1.0f);
        trans = glm::mat4(1.0f);
        trans_x = glm::mat4(1.0f);
        trans_y = glm::mat4(1.0f);
        trans_z = glm::mat4(1.0f);
        spin_theta = 0.0f;
        spin = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f));
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        cout << "Enter 1 to see what client expected" << endl;
        cout << "Enter 2 to see what I imagined to make" << endl;
        cout << "Enter 3 to see what my code finally made :{" << endl;
        cout << "Enter 4 to say GOODBYE :}" << endl;
        cin >> a;
        if (a < 4 && a > 0)
        {
            // glfw: initialize and configure
            // how to handle the windows n all are done with this
            // ---------------
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            
            // glfw window creation
            // ----------------
            GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
            if (window == NULL)
            {
                cout << "Failed to create GLFW window" << endl;
                glfwTerminate();
                return -1;
            }
            glfwMakeContextCurrent(window);
            glewExperimental = GL_TRUE;
            GLenum err = glewInit();
            if (err != GLEW_OK) {
                cout << "Error: Failed to initialise GLEW : " << glewGetErrorString(err) << endl;
                exit (1);
            }
            glfwSwapInterval(1);

            /* --- register callbacks with GLFW --- */

            /* Register function to handle window resizes */
            /* With Retina display on Mac OS X GLFW's FramebufferSize
            is different from WindowSize */
            glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
            glfwSetWindowSizeCallback(window, framebuffer_size_callback);

            // /* Register function to handle window close */
            // glfwSetWindowCloseCallback(window, quit);

            // /* Register function to handle keyboard input */
            // glfwSetKeyCallback(window, keyboard);  // general keyboard input
            // glfwSetCharCallback(window, keyboardChar); // simpler specific character handling

            // /* Register function to handle mouse click */
            // glfwSetMouseButtonCallback(window, mouseButton); // mouse button clicks
            // glfwSetScrollCallback(window, scroll_callback);

            // vertex shader 
            unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
            if(a==2)
                glShaderSource(vertexShader, 1, &vertexShaderSource1, NULL);
            else
                glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertexShader);

            // checking the shader compile errors
            int success;
            char infoLog[512];
            glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

            // fragment shader
            unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            if (a==2)
                glShaderSource(fragmentShader, 1, &fragmentShaderSource1, NULL);
            else
                glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragmentShader);
            
            // check for shader compile errors
            glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

            // link shaders
            unsigned int shaderProgram = glCreateProgram();
            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glLinkProgram(shaderProgram);
            
            // check for linking errors
            glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
            }

            glUseProgram(shaderProgram);

            unsigned int VBO, VAO, EBO;
            glGenVertexArrays(1, &VAO);
            glBindVertexArray(VAO);

            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            unsigned int d;
            if (a == 1) 
            {
                float cos_36 = cos(glm::radians(36.0f));
                float sin_36 = sin(glm::radians(36.0f));
                float cos_72 = cos(glm::radians(72.0f));
                float sin_72 = sin(glm::radians(72.0f));
                float vertices[] = {
                    0.0f,         0.0f,         0.5f,  0.0f, 0.0f, 0.0f,  //0
                    0.5f,         0.0f,         0.5f,  0.0f, 0.0f, 0.5f,  //1
                    0.5f*cos_36,  0.5f*sin_36,  0.5f,  0.0f, 0.5f, 0.0f,  //2
                    0.5f*cos_72,  0.5f*sin_72,  0.5f,  0.0f, 0.5f, 0.5f,  //3
                    -0.5f*cos_72,  0.5f*sin_72,  0.5f,  0.5f, 0.0f, 0.0f,  //4
                    -0.5f*cos_36,  0.5f*sin_36,  0.5f,  0.5f, 0.0f, 0.5f,  //5
                    -0.5f,         0.0f,         0.5f,  0.5f, 0.5f, 0.0f,  //6
                    -0.5f*cos_36, -0.5f*sin_36,  0.5f,  0.5f, 0.5f, 0.5f,  //7
                    -0.5f*cos_72, -0.5f*sin_72,  0.5f,  0.0f, 0.0f, 1.0f,  //8
                    0.5f*cos_72, -0.5f*sin_72,  0.5f,  0.0f, 1.0f, 0.0f,  //9
                    0.5f*cos_36, -0.5f*sin_36,  0.5f,  0.0f, 1.0f, 1.0f,   //10

                    0.0f,         0.0f,        -0.5f,  1.0f, 0.0f, 0.0f,  //11
                    0.5f,         0.0f,        -0.5f,  1.0f, 0.0f, 1.0f,  //12
                    0.5f*cos_36,  0.5f*sin_36, -0.5f,  1.0f, 1.0f, 0.0f,  //13
                    0.5f*cos_72,  0.5f*sin_72, -0.5f,  1.0f, 1.0f, 1.0f,  //14
                    -0.5f*cos_72,  0.5f*sin_72, -0.5f,  0.0f, 0.5f, 1.0f,  //15
                    -0.5f*cos_36,  0.5f*sin_36, -0.5f,  0.0f, 1.0f, 0.5f,  //16
                    -0.5f,         0.0f,        -0.5f,  1.0f, 0.5f, 0.0f,  //17
                    -0.5f*cos_36, -0.5f*sin_36, -0.5f,  0.5f, 1.0f, 0.0f,  //18
                    -0.5f*cos_72, -0.5f*sin_72, -0.5f,  1.0f, 0.0f, 0.5f,  //19
                    0.5f*cos_72, -0.5f*sin_72, -0.5f,  0.5f, 0.0f, 1.0f,  //20
                    0.5f*cos_36, -0.5f*sin_36, -0.5f,  0.5f, 0.5f, 1.0f   //21
                };
                unsigned int indices[] = {
                    0, 1, 2,
                    0, 2, 3,
                    0, 3, 4,
                    0, 4, 5,
                    0, 5, 6,
                    0, 6, 7,
                    0, 7, 8,
                    0, 8, 9,
                    0, 9, 10,
                    0, 10, 1,

                    11, 12, 13,
                    11, 13, 14,
                    11, 14, 15,
                    11, 15, 16,
                    11, 16, 17,
                    11, 17, 18,
                    11, 18, 19,
                    11, 19, 20,
                    11, 20, 21,
                    11, 21, 12,

                    1,  2, 12,
                    13, 2, 12,
                    2,  3, 13, 
                    14, 3, 13,
                    3,  4, 14,
                    15, 4, 14,
                    4,  5, 15,
                    16, 5, 15,
                    5,  6, 16,
                    17, 6, 16,
                    6,  7, 17,
                    18, 7, 17,
                    7,  8, 18,
                    19, 8, 18,
                    8,  9, 19,
                    20, 9, 19,
                    9, 10, 20,
                    21,10, 20,
                    1 ,10, 12,
                    21,10, 12
                };
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
                // position attribute
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                // color attribute
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
                d = 3*40;
            }
            else if(a==2) {
                float cos_60 = cos(glm::radians(60.0f));
                float sin_60 = sin(glm::radians(60.0f));
                float vertices[] = {
                    0.0f,         0.0f,         0.5f, 0.0f, 1.0f,// 0.5f,  //0
                    0.5f,         0.0f,         0.0f, 0.0f, 0.5f,// 0.0f,  //1
                    0.5f*cos_60,  0.5f*sin_60,  0.0f, 1.0f, 0.0f, //0.5f,  //2
                   -0.5f*cos_60,  0.5f*sin_60,  0.0f, 1.0f, 1.0f, //0.0f,  //3
                   -0.5f,         0.0f,         0.0f, 0.5f, 0.5f, //0.0f,  //4
                   -0.5f*cos_60, -0.5f*sin_60,  0.0f, 0.5f, 0.0f,// 0.5f,  //5
                    0.5f*cos_60, -0.5f*sin_60,  0.0f, 0.5f, 1.0f,// 0.0f,  //6
                    0.0f,         0.0f,        -0.5f, 1.0f, 0.5f//, 0.5f   //7
                };
                unsigned int indices[] = {
                    0, 1, 2,
                    0, 2, 3,
                    0, 3, 4,
                    0, 4, 5,
                    0, 5, 6,
                    0, 6, 1,

                    7, 1, 2,
                    7, 2, 3,
                    7, 3, 4,
                    7, 4, 5,
                    7, 5, 6,
                    7, 6, 1
                };
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
                // position attribute
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                // color attribute
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
                d = 3*12;
                unsigned int texture;
                glGenTextures(1, &texture);
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
                glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
                // int w, h, nrChannels;
                // unsigned char *data = stbi_load("container.jpg", &w, &h,&nrChannels, 0);
                float pixels[] = {
                        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
                    };
                if (pixels)
                {
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB,GL_FLOAT, pixels);
                    glGenerateMipmap(GL_TEXTURE_2D);
                }
                else
                {
                    std::cout << "Failed to load texture" << std::endl;
                }
                // stbi_image_free(data);
            }
            else if (a==3) {
                float vertices[] = {
                    0.0f,  0.0f,  1.0f, 0.0f, 0.0f, 0.0f, //0
                    0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f, //1
                    0.5f, -0.5f,  0.5f, 0.0f, 0.5f, 0.0f, //2
                   -0.5f, -0.5f,  0.5f, 0.0f, 0.5f, 0.5f, //3
                   -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f, //4
                    0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.5f, //5
                    0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.0f, //6
                   -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, //7
                   -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, //8
                    0.0f,  0.0f, -1.0f, 0.0f, 0.0f, 1.0f  //9
                };
                unsigned int indices[] = {
                    0, 1, 2,
                    0, 2, 3,
                    0, 3, 4,
                    0, 4, 1,

                    1, 2, 6,
                    1, 5, 6,
                    7, 6, 2,
                    7, 3, 2,
                    8, 4, 3,
                    8, 7, 3,
                    1, 5, 8,
                    1, 4, 8,

                    9, 5, 6,
                    9, 6, 7,
                    9, 7, 8,
                    9, 8, 5
                };
                d = 3*16;
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
                // position attribute
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                // color attribute
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
            }
            double prev = 0;
            while(!glfwWindowShouldClose(window))
            {
                processInput(window);

                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT); 
                double cur = glfwGetTime();
                // if (cur - prev >=interval) {
                    int view_zLoc = glGetUniformLocation(shaderProgram, "view_z");
                    glUniformMatrix4fv(view_zLoc, 1, GL_FALSE, &view_z[0][0]);
                    int transLoc = glGetUniformLocation(shaderProgram, "trans");
                    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &trans[0][0]);
                    int trans_xLoc = glGetUniformLocation(shaderProgram, "trans_x");
                    glUniformMatrix4fv(trans_xLoc, 1, GL_FALSE, &trans_x[0][0]);
                    int trans_yLoc = glGetUniformLocation(shaderProgram, "trans_y");
                    glUniformMatrix4fv(trans_yLoc, 1, GL_FALSE, &trans_y[0][0]);
                    int trans_zLoc = glGetUniformLocation(shaderProgram, "trans_z");
                    glUniformMatrix4fv(trans_zLoc, 1, GL_FALSE, &trans_z[0][0]);
                    int spinLoc = glGetUniformLocation(shaderProgram, "spin");
                    glUniformMatrix4fv(spinLoc, 1, GL_FALSE, &spin[0][0]);
                    prev = cur;
                    glBindVertexArray(VAO);
                    glDrawElements(GL_TRIANGLES, d, GL_UNSIGNED_INT, 0);
                // }
                glfwSwapBuffers(window);
                glfwPollEvents();
            }
            // optional: de-allocate all resources once they've outlived their purpose:
            // ------------------------------------------------------------------------
            // deleting not used shaders
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
            glDeleteProgram(shaderProgram);

            glfwTerminate();
        }
        else 
        {
            break;
        }
    }
	return 0;
}