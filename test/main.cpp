#include <iostream>
#include <vk_api.h>

int main(int argc, char** argv) {
    auto result = volkInitialize();
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to initialize volk: " << result << std::endl;
        return -1;
    }

    uint32_t apiVersin = volkGetInstanceVersion();
    std::cout << "Vulkan API version: " << VK_API_VERSION_MAJOR(apiVersin) << "."
                                        << VK_API_VERSION_MINOR(apiVersin) << "."
                                        << VK_API_VERSION_PATCH(apiVersin) << std::endl;

    return 0;
}