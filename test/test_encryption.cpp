#include "test.h"

#include "encryption/FES.h"
#include "image/pixel.h"

#include <type_traits>

class EncryptionTest : public LabTest {};

TEST_F(EncryptionTest, test_three_a) {
	using expected_key_type = Key::key_type;
	using implemented_key_type = FES::key_type;

	using expected_row_type = std::array<BitmapImage::BitmapPixel, 16>;
	using implemented_row_type = FES::row_type;

	using expected_block_type = std::array<std::array<expected_row_type, 3>, 3>;
	using implemented_block_type = FES::block_type;

	static_assert(std::is_same<expected_key_type, implemented_key_type>::value);
	static_assert(std::is_same<expected_row_type, implemented_row_type>::value);
	static_assert(std::is_same<expected_block_type, implemented_block_type>::value);
}

TEST_F(EncryptionTest, test_three_b) {
}

TEST_F(EncryptionTest, test_three_c) {
}

TEST_F(EncryptionTest, test_three_d_one) {
	auto zero_block_1 = FES::block_type{};
	auto zero_block_2 = FES::block_type{};

	auto full_block_1 = FES::block_type{};
	auto full_block_2 = FES::block_type{};

	for (auto& half_block : full_block_1) {
		for (auto& row : half_block) {
			for (auto& pixel : row) {
				pixel = { 255, 255, 255 };
			}
		}
	}

	for (auto& half_block : full_block_2) {
		for (auto& row : half_block) {
			for (auto& pixel : row) {
				pixel = { 255, 255, 255 };
			}
		}
	}

	const auto encrypted_zero_zero = FES::encrypt_block(zero_block_1, zero_block_2);
	ASSERT_EQ(encrypted_zero_zero, zero_block_1);

	const auto encrypted_zero_full = FES::encrypt_block(zero_block_1, full_block_1);
	ASSERT_EQ(encrypted_zero_full[0][0], full_block_1[0][0]);
	ASSERT_EQ(encrypted_zero_full[0][1], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_zero_full[0][2], zero_block_1[0][0]);

	ASSERT_EQ(encrypted_zero_full[1][0], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_zero_full[1][1], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_zero_full[1][2], zero_block_1[0][0]);

	ASSERT_EQ(encrypted_zero_full[2][0], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_zero_full[2][1], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_zero_full[2][2], zero_block_1[0][0]);

	const auto encrypted_full_zero = FES::encrypt_block(full_block_1, zero_block_1);
	ASSERT_EQ(encrypted_full_zero[0][0], full_block_1[0][0]);
	ASSERT_EQ(encrypted_full_zero[0][1], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_full_zero[0][2], zero_block_1[0][0]);

	ASSERT_EQ(encrypted_full_zero[1][0], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_full_zero[1][1], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_full_zero[1][2], zero_block_1[0][0]);

	ASSERT_EQ(encrypted_full_zero[2][0], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_full_zero[2][1], zero_block_1[0][0]);
	ASSERT_EQ(encrypted_full_zero[2][2], zero_block_1[0][0]);

	const auto encrypted_full_full = FES::encrypt_block(full_block_1, full_block_2);
	ASSERT_EQ(encrypted_full_full, zero_block_1);
}

TEST_F(EncryptionTest, test_three_d_two) {
}

TEST_F(EncryptionTest, test_three_d_three) {
}

TEST_F(EncryptionTest, test_three_e_one) {
}

TEST_F(EncryptionTest, test_three_e_two) {
}
