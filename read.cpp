#include "read.hpp"

int ReadInt() {
	std::string input;
	size_t count = 0;
	int result = 0;
	
	while ( true ) {
		std::getline( std::cin, input );
	
		try {
			result = std::stoi( input, & count, 10 );

			if ( count == input.size() ) {
				return result;
			}

			std::cout << "Bad format" << std::endl;
		}
		catch ( const std::invalid_argument & e ) {
			std::cout << "Number has bad format" << std::endl;
		}
		catch ( const std::out_of_range & e ) {
			std::cout << "Number out of range" << std::endl;
		}
	}
}

int ReadNumberInRange( int from, int to ) {
	std::string input;
	int result = 0;

	while ( true ) {
		result = ReadInt();

		if ( result >= from && result < to ) {
			return result;
		}

		std::cout << "Number out of range" << std::endl;		
	}
}

bool ReadYesNo() {
	const static std::map< std::string, bool > stringToBool = {
		{ "y", true },
		{ "n", false }
	};

	std::string input;

	while ( true ) {
		std::getline( std::cin, input );
		
		std::map< std::string, bool >::const_iterator it = stringToBool.find( input );
		if ( it != stringToBool.end() ) {
			return it->second;
		}

		std::cout << "Invalid input" << std::endl;
	}
}

SoundState ReadSoundState() {
	const static std::map< std::string, SoundState > stringToSoundState = {
		{ "None",  SoundState::None },
		{ "Music", SoundState::Music },
		{ "Alarm", SoundState::Alarm }
	};

	std::string input;

	while ( true ) {
		std::getline( std::cin, input );

		std::map< std::string, SoundState >::const_iterator it =
			stringToSoundState.find( input );

		if ( it != stringToSoundState.end() ) {
			return it->second;
		}

		std::cout << "Invalid input" << std::endl;
	}
}

double ReadDouble() {
	std::string input;
	char * end = nullptr;
	double result = 0;

	while ( true ) {
		std::getline( std::cin, input );

		try {
			result = std::strtod( input.c_str(), & end );

			if ( end == input.c_str() + input.size() ) {
				return result;
			}

			std::cout << "Invalid input" << std::endl;
		}
		catch ( const std::invalid_argument & e ) {
			std::cout << "Number has bad format" << std::endl;
		}
		catch ( const std::out_of_range & e ) {
			std::cout << "Number out of range" << std::endl;
		}
	}
}