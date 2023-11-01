#pragma once

#include "gtest/gtest.h"

#include <filesystem>

/**
 * @brief Get the path to the inputs
 *
 * @return std::filesystem::path path
 */
[[nodiscard]] std::filesystem::path get_path();

class LabTest : public ::testing::Test {

};
