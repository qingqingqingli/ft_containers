//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"

int Factorial( int number ) {
	return number <= 1 ? number : Factorial( number - 1 ) * number;  // fail
// return number <= 1 ? 1      : Factorial( number - 1 ) * number;  // pass
}

TEST_CASE( "vectors can be sized and resized", "[vector]" ) {

// initialization block executed for each section
std::vector<int> v( 5 );
REQUIRE( v.size() == 5 );
REQUIRE( v.capacity() >= 5 );
// end of initialization block

SECTION( "resizing bigger changes size and capacity" ) {
v.resize( 10 );

REQUIRE( v.size() == 10 );
REQUIRE( v.capacity() >= 10 );
}
SECTION( "resizing smaller changes size but not capacity" ) {
v.resize( 0 );

REQUIRE( v.size() == 0 );
REQUIRE( v.capacity() >= 5 );
}
}

TEST_CASE( "vectors can be sized and resized 2", "[vector]" ) {

// initialization block executed for each section
	std::vector<int> v( 5 );
	REQUIRE( v.size() == 5 );
	REQUIRE( v.capacity() >= 5 );
// end of initialization block

	SECTION( "resizing bigger changes size and capacity" ) {
		v.resize( 9 );

		REQUIRE( v.size() == 10 );
		REQUIRE( v.capacity() >= 10 );
	}
	SECTION( "resizing smaller changes size but not capacity" ) {
		v.resize( 0 );

		REQUIRE( v.size() == 0 );
		REQUIRE( v.capacity() >= 5 );
	}
}

TEST_CASE("factorial correct cases", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("factorial wrong cases", "[factorial]") {
	REQUIRE(Factorial(0) == 1);
}