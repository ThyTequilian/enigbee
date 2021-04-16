#include "rotor.hpp"
#include "plugBoard.hpp"
#include "main.hpp"
#include "pch.hpp"
#include "enigmaEncoder.hpp"



int main(int argc, char* argv[]) {

	std::wstring text = L"antonistmeinlieblingsnameaaaaaaaaaaaaaaaaa";

	EnigmaEncoder eniggy;
	std::wcout << text << std::endl;
	auto cpr = eniggy.encodeText(text);
	std::wcout << cpr.value() << std::endl;
	eniggy.resetRotors();
	cpr = eniggy.encodeText(cpr.value());
	std::wcout << cpr.value() << std::endl;
}
