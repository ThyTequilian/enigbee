
#include "main.hpp"
#include "pch.hpp"
#include "enigmaEncoder.hpp"


int main(int argc, char* argv[]) {
	
	EnigmaEncoder enigma;
	enigma.setRotors(10, 0, 0);

	//std::wstring text = L"antonistmeinlieblingsnameaaaaaaaaaaaaaaaaa";
	std::wstring text = L"antonaaaaaaaaaaa";
	std::wcout << text << std::endl;

	
	auto cypher = enigma.encodeText(text).value();
	std::wcout << cypher << std::endl;
	enigma.resetRotors();
	cypher = enigma.encodeText(cypher).value();
	std::wcout << cypher << std::endl;
	
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
