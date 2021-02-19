#include "interactive_change_structure.hpp"

void InterActiveAddLedPanel( DeviceGroup & group ) {
	group.Devices.push_back( std::make_unique< LedPanel >( &group ) );
	auto & device = static_cast< LedPanel & >( * group.Devices.back() );

	device.Id.AddPropertyChangeHandler( printDevice );
	device.Name.AddPropertyChangeHandler( printDevice );
	device.Message.AddPropertyChangeHandler( printDevice );

	InterActiveDeviceChangeName( device );
	InterActiveLedPanelChangeMessage( device );
}

void InterActiveAddDoor( DeviceGroup & group ) {
	group.Devices.push_back( std::make_unique< Door >( & group ) );
	auto & device = static_cast< Door & >( * group.Devices.back() );

	device.Id.AddPropertyChangeHandler( printDevice );
	device.Name.AddPropertyChangeHandler( printDevice );
	device.Locked.AddPropertyChangeHandler( printDevice );
	device.Open.AddPropertyChangeHandler( printDevice );
	device.OpenForTooLong.AddPropertyChangeHandler( printDevice );
	device.OpenedForcibly.AddPropertyChangeHandler( printDevice );

	InterActiveDeviceChangeName( device );
	InterActiveDoorChangeLockedState( device );
	InterActiveDoorChangeOpenState( device );
	InterActiveDoorChangeOpenForTooLongState( device );
	InterActiveDoorChangeOpenedForciblyState( device );
}

void InterActiveAddSpeaker( DeviceGroup & group ) {
	group.Devices.push_back( std::make_unique< Speaker >( & group ) );
	auto & device = static_cast< Speaker & >( * group.Devices.back() );

	device.Id.AddPropertyChangeHandler( printDevice );
	device.Name.AddPropertyChangeHandler( printDevice );
	device.Sound.AddPropertyChangeHandler( printDevice );
	device.Volume.AddPropertyChangeHandler( printDevice );

	InterActiveDeviceChangeName( device );
	InterActiveSpeakerChangeSoundState( device );
	InterActiveSpeakerChangeVolume( device );
}

void InterActiveAddCardReader( DeviceGroup & group ) {
	group.Devices.push_back( std::make_unique< CardReader >( & group ) );
	auto & device = static_cast< CardReader & >( * group.Devices.back() );

	device.Id.AddPropertyChangeHandler( printDevice );
	device.Name.AddPropertyChangeHandler( printDevice );
	device.AccessCardNumber.AddPropertyChangeHandler( printDevice );

	InterActiveDeviceChangeName( device );
	InterActiveCardReaderChangeAccessCardNumber( device );
}

void InterActiveAddDeviceGroup( DeviceGroup & group ) {
	group.Devices.push_back( std::make_unique< DeviceGroup >( & group ) );
	auto & device = static_cast< DeviceGroup & >( * group.Devices.back() );

	device.Id.AddPropertyChangeHandler( printDevice );
	device.Name.AddPropertyChangeHandler( printDevice );
	device.Devices.AddPropertyChangeHandler( printTree );

	InterActiveDeviceChangeName( device );
}

void InterActiveAddDevice( DeviceGroup & group, int depth ) {
	if ( depth < 1 ) {
		std::cout << "Adding group" << std::endl;

		InterActiveAddDeviceGroup( group );
	} else {
		std::cout << "Adding device" << std::endl;
		std::cout << "Select which devide type to create" << std::endl;
		
		for ( unsigned int i = 0; i < DeviceTypes.size() - 1; i++ ) {
			DeviceType type = DeviceTypes.at( i );
			std::cout << "\t" << i << ") " << type << std::endl;
		}

		int input = ReadNumberInRange( 0, DeviceTypes.size() - 1 );
		DeviceType type = static_cast< DeviceType >( input );

		if ( type == DeviceType::LedPanel ) {
			InterActiveAddLedPanel( group );
		} else if ( type == DeviceType::Door ) {
			InterActiveAddDoor( group );
		} else if ( type == DeviceType::Speaker ) {
			InterActiveAddSpeaker( group );
		} else if ( type == DeviceType::CardReader ) {
			InterActiveAddCardReader( group );
		}
	}
}

void InterActiveDeleteDevice( DeviceGroup & group ) {
	if ( group.Devices.size() == 0 ) {
		std::cout << "Group is empty" << std::endl;
		return;
	}

	std::cout << "Which one?" << std::endl;

	int input = ReadNumberInRange( 0, group.Devices.size() );

	auto it = group.Devices.begin();
	std::advance( it, input );
	group.Devices.erase( it );
}
void InterActiveMoveDevice( DeviceGroup & group ) {
	if ( group.Devices.size() == 0 ) {
		std::cout << "Group is empty" << std::endl;
		return;
	}

	if ( group.Parent == nullptr ||
		static_cast< DeviceGroup & >( * group.Parent ).Devices.size() == 1 ) {
		std::cout << "This is only group on this level" << std::endl;
		return;
	}

	std:: cout << "Select device" << std::endl;

	for ( unsigned int i = 0; i < group.Devices.size(); i++ ) {
		const auto & device = * group.Devices.at( i );
		std::cout << "\t" << i << ") " << device.Name << std::endl;
	}

	int input = ReadNumberInRange( 0, group.Devices.size() );

	std::unique_ptr< Device > deviceToMove = std::move( group.Devices.at( input ) );

	auto it = group.Devices.begin();
	std::advance( it, input );
	group.Devices.erase( it );

	const DeviceGroup & parent = * group.Parent;

	std::cout << "Select group to move device to" << std::endl;

	for ( unsigned int i = 0; i < parent.Devices.size(); i++ ) {
		const auto & device = * parent.Devices.at( i );
		std::cout << "\t" << i << ") " << device.Name << std::endl;
	}

	input = ReadNumberInRange( 0, parent.Devices.size() );

	auto & anotherGroup = static_cast< DeviceGroup & >( * parent.Devices.at( input ) );
	anotherGroup.Devices.push_back( std::move( deviceToMove ) );
}