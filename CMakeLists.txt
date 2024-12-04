cmake_minimum_required(VERSION 3.16)
project(VisualData)

set(CMAKE_CXX_STANDART 17)
set(ENV{VULKAN_SDK} "D:/Application/VulkanSDK/1.3.296.0")
find_package(Vulkan REQUIRED)

add_subdirectory("libs/glfw/")

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(GLM_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/libs/glm")
set(GLFW_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include")

add_executable(${PROJECT_NAME} "${SRC}/main.cpp" "${SRC}/drawer.cpp")

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${GLM_HEADERS}
    ${GLFW_HEADERS}
    ${Vulkan_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES} glfw)
