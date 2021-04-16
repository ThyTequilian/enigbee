#ifndef typeDefinitions
#define typeDefinitions

#include <string>
#include <map>

//TypeDefinitions
using Message = std::wstring;
using MessageElement = wchar_t;
using RotorPosition = int;

//ErrorDefinitions
enum class ENIGERR{
	OK					= 0,
	elementOutOfRange	= 1,
	BrokenRotor			= 2
};


#endif