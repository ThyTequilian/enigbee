#ifndef enigmaEncoder
#define enigmaEncoder

#include <string>
#include <sstream>

#include "typeDefinitions.hpp"
#include "tl/expected.hpp"

#include "rotor.hpp"
#include "plugBoard.hpp"

class EnigmaEncoder {
public: 
	EnigmaEncoder();
	~EnigmaEncoder() {}

	auto encode(const MessageElement& elem)->tl::expected<MessageElement, ENIGERR>;
	auto encodeText(const Message& message)->tl::expected<Message, ENIGERR>;
	void setRotors(const RotorPosition &a, const RotorPosition& b, const RotorPosition& c);
	void resetRotors();

private:
	Rotor *r1;
	Rotor *r2;
	Rotor *r3;

	PlugBoard *returnRotor;

	RotorPosition pos1 = 0;
	RotorPosition pos2 = 0;
	RotorPosition pos3 = 0;

};

#endif