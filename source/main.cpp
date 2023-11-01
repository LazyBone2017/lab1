#include "encryption/FES.h"
#include "encryption/Key.h"
#include "io/image_parser.h"

#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>

int main(int argc, char** argv) {
	auto lab_cli_app = CLI::App{ "" };

	auto image_path = std::filesystem::path{};
	auto file_option = lab_cli_app.add_option("--file", image_path);

	auto output_path = std::filesystem::path{};
	auto output_option = lab_cli_app.add_option("--output", output_path);

	file_option->check(CLI::ExistingFile);
	output_option->check(CLI::ExistingDirectory);

	CLI11_PARSE(lab_cli_app, argc, argv);

	auto bitmap_image = ImageParser::read_bitmap(image_path);

	auto key = FES::key_type{};
	for (auto i = FES::key_type::value_type(0); i < key.size(); i++) {
		key[i] = i;
	}

	auto encrypted_image = FES::encrypt(bitmap_image, key);
	
	ImageParser::write_bitmap(output_path / "encrypted_image.bmp", encrypted_image);

	return 0;
}
