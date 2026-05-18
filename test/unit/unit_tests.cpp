#include <cassert>
#include <cmath>
#include <iostream>

#include "unit_tests.h"
#include "../../src/mySim.h"

using namespace std;

bool almostEqualUnit(double a, double b, double tolerance = 0.0001) {
    return fabs(a - b) < tolerance;
}

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

void exponentialFlowUnitTest() {
    System pop("Populacao", 100);
    ExponentialFlow flow(nullptr, &pop);

    assert(almostEqualUnit(flow.execute(), 30));

    cout << "exponentialFlowUnitTest OK" << endl;
}

void logisticFlowUnitTest() {
    System pop("Populacao", 10);
    LogisticFlow flow(nullptr, &pop, 70);

    double expected = 0.3 * 10 * (1 - 10.0 / 70.0);

    assert(almostEqualUnit(flow.execute(), expected));

    cout << "logisticFlowUnitTest OK" << endl;
}
