#include "create_tree.hpp"

std::string RandomName( std::string && name ) {
	name.push_back( ' ' );
	name.push_back( '0' + rand() % 10 );
	return name;
}

std::unique_ptr< Device > RandomDevice( int depth, DeviceGroup * parent ) {
	const static std::vector< SoundState > soundState = {
		SoundState::None,
		SoundState::Music,
		SoundState::Alarm
	};

	const static auto deviceGroup = [] ( DeviceGroup * parent ) -> std::unique_ptr< Device > {
		auto ptr = std::make_unique< DeviceGroup >( parent, RandomName( "Group" ) );

		ptr->Id.AddPropertyChangeHandler( printDevice );
		ptr->Name.AddPropertyChangeHandler( printDevice );
		ptr->Devices.AddPropertyChangeHandler( printTree );

		return ptr;
	};

	const static std::vector< std::function< std::unique_ptr< Device >(DeviceGroup*) > > others = {
		[] ( DeviceGroup * parent ) -> std::unique_ptr< Device > {
			auto ptr = std::make_unique< LedPanel >( parent, RandomName( "Led Panel" ),
				"I'm Led Panel!" );

			ptr->Id.AddPropertyChangeHandler( printDevice );
			ptr->Name.AddPropertyChangeHandler( printDevice );
			ptr->Message.AddPropertyChangeHandler( printDevice );

			return ptr;
		},
		[] ( DeviceGroup * parent ) -> std::unique_ptr< Device > {
			auto ptr = std::make_unique< Door >( parent, RandomName( "Door" ), DoorState::Open );

			ptr->Id.AddPropertyChangeHandler( printDevice );
			ptr->Name.AddPropertyChangeHandler( printDevice );
			ptr->Locked.AddPropertyChangeHandler( printDevice );
			ptr->Open.AddPropertyChangeHandler( printDevice );
			ptr->OpenForTooLong.AddPropertyChangeHandler( printDevice );
			ptr->OpenedForcibly.AddPropertyChangeHandler( printDevice );

			return ptr;
		},
		[] ( DeviceGroup * parent ) -> std::unique_ptr< Device > {
			auto ptr = std::make_unique< Speaker >( parent, RandomName( "Speaker" ),
				soundState[ rand() % soundState.size() ], rand() % 100 );

			ptr->Id.AddPropertyChangeHandler( printDevice );
			ptr->Name.AddPropertyChangeHandler( printDevice );
			ptr->Sound.AddPropertyChangeHandler( printDevice );
			ptr->Volume.AddPropertyChangeHandler( printDevice );

			return ptr;
		},
		[] ( DeviceGroup * parent ) -> std::unique_ptr< Device > {
			auto ptr = std::make_unique< CardReader >( parent, RandomName( "Card Reader" ),
				"A01234DE7FFF" );

			ptr->Id.AddPropertyChangeHandler( printDevice );
			ptr->Name.AddPropertyChangeHandler( printDevice );
			ptr->AccessCardNumber.AddPropertyChangeHandler( printDevice );

			return ptr;
		} };

	if ( depth <= 1 ) {
		return deviceGroup( parent );
	} else {
		return others.at( rand() % others.size() )( parent );
	}
}

void RandomFillDeviceGroup( DeviceGroup & group, int depth ) {
	int count = rand() % 5 + 2;

	for ( int i = 0; i < count; i++ ) {
		group.Devices.push_back( RandomDevice( depth + 1, & group ) );
		Device & device = * group.Devices.back();

		if ( device.Type == DeviceType::DeviceGroup ) {
			RandomFillDeviceGroup( static_cast< DeviceGroup & >( device ), depth + 1 );
		}
	}
}

std::unique_ptr< Device > CreateTree() {
	std::unique_ptr< Device > root = RandomDevice();

	if ( root->Type == DeviceType::DeviceGroup ) {
		DeviceGroup & group = * static_cast< DeviceGroup * >( root.get() );
		RandomFillDeviceGroup( group );
	}
	
	return root;
}
