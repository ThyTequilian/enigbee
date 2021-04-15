#ifndef rotor
#define rotor

#include <string>
#include <unordered_map>

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
	auto encodeReverse(const MessageElement& element)->tl::expected<const MessageElement, ENIGERR>;
	
	void setRotationOffset(int &x) { rotationOffset = x%26; }
	void setRotorPosition(int &x) { rotorPosition = x%26; }
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
	
	std::unordered_map<MessageElement, MessageElement> rotorBlade;
	std::unordered_map<MessageElement, MessageElement> reverseRotorBlade;
};

#endif