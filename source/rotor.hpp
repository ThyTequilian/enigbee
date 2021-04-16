#ifndef rotor
#define rotor

#include <string>
#include <map>

#include "typeDefinitions.hpp"
#include "tl/expected.hpp"

class Rotor {
public: 
	Rotor(const int &rotorPos, const int& rotOffset) {
		rotationOffset = rotOffset;
		rotorPosition = rotorPos % 26;
		rotationCounter = 0;

		//setting Root-Values
		rotationOffsetRoot = rotationOffset;
		rotorPositionRoot = rotorPosition;
		rotationCounterRoot = rotationCounter;
	}

	~Rotor() {}

	auto encode(const MessageElement &element) -> tl::expected<const MessageElement, ENIGERR>;
	auto encodeNoRotate(const MessageElement &element) -> tl::expected<const MessageElement, ENIGERR>;
	auto encodeReverse(const MessageElement& element)->tl::expected<const MessageElement, ENIGERR>;
	
	void setRotationOffset(int &x) { rotationOffset = x%26; }
	void setRotorPosition(const RotorPosition &x) { rotorPosition = x%26; }
	void setToRotorI();
	void setToRotorII();
	void setToRotorIII();

	void resetRotor();

private:
	int rotorPosition;
	int rotorPositionRoot;
	int rotationOffset;
	int rotationOffsetRoot;
	int rotationCounter;
	int rotationCounterRoot;

	void rotate();
	void setReverseRotorBlade();
	
	std::map<MessageElement, MessageElement> rotorBlade;
	std::map<MessageElement, MessageElement> reverseRotorBlade;
};

#endif