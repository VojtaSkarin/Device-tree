#include "interactive_mode.hpp"

void PrintTree( const Device & device, int depth ) {
	for ( int i = 0; i < depth; i++ ) {
		std::cout << "\t";
	}

	std::cout << device.GetCurrentState() << std::endl;
	std::cout << std::endl;

	if ( device.Type == DeviceType::DeviceGroup ) {
		const auto & group = static_cast< const DeviceGroup & >( device );

		for ( const auto & son : group.Devices ) {
			PrintTree( * son, depth + 1 );
		}
	}
}

void printDevice( const Device * device ) {
	std::cout << std::endl;
	std::cout << "Device after change" << std::endl;
	std::cout << device->GetCurrentState() << std::endl;
}

void printTree( const Device * device ) {
	while ( device->Parent != nullptr ) {
		device = device->Parent;
	}
	
	PrintTree( * device );
}

void InterActiveSelectDevice( DeviceGroup & group, int depth ) {
	if ( group.Devices.size() == 0 ) {
		std::cout << "Group is empty" << std::endl;
		return;
	}

	std::cout << "Select device" <<std::endl;

	for ( unsigned int i = 0; i < group.Devices.size(); i++ ) {
		const auto & device = group.Devices.at( i );
		std::cout << "\t" << i << ") " << device->Name << std::endl;
	}

	int input = ReadNumberInRange( 0, group.Devices.size() );
	
	InterActiveMode( * group.Devices.at( input ), depth + 1 );
}

void InterActiveLedPanel( LedPanel & panel ) {
	while ( true ) {
		std::cout << panel.GetCurrentState() << std::endl;

		std::cout << "Select option" << std::endl;
		std::cout << "\t0) Change id" << std::endl;
		std::cout << "\t1) Change name" << std::endl;
		std::cout << "\t2) Change message" << std::endl;
		std::cout << "\t3) Back" << std::endl;

		int input = ReadNumberInRange( 0, 4 );

		if ( input == 0 ) {
			InterActiveDeviceChangeId( panel );
		} else if ( input == 1 ) {
			InterActiveDeviceChangeName( panel );
		} else if ( input == 2 ) {
			InterActiveLedPanelChangeMessage( panel );
		} else if ( input == 3 ) {
			break;
		}
	}
}

void InterActiveDoor( Door & door ) {
	while ( true ) {
		std::cout << door.GetCurrentState() << std::endl;

		std::cout << "Select option" << std::endl;
		std::cout << "\t0) Change Id" << std::endl;
		std::cout << "\t1) Change name" << std::endl;
		std::cout << "\t2) Change locked state" << std::endl;
		std::cout << "\t3) Change open state" << std::endl;
		std::cout << "\t4) Change open for too long state" << std::endl;
		std::cout << "\t5) Change opened forcibly state" << std::endl;
		std::cout << "\t6) Back" << std::endl;

		int input = ReadNumberInRange( 0, 7 );

		if ( input == 0 ) {
			InterActiveDeviceChangeId( door );
		} else if ( input == 1 ) {
			InterActiveDeviceChangeName( door );
		} else if ( input == 2 ) {
			InterActiveDoorChangeLockedState( door );
		} else if ( input == 3 ) {
			InterActiveDoorChangeOpenState( door );
		} else if ( input == 4 ) {
			InterActiveDoorChangeOpenForTooLongState( door );
		} else if ( input == 5 ) {
			InterActiveDoorChangeOpenedForciblyState( door );
		} else if ( input == 6 ) {
			break;
		}
	}
}

