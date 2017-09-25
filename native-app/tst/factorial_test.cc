#include "catch.hpp"

// Command line options for Catch (C++ Automated Test Cases in Headers).
// https://github.com/philsquared/Catch/blob/master/docs/command-line.md

// Below test taken from below link.
// https://github.com/philsquared/Catch/blob/master/test_package/MainTest.cpp

unsigned int Factorial( unsigned int number ) {
  	return number > 1 ? Factorial(number-1)*number : 1;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(0) == 1 );
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}