/**
* This Class handles the reagin of a configfile for a Virtuoso-Database
*
* @author Khun
* @version 1.0
*/

#include "rotor.hpp"


auto Rotor::encode(MessageElement& element)->tl::expected<int, MessageElement> {

	


	return element;


}

void Rotor::rotate(){
	rotorPosition += rotationOffset;
	rotorPosition %= 26;
}