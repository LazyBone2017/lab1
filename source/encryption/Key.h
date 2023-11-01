#pragma once

#include <array>
#include <cstdint>

class Key {
public:
	using key_type = std::array<std::uint8_t, 48>;
	
	[[nodiscard]] static key_type get_standard_key() noexcept;
};
