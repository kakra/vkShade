#include "reshade_buffer_metadata.hpp"

uint32_t vkShade::get_reshade_buffer_color_bit_depth(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_R5G6B5_UNORM_PACK16:
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
            return 5;
        case VK_FORMAT_R8G8B8A8_UNORM:
        case VK_FORMAT_R8G8B8A8_SRGB:
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        case VK_FORMAT_B8G8R8A8_UNORM:
        case VK_FORMAT_B8G8R8A8_SRGB:
            return 8;
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
            return 9;
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return 10;
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return 11;
        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return 16;
        case VK_FORMAT_R32G32B32_SFLOAT:
        case VK_FORMAT_R32G32B32A32_SFLOAT:
            return 32;
        default:
            return 0;
    }
}
