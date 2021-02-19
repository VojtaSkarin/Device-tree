#pragma once

#include <vector>
#include <functional>

template< typename T >
class PropertyReadOnly {
protected:
	T Value;

	std::function< const T&(const T&) > Getter;

public:
	constexpr static auto DefaultGetter = [] ( const T & v ) -> const T& { return v; };

	PropertyReadOnly( const PropertyReadOnly & p ) = default;

	PropertyReadOnly( PropertyReadOnly && p ) = default;

	PropertyReadOnly() = default;

	PropertyReadOnly( T value )
		: PropertyReadOnly( std::move( value ), DefaultGetter ) {}

	template< typename G >
	PropertyReadOnly( T value, const G & getter ) : Value( std::move( value ) ),
		Getter( getter ) {}

	virtual ~PropertyReadOnly() = default;

	PropertyReadOnly & operator=( const PropertyReadOnly & newValue ) = default;

	PropertyReadOnly & operator=( const T & newValue ) = delete;
	
	operator const T&() const {
		return Getter( Value );
	}

	friend std::ostream & operator<<( std::ostream & o, const PropertyReadOnly & p ) {
		o << p.Value;
		return o;
	}
};
