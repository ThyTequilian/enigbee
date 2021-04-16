/**
* This Class handles the reagin of a configfile for a Virtuoso-Database
*
* @author Khun
* @version 1.0
*/

#include "enigmaEncoder.hpp"


EnigmaEncoder::EnigmaEncoder(){
	r1 = new Rotor(0, 1);
	r1->setToRotorI();
	r2 = new Rotor(0, 26);
	r2->setToRotorII();
	r3 = new Rotor(0, 26 * 26);
	r3->setToRotorIII();

	returnRotor = new PlugBoard();
	returnRotor->createBoard();
	returnRotor->returnBoard();

}


auto EnigmaEncoder::encode(const MessageElement& elem)->tl::expected<MessageElement, ENIGERR> {

	auto r1Do = [&](const MessageElement& elem) {
		return r1->encode(elem);
	};

	auto r2Do = [&](const MessageElement& elem) {
		return r2->encode(elem);
	};

	auto r3Do = [&](const MessageElement& elem) {
		return r3->encode(elem);
	};
	auto r1DoR = [&](const MessageElement& elem) {
		return r1->encodeReverse(elem);
	};

	auto r2DoR = [&](const MessageElement& elem) {
		return r2->encodeReverse(elem);
	};

	auto r3DoR = [&](const MessageElement& elem) {
		return r3->encodeReverse(elem);
	};

	auto returnDo = [&](const MessageElement& elem) {
		return returnRotor->encode(elem);
	};

	auto exceptionThrown = [](ENIGERR& err) {
		return tl::make_unexpected(err);
	};

	return r1Do(elem)
		.and_then(r2Do)
		.and_then(r3Do)
		.and_then(returnDo)
		.and_then(r3DoR)
		.and_then(r2DoR)
		.and_then(r1DoR);
}

auto EnigmaEncoder::encodeText(const Message& message)->tl::expected<Message, ENIGERR> {
	std::wstringstream wss;
	for (auto& elem : message) {
		wss << encode(elem).value();
	}
	auto out = wss.str();
	return out;
}


void EnigmaEncoder::setRotors(const RotorPosition& a, const RotorPosition& b, const RotorPosition& c) {
	pos1 = a%26;
	pos2 = b%26;
	pos3 = c%26;
	resetRotors();
}

void EnigmaEncoder::resetRotors() {
	r1->setRotorPosition(pos1);
	r2->setRotorPosition(pos2);
	r3->setRotorPosition(pos3);
}