#include "test.h"

#include "image/pixel.h"

#include <cstdint>

class PixelTest : public LabTest {};

TEST_F(PixelTest, test_one_a) {
}

TEST_F(PixelTest, test_one_b) {
}

TEST_F(PixelTest, test_one_c) {
	const auto pixel_small_1 = Pixel<std::uint8_t>{ 255, 255, 255 };
	const auto pixel_small_2 = Pixel<std::uint8_t>{ 255, 255, 0 };
	const auto pixel_small_3 = Pixel<std::uint8_t>{ 255, 0, 255 };
	const auto pixel_small_4 = Pixel<std::uint8_t>{ 0, 255, 255 };

	const auto pixel_small_1_copy = Pixel<std::uint8_t>{ 255, 255, 255 };

	ASSERT_TRUE(pixel_small_1 == pixel_small_1);
	ASSERT_TRUE(pixel_small_1_copy == pixel_small_1);
	ASSERT_TRUE(pixel_small_1 == pixel_small_1_copy);

	ASSERT_FALSE(pixel_small_1 == pixel_small_2);
	ASSERT_FALSE(pixel_small_1 == pixel_small_3);
	ASSERT_FALSE(pixel_small_1 == pixel_small_4);

	ASSERT_FALSE(pixel_small_2 == pixel_small_1);
	ASSERT_FALSE(pixel_small_3 == pixel_small_1);
	ASSERT_FALSE(pixel_small_4 == pixel_small_1);

	const auto pixel_large_1 = Pixel<std::uint32_t>{ 132, 24531658, 2365 };
	const auto pixel_large_2 = Pixel<std::uint32_t>{ 132, 24531658, 2364 };
	const auto pixel_large_3 = Pixel<std::uint32_t>{ 132, 245316580, 2365 };
	const auto pixel_large_4 = Pixel<std::uint32_t>{ 133, 24531658, 2365 };

	const auto pixel_large_1_copy = Pixel<std::uint32_t>{ 132, 24531658, 2365 };

	ASSERT_TRUE(pixel_large_1 == pixel_large_1);
	ASSERT_TRUE(pixel_large_1_copy == pixel_large_1);
	ASSERT_TRUE(pixel_large_1 == pixel_large_1_copy);

	ASSERT_FALSE(pixel_large_1 == pixel_large_2);
	ASSERT_FALSE(pixel_large_1 == pixel_large_3);
	ASSERT_FALSE(pixel_large_1 == pixel_large_4);

	ASSERT_FALSE(pixel_large_2 == pixel_large_1);
	ASSERT_FALSE(pixel_large_3 == pixel_large_1);
	ASSERT_FALSE(pixel_large_4 == pixel_large_1);
}
