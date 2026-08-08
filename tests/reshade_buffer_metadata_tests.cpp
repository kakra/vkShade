#include <catch2/catch_test_macros.hpp>

#include "runtime/reshade_buffer_metadata.hpp"

TEST_CASE("ReShade buffer bit depth follows the reference format semantics")
{
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_UNDEFINED) == 0);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_R5G6B5_UNORM_PACK16) == 5);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_R8G8B8A8_UNORM) == 8);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_A8B8G8R8_SRGB_PACK32) == 8);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32) == 9);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_A2B10G10R10_UNORM_PACK32) == 10);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_B10G11R11_UFLOAT_PACK32) == 11);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_R16G16B16A16_SFLOAT) == 16);
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_R32G32B32A32_SFLOAT) == 32);

    // ReShade does not classify the UNORM variant as a supported back-buffer
    // bit-depth format, despite its nominal 16 bits per component.
    CHECK(vkShade::get_reshade_buffer_color_bit_depth(VK_FORMAT_R16G16B16A16_UNORM) == 0);
}
