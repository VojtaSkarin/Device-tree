#pragma once

#include <vector>
#include <functional>

#include "property_readonly.hpp"

template< typename T, typename U >
class Property : public PropertyReadOnly< T > {
protected:
	U * Object;

	std::function< void(T&, const T&) > Setter;

	std::vector< std::function< void(U*) > > Handlers;

	void OnPropertyValueChange() {
		for ( const auto & handler : Handlers ) {
			handler( Object );
		}
	}
	
public:
	constexpr static auto DefaultSetter =
		[] ( T & oldValue, T newValue ) { oldValue = std::move( newValue ); };

	Property( const Property & p ) = delete;

	Property( Property && p ) = delete;

	Property( U * object ) : Object( object ) {}

	Property( U * object, T value ) : Property( object, std::move( value ),
		DefaultSetter ) {}

	template< typename S >
	Property( U * object, T value, const S & setter ) : PropertyReadOnly< T >( std::move( value ) ),
		Object( object ), Setter( setter ) {}

	template< typename S, typename G >
	Property( U * object, T value, const S & setter, const G & getter )
		: PropertyReadOnly< T >( std::move( value ), getter ), Object( object ), Setter( setter ) {}
	
	Property & operator=( const Property & p ) = delete;

	Property & operator=( const T & value ) {
		Setter( this->Value, value );
		OnPropertyValueChange();
		return *this;
	}

	T & operator*() {
		OnPropertyValueChange();
		return this->Value;
	}

	const T & get() const {
		return this->Value;
	}

	T & get() {
		return this->Value;
	}

	template< typename H >
	void AddPropertyChangeHandler( const H & handler ) {
		Handlers.push_back( handler );
	}
};
