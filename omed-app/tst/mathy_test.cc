#include "catch.hpp"
#include "../inc/mathy.h"

// Command line options for Catch (C++ Automated Test Cases in Headers).
// https://github.com/philsquared/Catch/blob/master/docs/command-line.md


TEST_CASE( "mathy add function", "[mathy]" ) {

    Mathy::Calculate calc;

    REQUIRE( calc.Add(0, 5) == 5 );
    REQUIRE( calc.Add(0, 0) == 0 );
    REQUIRE( calc.Add(5, 0) == 5 );

    SECTION( "add 10 with 32" ) {
        REQUIRE( calc.Add(10, 32) == 42 );
        REQUIRE( calc.Add(32, 10) == 42  );
    }

    SECTION( "add 20 with 22" ) {
        REQUIRE( calc.Add(20, 22) == 42 );
        REQUIRE( calc.Add(22, 20) == 42  );
    }
}

TEST_CASE( "mathy subtract function", "[mathy]" ) {

    Mathy::Calculate calc;

    REQUIRE( calc.Subtract(0, 5) == -5 );
    REQUIRE( calc.Subtract(0, 0) == 0 );
    REQUIRE( calc.Subtract(5, 0) == 5 );

    SECTION( "add 10 with 32" ) {
        REQUIRE( calc.Subtract(10, 32) == -22 );
        REQUIRE( calc.Subtract(32, 10) == 22  );
    }

    SECTION( "add 20 with 22" ) {
        REQUIRE( calc.Subtract(20, 22) == -2 );
        REQUIRE( calc.Subtract(22, 20) == 2  );
    }
}

TEST_CASE( "mathy multiply function", "[mathy]" ) {

    Mathy::Calculate calc;

    REQUIRE( calc.Multiply(0, 5) == 0 );
    REQUIRE( calc.Multiply(0, 0) == 0 );
    REQUIRE( calc.Multiply(5, 0) == 0 );

    SECTION( "add 10 with 32" ) {
        REQUIRE( calc.Multiply(10, 32) == 320 );
        REQUIRE( calc.Multiply(32, 10) == 320  );
    }

    SECTION( "add 20 with 22" ) {
        REQUIRE( calc.Multiply(20, 22) == 440 );
        REQUIRE( calc.Multiply(22, 20) == 440  );
    }
}