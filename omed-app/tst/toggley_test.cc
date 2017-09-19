#include "catch.hpp"
#include "../inc/toggley.h"

// Command line options for Catch (C++ Automated Test Cases in Headers).
// https://github.com/philsquared/Catch/blob/master/docs/command-line.md


SCENARIO("Turn on toggle switch.", "[toggle_switch]") {
    GIVEN("The toggle switch was switched off.") {
        Toggley toggleySwitch;

        REQUIRE( toggleySwitch.state() == ToggleyState::STATE_OFF );

        WHEN("The toggle switch is not switched on earlier.") {

            THEN("The toggle switch is still off.") {
                REQUIRE( toggleySwitch.state() == ToggleyState::STATE_OFF );
            }
        }

        REQUIRE( toggleySwitch.state() == ToggleyState::STATE_OFF );

        WHEN("The toggle switch button is toggled.") {
            toggleySwitch.toggle();

            THEN("The toggle switch switched on.") {
                REQUIRE( toggleySwitch.state() == ToggleyState::STATE_ON );
            }

            WHEN("The toggle switch button is toggled another time.") {
                toggleySwitch.toggle();

                THEN("The toggle switch switched off again.") {
                    REQUIRE( toggleySwitch.state() == ToggleyState::STATE_OFF );
                }
            }
        }
    }
}

SCENARIO("Turn off toggle switch.", "[power_button]") {
    GIVEN("The toggle switch was switched on earlier.") {
        Toggley toggleySwitch(ToggleyState::STATE_ON);

        REQUIRE( toggleySwitch.state() == ToggleyState::STATE_ON );

        WHEN("The toggle switch button is toggled.") {
            toggleySwitch.toggle();

            THEN("The toggle switch swiched off.") {
                REQUIRE( toggleySwitch.state() == ToggleyState::STATE_OFF );
            }

            WHEN("The toggle switch button is toggled another time.") {
                toggleySwitch.toggle();

                THEN("The toggle switch switched on again.") {
                    REQUIRE( toggleySwitch.state() == ToggleyState::STATE_ON );
                }
            }
        }
    }
}
