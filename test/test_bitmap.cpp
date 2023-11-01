#include "test.h"

#include "image/bitmap_image.h"

#include <exception>

class BitmapTest : public LabTest {};

TEST_F(BitmapTest, test_one_d_one) {
}

TEST_F(BitmapTest, test_one_d_two) {
}

TEST_F(BitmapTest, test_one_e_one) {
	const auto picture_1_const = BitmapImage(1024, 1576);
	const auto picture_2_const = BitmapImage(8192, 8192);

	ASSERT_THROW(auto val = picture_1_const.get_pixel(1024, 1576), std::exception);
	ASSERT_THROW(auto val = picture_1_const.get_pixel(1576, 1024), std::exception);

	ASSERT_THROW(auto val = picture_1_const.get_pixel(1, 1576), std::exception);
	ASSERT_THROW(auto val = picture_1_const.get_pixel(1576, 1), std::exception);

	ASSERT_THROW(auto val = picture_1_const.get_pixel(8192, 8192), std::exception);
	ASSERT_THROW(auto val = picture_1_const.get_pixel(8192, 8192), std::exception);

	ASSERT_THROW(auto val = picture_2_const.get_pixel(1024, 8192), std::exception);
	ASSERT_THROW(auto val = picture_2_const.get_pixel(8192, 1024), std::exception);

	ASSERT_THROW(auto val = picture_2_const.get_pixel(1, 8192), std::exception);
	ASSERT_THROW(auto val = picture_2_const.get_pixel(8192, 1), std::exception);

	ASSERT_THROW(auto val = picture_2_const.get_pixel(8192, 8192), std::exception);
	ASSERT_THROW(auto val = picture_2_const.get_pixel(8192, 8192), std::exception);

	auto picture_1 = BitmapImage(1024, 1576);
	auto picture_2 = BitmapImage(8192, 8192);

	ASSERT_THROW(auto val = picture_1.get_pixel(1024, 1576), std::exception);
	ASSERT_THROW(auto val = picture_1.get_pixel(1576, 1024), std::exception);

	ASSERT_THROW(auto val = picture_1.get_pixel(1, 1576), std::exception);
	ASSERT_THROW(auto val = picture_1.get_pixel(1576, 1), std::exception);

	ASSERT_THROW(auto val = picture_1.get_pixel(8192, 8192), std::exception);
	ASSERT_THROW(auto val = picture_1.get_pixel(8192, 8192), std::exception);

	ASSERT_THROW(auto val = picture_2.get_pixel(1024, 8192), std::exception);
	ASSERT_THROW(auto val = picture_2.get_pixel(8192, 1024), std::exception);

	ASSERT_THROW(auto val = picture_2.get_pixel(1, 8192), std::exception);
	ASSERT_THROW(auto val = picture_2.get_pixel(8192, 1), std::exception);

	ASSERT_THROW(auto val = picture_2.get_pixel(8192, 8192), std::exception);
	ASSERT_THROW(auto val = picture_2.get_pixel(8192, 8192), std::exception);

	const auto pixel = Pixel<std::uint8_t>{ 126, 145, 199 };

	ASSERT_THROW(picture_1.set_pixel(1024, 1576, pixel), std::exception);
	ASSERT_THROW(picture_1.set_pixel(1576, 1024, pixel), std::exception);

	ASSERT_THROW(picture_1.set_pixel(1, 1576, pixel), std::exception);
	ASSERT_THROW(picture_1.set_pixel(1576, 1, pixel), std::exception);

	ASSERT_THROW(picture_1.set_pixel(8192, 8192, pixel), std::exception);
	ASSERT_THROW(picture_1.set_pixel(8192, 8192, pixel), std::exception);

	ASSERT_THROW(picture_2.set_pixel(1024, 8192, pixel), std::exception);
	ASSERT_THROW(picture_2.set_pixel(8192, 1024, pixel), std::exception);

	ASSERT_THROW(picture_2.set_pixel(1, 8192, pixel), std::exception);
	ASSERT_THROW(picture_2.set_pixel(8192, 1, pixel), std::exception);

	ASSERT_THROW(picture_2.set_pixel(8192, 8192, pixel), std::exception);
	ASSERT_THROW(picture_2.set_pixel(8192, 8192, pixel), std::exception);
}

TEST_F(BitmapTest, test_one_e_two) {
}

TEST_F(BitmapTest, test_one_f) {
}

