#include <iostream>

using namespace std;

string decodeMorse(std::string morseCode) {
    // ToDo: Accept dots, dashes and spaces, return human-readable message
    string decoded;
    for( auto p : morseCode ) {
      if( p == '.' )
        decoded += MORSE_CODE[ "." ];
      else if( p == '-' )
        decoded += MORSE_CODE[ "-" ];
    }
    return decoded;
}

int main(){
	

	return 0;
}
