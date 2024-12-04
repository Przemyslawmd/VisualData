
#define GLFW_INCLUDE_VULKAN

#include <iostream>

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

class Drawer
{
public:
    void run();

private:
    void initVulkan();
    void mainLoop();
    void clean();

    GLFWwindow* window;
};

