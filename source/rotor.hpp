#ifndef rotor
#define rotor

#include <string>

#include "typeDefinitions.hpp"
#include "tl/expected.hpp"


class Rotor {
public: 
	Rotor() {}
	~Rotor() {}

	auto encode(MessageElement &element) -> tl::expected<int, MessageElement>;
	
	void setRotationOffset(int &x) { rotationOffset = (1+(x%25)); }
	int getRotationOffset() { return rotationOffset; }

private:
	RotorPosition rotorPosition;
	int rotationOffset;

	void rotate();

};

#endif