#include "rotor.hpp"

auto Rotor::encode(const MessageElement& element)->tl::expected<const MessageElement, ENIGERR> {
	//rotate();
	auto a = rotorBlade[element];
	auto b = a - L'a';
	auto c = b + rotorPosition;
	auto d = c % 26;
	MessageElement e = c + L'a';
	MessageElement ret = L'a' + (((rotorBlade[element] - L'a') + rotorPosition) % 26);
	rotate();
	return ret;
}

auto Rotor::encodeReverse(const MessageElement& element)->tl::expected<const MessageElement, ENIGERR> {
	auto val = ((reverseRotorBlade[element] - L'a') + rotorPosition);
	if (val < 0) {
		val = 26 - val;
	}
	MessageElement ret = L'a' + (val % 26);
	return  ret;
}

void Rotor::rotate(){
	if ((++rotationCounter) % rotationOffset == 0) {
		rotorPosition += 1;
		rotorPosition %= 26;
	}
}

void Rotor::setToRotorI() {
	for (auto elem = 'a'; elem <= 'z'; elem++)
		rotorBlade[L'a' + ((elem * 19) % 26)] = elem;

	setReverseRotorBlade();
}

void Rotor::setToRotorII() {
	for (auto elem = 'a'; elem <= 'z'; elem++)
		rotorBlade[L'a' + ((elem * 3) % 26)] = elem;

	setReverseRotorBlade();
}

void Rotor::setToRotorIII() {
	for (auto elem = 'a'; elem <= 'z'; elem++)
		rotorBlade[L'a' + ((elem * 5) % 26)] = elem;

	setReverseRotorBlade();
}

void Rotor::setReverseRotorBlade() {
	for (auto &elem : rotorBlade)
		reverseRotorBlade[elem.second] = elem.first;
}


void Rotor::resetRotor() {
	rotationOffset = rotationOffsetRoot;
	rotorPosition = rotorPositionRoot;
	rotationCounter = rotationCounterRoot;
}