void InterActiveSpeaker( Speaker & speaker ) {
	while ( true ) {
		std::cout << speaker.GetCurrentState() << std::endl;

		std::cout << "Select option" << std::endl;
		std::cout << "\t0) Change id" << std::endl;
		std::cout << "\t1) Change name" << std::endl;
		std::cout << "\t2) Change sound" << std::endl;
		std::cout << "\t3) Change volume" << std::endl;
		std::cout << "\t4) Back" << std::endl;

		int input = ReadNumberInRange( 0, 5 );

		if ( input == 0 ) {
			InterActiveDeviceChangeId( speaker );
		} else if ( input == 1 ) {
			InterActiveDeviceChangeName( speaker );
		} else if ( input == 2 ) {
			InterActiveSpeakerChangeSoundState( speaker );
		} else if ( input == 3 ) {
			InterActiveSpeakerChangeVolume( speaker );
		} else if ( input == 4 ) {
			break;
		}
	}
}

void InterActiveCardReader( CardReader & reader ) {
	while ( true ) {
		std::cout << reader.GetCurrentState() << std::endl;

		std::cout << "Select option" << std::endl;
		std::cout << "\t0) Change id" << std::endl;
		std::cout << "\t1) Change name" << std::endl;
		std::cout << "\t2) Change access card number" << std::endl;
		std::cout << "\t3) Back" << std::endl;

		int input = ReadNumberInRange( 0, 4 );

		if ( input == 0 ) {
			InterActiveDeviceChangeId( reader );
		} else if ( input == 1 ) {
			InterActiveDeviceChangeName( reader );
		} else if ( input == 2 ) {
			InterActiveCardReaderChangeAccessCardNumber( reader );
		} else if ( input == 3 ) {
			break;
		}
	}
}



void InterActiveDeviceGroup( DeviceGroup & group, int depth ) {
	bool active = true;

	while ( active ) {
		std::cout << std::endl;
		std::cout << "Selected device:" << std::endl;
		std::cout << group.GetCurrentState() << std::endl;
		std::cout << std::endl;

		std::cout << "Devices:" << std::endl;

		for ( unsigned int i = 0; i < group.Devices.size(); i++ ) {
			const auto & device = group.Devices.at( i );
			std::cout << '\t' << i << ") " << device->Name << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Select action" << std::endl;

		std::cout << "\t0) Add device" << std::endl;
		std::cout << "\t1) Delete device" << std::endl;
		std::cout << "\t2) Change this device id" << std::endl;
		std::cout << "\t3) Rename this device" << std::endl;
		std::cout << "\t4) Select device" << std::endl;
		std::cout << "\t5) Move device to another group" << std::endl;
		std::cout << "\t6) Write device tree" << std::endl;
		std::cout << "\t7) Close" << std::endl;

		int input = ReadNumberInRange( 0, 8 );

		if ( input == 0 ) {
			InterActiveAddDevice( group, depth );
		} else if ( input == 1 ) {
			InterActiveDeleteDevice( group );
		} else if ( input == 2 ) {
			InterActiveDeviceChangeId( group );
		} else if ( input == 3 ) {
			InterActiveDeviceChangeName( group );
		} else if ( input == 4 ) {
			InterActiveSelectDevice( group, depth );
		} else if ( input == 5 ) {
			InterActiveMoveDevice( group );
		} else if ( input == 6 ) {
			PrintTree( group );
		} else if ( input == 7 ) {
			active = false;
		}
	}
}

void InterActiveMode( Device & device, int depth ) {
	if ( device.Type == DeviceType::DeviceGroup ) {
		InterActiveDeviceGroup( static_cast< DeviceGroup & >( device ), depth );
	} else if ( device.Type == DeviceType::LedPanel ) {
		InterActiveLedPanel( static_cast< LedPanel & >( device ) );
	} else if ( device.Type == DeviceType::Door ) {
		InterActiveDoor( static_cast< Door & >( device ) );
	} else if ( device.Type == DeviceType::Speaker ) {
		InterActiveSpeaker( static_cast< Speaker & >( device ) );
	} else if ( device.Type == DeviceType::CardReader ) {
		InterActiveCardReader( static_cast< CardReader & >( device ) );
	}
}