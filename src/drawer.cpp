
#include "drawer.h"


void Drawer::run()
{
    initVulkan();
    mainLoop();
    clean();
}


void Drawer::initVulkan()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(1000, 700, "Vulkan window", nullptr, nullptr);
}


void Drawer::mainLoop()
{
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}


void Drawer::clean()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

