/**
* This Class handles the reagin of a configfile for a Virtuoso-Database
*
* @author Khun
* @version 1.0
*/

#ifndef typeDefinitions
#define typeDefinitions

#include <string>

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