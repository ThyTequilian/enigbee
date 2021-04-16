#include "rotor.hpp"

auto Rotor::encode(const MessageElement& element)->tl::expected<const MessageElement, ENIGERR> {
	
	MessageElement elem = std::tolower(element);
	MessageElement in = elem - rotorPosition;
	while (in < L'a') {
		in += 26;
	}
	MessageElement out = rotorBlade[in];
	
	return out;
}

auto Rotor::encodeReverse(const MessageElement& elem)->tl::expected<const MessageElement, ENIGERR> {
	//MessageElement ret = reverseRotorBlade[L'a' + ((elem - L'a' + rotorPosition) % 26) - rotorPosition] - L'a' - rotorPosition;
	
	MessageElement out = reverseRotorBlade[elem] + rotorPosition;
	while (out > L'z') {
		out -= 26;
	}
	rotate();
	//MessageElement ret = def - rotorPosition + L'a';
	return  out;
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