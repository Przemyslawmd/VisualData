
#include "drawer.h"


void Drawer::run()
{
    
    initWindow();
    initVulkan();
    mainLoop();
    clean();
}


void Drawer::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(1000, 700, "Vulkan window", nullptr, nullptr);
}


void Drawer::initVulkan()
{
   VkApplicationInfo appInfo{};
   appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
   appInfo.pApplicationName = "Test";
   appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
   appInfo.pEngineName = "No Engine";
   appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
   appInfo.apiVersion = VK_API_VERSION_1_0;

   VkInstanceCreateInfo createInfo{};
   createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
   createInfo.pApplicationInfo = &appInfo;

   uint32_t glfwExtensionCount = 0;
   const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
   createInfo.enabledExtensionCount = glfwExtensionCount;
   createInfo.ppEnabledExtensionNames = glfwExtensions;

   createInfo.enabledLayerCount = 0;

   VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
   if (result != VK_SUCCESS) {
        throw std::runtime_error("Create Vulkan instance - fail");
   }
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

