//
// Created by qli on 24/02/2021.
//

// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

int Factorial( int number ) {
	return number <= 1 ? number : Factorial( number - 1 ) * number;  // fail
// return number <= 1 ? 1      : Factorial( number - 1 ) * number;  // pass
}

TEST_CASE("[factorial]", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
	REQUIRE(Factorial(0) == 1);
}
