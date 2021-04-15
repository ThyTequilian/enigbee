#include "rotor.hpp"
#include "plugBoard.hpp"
#include "main.hpp"
#include "pch.hpp"



int main(int argc, char* argv[]) {
	Rotor r1(0,1);
	r1.setToRotorI();
	Rotor r2(0, 26);
	r2.setToRotorII();
	Rotor r3(0,26*26);
	r3.setToRotorIII();

	PlugBoard returnRotor;
	returnRotor.createBoard();
	returnRotor.returnBoard();

	auto r1Do = [&r1](const MessageElement& elem) {
		return r1.encode(elem);
	};

	auto r2Do = [&r2](const MessageElement& elem) {
		return r2.encode(elem);
	};

	auto r3Do = [&r3](const MessageElement& elem) {
		return r3.encode(elem);
	};
	auto r1DoR = [&r1](const MessageElement& elem) {
		return r1.encodeReverse(elem);
	};

	auto r2DoR = [&r2](const MessageElement& elem) {
		return r2.encodeReverse(elem);
	};

	auto r3DoR = [&r3](const MessageElement& elem) {
		return r3.encodeReverse(elem);
	};
	
	auto returnDo = [&returnRotor](const MessageElement& elem) {
		return returnRotor.encode(elem);
	};

	auto exceptionThrown = [](ENIGERR &err) {
		std::cout << (int)err;
	};

	auto enigma = [&](const MessageElement& elem) {
		return r1Do(elem)
			.and_then(r2Do)
			.and_then(r3Do)
			.and_then(returnDo)
			.and_then(r3DoR)
			.and_then(r2DoR)
			.and_then(r1DoR);
	};

	std::wstring text = L"anton";
	std::wcout << text << std::endl;

	auto encode = [&](std::wstring& txt) {
		std::wstringstream wss;
		for (auto& elem : txt) {
			wss << enigma(elem).value();
		}
		auto out = wss.str();
		std::wcout << out << std::endl;
		return out;
	};

	auto cypher = encode(text);
	r1.resetRotor();
	r2.resetRotor();
	r3.resetRotor();
	encode(cypher);

	
	//std::wcout << encode(L'h').value() << std::endl;
	//std::wcout << encode(L'h').value() << std::endl;
	//std::wcout << encode(L'n').value() << std::endl;
	//std::wcout << encode(L'x').value() << std::endl;
	//std::wcout << encode(L'e').value() << std::endl;

	//std::wcout << encode(L'e').value() << std::endl;
	//std::wcout << encode(L'd').value() << std::endl;
	//std::wcout << encode(L'g').value() << std::endl;
	//std::wcout << encode(L'a').value() << std::endl;
	//std::wcout << encode(L'r').value() << std::endl;

	//std::wcout << encode(L'a').value() << std::endl;
	//std::wcout << encode(L'd').value() << std::endl;
	//std::wcout << encode(L'e').value() << std::endl;
	//std::wcout << encode(L'h').value() << std::endl;
	//std::wcout << encode(L'c').value() << std::endl;


}
