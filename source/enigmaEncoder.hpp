#ifndef enigmaEncoder
#define enigmaEncoder

#include <string>

#include "typeDefinitions.hpp"
#include "tl/expected.hpp"


class EnigmaEncoder {
public: 
	EnigmaEncoder() {}
	~EnigmaEncoder() {}

	auto encode(Message &text) -> tl::expected<int, Message>;

private:

};

#endif