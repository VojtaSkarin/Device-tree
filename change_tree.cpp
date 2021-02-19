#include "change_tree.hpp"

void ChangeRandomAddDevice( DeviceGroup & group ) {
	std::cout << "Add device" << std::endl;
	
	auto & son = * group.Devices.at( rand() % group.Devices.size() );
	auto & sonGroup = static_cast< DeviceGroup & >( son );

	sonGroup.Devices.push_back( RandomDevice( 2, & sonGroup ) );
}

void ChangeRandomRemoveDevice( DeviceGroup & group ) {
	std::cout << "Remove device" << std::endl;
	
	auto & son = * group.Devices.at( rand() % group.Devices.size() );
	auto & sonGroup = static_cast< DeviceGroup & >( son );

	auto it = sonGroup.Devices.begin();
	std::advance( it, rand() % sonGroup.Devices.size() );
	sonGroup.Devices.erase( it );
}

void ChangeRandomMoveDevice( DeviceGroup & group ) {
	std::cout << "Move device" << std::endl;
	
	auto & sonFrom = * group.Devices.at( rand() % group.Devices.size() );
	auto & sonFromGroup = static_cast< DeviceGroup & >( sonFrom );

	auto & sonTo = * group.Devices.at( rand() % group.Devices.size() );
	auto & sonToGroup = static_cast< DeviceGroup & >( sonTo );

	int toMoveIndex = rand() % sonFromGroup.Devices.size();
	auto moved = std::move( sonFromGroup.Devices.at( toMoveIndex ) );

	auto it = sonFromGroup.Devices.begin();
	std::advance( it, toMoveIndex );
	sonFromGroup.Devices.erase( it );

	sonToGroup.Devices.push_back( std::move( moved ) );
}

void ChangeRandomName( DeviceGroup & group ) {
	std::cout << "Change device name" << std::endl;
	
	auto & son = * group.Devices.at( rand() % group.Devices.size() );
	auto & sonGroup = static_cast< DeviceGroup & >( son );

	auto & grandSon = * sonGroup.Devices.at( rand() % sonGroup.Devices.size() );

	grandSon.Name = "Entirely new name";	
}

void ChangeRandomAttributeLedPanel( LedPanel & panel ) {
	std::cout << "Change Led panel" << std::endl;
	
	panel.Message = "Entirely new message";
}

void ChangeRandomAttributeDoor( Door & door ) {
	std::cout << "Chagen Door" << std::endl;
	
	int option = rand() % 4;

	if ( option == 0 ) {
		door.Locked = ! door.Locked;
	} else if ( option == 1 ) {
		door.Open = ! door.Open;	
	} else if ( option == 2 ) {
		door.OpenForTooLong = ! door.OpenForTooLong;
	} else if ( option == 3 ) {
		door.OpenedForcibly = ! door.OpenedForcibly;
	}
}

void ChangeRandomAttributeSpeaker( Speaker & speaker ) {
	std::cout << "Change Speaker" << std::endl;
	
	int option = rand() % 2;

	if ( option == 0 ) {
 		speaker.Sound = static_cast< SoundState >( rand() % 3 );
	} else if ( option == 1 ) {
		speaker.Volume = rand() % 100;
	}
}

void ChangeRandomAttributeCardReader( CardReader & reader ) {
	std::cout << "Change Card reader" << std::endl;

	reader.AccessCardNumber = "123456789abcdef0";
}

void ChangeRandomAttribute( DeviceGroup & group ) {
	auto & son = * group.Devices.at( rand() % group.Devices.size() );
	auto & sonGroup = static_cast< DeviceGroup & >( son );

	auto & grandSon = * sonGroup.Devices.at( rand() % sonGroup.Devices.size() );

	if ( grandSon.Type == DeviceType::LedPanel ) {
		ChangeRandomAttributeLedPanel( static_cast< LedPanel & >( grandSon ) );
	} else if ( grandSon.Type == DeviceType::Door ) {
		ChangeRandomAttributeDoor( static_cast< Door & >( grandSon ) );
	} else if ( grandSon.Type == DeviceType::Speaker ) {
		ChangeRandomAttributeSpeaker( static_cast< Speaker & >( grandSon ) );
	} else if ( grandSon.Type == DeviceType::CardReader ) {
		ChangeRandomAttributeCardReader( static_cast< CardReader & >( grandSon ) );
	}
}

void ChangeTree( DeviceGroup & group ) {
	const static std::vector< std::function< void(DeviceGroup&) > > operations = {
		[] ( auto & group ) -> void { ChangeRandomAddDevice( group ); },
		[] ( auto & group ) -> void { ChangeRandomRemoveDevice( group ); },
		[] ( auto & group ) -> void { ChangeRandomMoveDevice( group ); },
		[] ( auto & group ) -> void { ChangeRandomName( group ); }
	};

	for ( const auto & operation : operations ) {
		operation( group );
		sleep( 1 );
	}
}