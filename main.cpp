#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow *window,int key,int scancode,int action,int mode){
    if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);
}

int main(){ 
    glfwInit();
    glfwDefaultWindowHints();
    GLFWwindow* window = glfwCreateWindow(1920,720,"OpenGL",nullptr,nullptr);
            if (window == nullptr){
        std::cout<<"failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

 //   glewExperimental=GL_TRUE;

    glfwSetKeyCallback(window,key_callback);

    if (glewInit()!= GLEW_OK){
        std::cout<<"Glew Failed to initialize\n";
        return -1;
    }

    glViewport(0,0,1920,720);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();

        glClearColor(0.9f,0.1f,0.9f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
