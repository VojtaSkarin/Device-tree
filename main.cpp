#include "device.hpp"
#include "led_panel.hpp"
#include "door.hpp"
#include "speaker.hpp"
#include "card_reader.hpp"
#include "device_group.hpp"

#include "create_tree.hpp"
#include "change_tree.hpp"
#include "interactive_mode.hpp"

int main( void ) {
	std::unique_ptr< Device > tree = CreateTree();

	ChangeTree( static_cast< DeviceGroup & > ( * tree ) );

	std::cout << "Interactive mode" << std::endl;

	InterActiveMode( * tree, 0 );
	
	return EXIT_SUCCESS;
}