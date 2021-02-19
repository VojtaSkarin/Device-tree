#pragma once

#include <vector>

template< typename T, typename U >
class my_vector : public std::vector< T > {
	U * Object;
	
	std::vector< std::function< void(U*) > > Handlers;

	void OnPropertyValueChange() {
		for ( const auto & handler : Handlers ) {
			handler( Object );
		}
	}

public:
	my_vector( U * object ) : Object( object ) {}

	void push_back( T && item ) {
		std::vector< T >::push_back( std::move( item ) );
		OnPropertyValueChange();
	}

	template< typename I >
	I erase( I pos ) {
		auto result = std::vector< T >::erase( pos );
		OnPropertyValueChange();
		return result;
	}

	template< typename H >
	void AddPropertyChangeHandler( const H & handler ) {
		Handlers.push_back( handler );
	}
};
