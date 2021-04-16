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

	auto ret = r1Do(elem)
		.and_then(r2Do)
		.and_then(r3Do)
		.and_then(returnDo)
		.and_then(r3DoR)
		.and_then(r2DoR)
		.and_then(r1DoR);

	return ret.value();
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
	r1->setRotorPosition(a);
	r2->setRotorPosition(b);
	r3->setRotorPosition(c);
}

void EnigmaEncoder::resetRotors() {
	r1->resetRotor();
	r2->resetRotor();
	r3->resetRotor();
}