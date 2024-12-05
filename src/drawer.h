
#define GLFW_INCLUDE_VULKAN

#include <iostream>

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>


#ifdef NDEBUG
    const bool enableValidationLayers = false;
 #else
    const bool enableValidationLayers = true;
#endif


class Drawer
{
public:
    void run();

private:
    void initVulkan();
    void initWindow();
    void mainLoop();
    void clean();

    bool initValidation();

    GLFWwindow* window;
    VkInstance instance;
};

