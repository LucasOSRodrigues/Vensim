/**
 * @file unit_tests.cpp
 * @brief Implementation of unit tests for MySim framework.
 *
 * @details
 * Contains individual unit tests for System, ExponentialFlow,
 * and LogisticFlow classes. Each test validates specific functionality
 * in isolation from other components.
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "unit_tests.h"
#include "../../src/MySim.h"

using namespace std;

/**
 * @brief Checks if two double values are almost equal within tolerance.
 *
 * @param a First value.
 * @param b Second value.
 * @param tolerance Maximum allowed difference (default: 0.0001).
 * @return True if |a - b| < tolerance, false otherwise.
 */
bool almostEqualUnit(double a, double b, double tolerance = 0.0001) {
    return fabs(a - b) < tolerance;
}

/**
 * @brief Implementation of System unit test.
 *
 * Tests System class initialization, name and value retrieval,
 * and modification of both attributes.
 */
void systemUnitTest() {
    System s("Populacao", 100);

    assert(s.getName() == "Populacao");
    assert(s.getValue() == 100);

    s.setName("Pop");
    s.setValue(200);

    assert(s.getName() == "Pop");
    assert(s.getValue() == 200);

    cout << "systemUnitTest OK" << endl;
}

/**
 * @brief Implementation of ExponentialFlow unit test.
 *
 * Tests the execute() method of ExponentialFlow with
 * null source and specific sink value.
 */
void exponentialFlowUnitTest() {
    System pop("Populacao", 100);
    ExponentialFlow flow(nullptr, &pop);

    assert(almostEqualUnit(flow.execute(), 30));

    cout << "exponentialFlowUnitTest OK" << endl;
}

/**
 * @brief Implementation of LogisticFlow unit test.
 *
 * Tests the execute() method of LogisticFlow with
 * null source, specific sink value and population maximum.
 */
void logisticFlowUnitTest() {
    System pop("Populacao", 10);
    LogisticFlow flow(nullptr, &pop, 70);

    double expected = 0.3 * 10 * (1 - 10.0 / 70.0);

    assert(almostEqualUnit(flow.execute(), expected));

    cout << "logisticFlowUnitTest OK" << endl;
}
