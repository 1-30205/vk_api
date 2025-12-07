cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(vulkan_api VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)           # 将 C++ 标准设置为 C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # C++ 17 是强制要求，不会衰退至低版本
set(CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(
    vk_api
    STATIC
        src/vk_api.cpp
)

target_include_directories(
    vk_api
    PUBLIC
        include
)

find_package(VulkanHeaders CONFIG)
find_package(volk CONFIG REQUIRED)
find_package(VulkanMemoryAllocator CONFIG REQUIRED)

target_link_libraries(
    vk_api
    PUBLIC
        Vulkan::Headers
        volk::volk volk::volk_headers
        GPUOpen::VulkanMemoryAllocator
)

add_executable(
    vk_api_main
        test/main.cpp
)

target_link_libraries(
    vk_api_main
    PUBLIC
        vk_api
)