#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_tests.h"
#include "../../src/mySim.h"

int main() {
    systemUnitTest();
    exponentialFlowUnitTest();
    logisticFlowUnitTest();

    return 0;
}

#endif
