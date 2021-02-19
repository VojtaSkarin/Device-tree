#include "interactive_change_property.hpp"

void InterActiveDeviceChangeId( Device & device ) {
	std::cout << "Id: ";

	std::string id;

	while ( true ) {
		try {
			int number = ReadInt();

			if ( number < 0 ) {
				std::cout << "Id must be positive" << std::endl;
				continue;
			}
			
			device.Id = number;
			break;
		}
		catch ( const std::invalid_argument & ) {
			std::cout << "Id already used" << std::endl;
		} 
	}
}

void InterActiveDeviceChangeName( Device & device ) {
	std::cout << "Name: ";
	
	std::string name;
	std::getline( std::cin, name );

	device.Name = name;	
}

void InterActiveLedPanelChangeMessage( LedPanel & panel ) {
	std::cout << "Message: ";

	std::string input;
	std::getline( std::cin, input );

	panel.Message = input;
}

void InterActiveDoorChangeLockedState( Door & door ) {
	std::cout << "Locked? [y|n]: ";
	door.Locked = ReadYesNo();
}

void InterActiveDoorChangeOpenState( Door & door ) {
	std::cout << "Open? [y|n]: ";
	door.Open = ReadYesNo();
}

void InterActiveDoorChangeOpenForTooLongState( Door & door ) {
	std::cout << "Open for too long? [y|n]: ";
	door.OpenForTooLong = ReadYesNo();
}

void InterActiveDoorChangeOpenedForciblyState( Door & door ) {
	std::cout << "Opened forcibly? [y|n]: ";
	door.OpenedForcibly = ReadYesNo();
}

void InterActiveSpeakerChangeSoundState( Speaker & speaker ) {
	std::cout << "Sound state [None|Music|Alarm]: ";
	speaker.Sound = ReadSoundState();
}

void InterActiveSpeakerChangeVolume( Speaker & speaker ) {
	std::cout << "Volume: ";
	speaker.Volume = ReadDouble();
}

void InterActiveCardReaderChangeAccessCardNumber( CardReader & reader ) {
	std::string cardNumber;
	
	while ( true ) {
		std::cout << "Access card number: ";
		std::getline( std::cin, cardNumber );
			
		try {
			reader.AccessCardNumber = cardNumber;
			break;
		}
		catch ( const std::invalid_argument & ) {
			std::cout << "Bad format" << std::endl;
		}
	}
}