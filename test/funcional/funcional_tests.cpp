/**
 * @file funcional_tests.cpp
 * @brief Implementation of functional tests for MySim framework.
 *
 * @details
 * Contains the implementation of functional tests that validate the
 * complete simulation workflows. Each test creates a model with systems
 * and flows, runs the simulation, and verifies the results.
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "funcional_tests.h"
#include "../../src/MySim.h"

using namespace std;

/**
 * @brief Rounds a double value to 4 decimal places.
 *
 * @param value The value to round.
 * @return The rounded value.
 */
double round4(double value) {
    return round(value * 10000.0) / 10000.0;
}

/**
 * @brief Checks if a value is between two bounds (inclusive).
 *
 * @param value The value to check.
 * @param lower Lower bound (inclusive).
 * @param upper Upper bound (inclusive).
 * @return True if lower <= value <= upper, false otherwise.
 */
bool isBetween(double value, double lower, double upper) {
    return value >= lower && value <= upper;
}

/**
 * @brief Implementation of exponential functional test.
 *
 * Creates a simple model with one system (Population)
 * and one exponential flow from null source to the system.
 * Simulates 10 time units and verifies the result.
 */
void exponentialFuncionalTest() {
    // P inicial = 10, tempo = 10.
    // Esperado: 10 * 1.3^10 = aproximadamente 137.858491849.

    System pop("Populacao", 10);
    ExponentialFlow nascimento(nullptr, &pop);

    Model model;
    model.add(&pop);
    model.add(&nascimento);

    model.run(0, 10);

    assert(round4(pop.getValue()) == round4(137.858491849));

    cout << "exponentialFuncionalTest OK" << endl;
}

/**
 * @brief Implementation of logistic functional test.
 *
 * Creates a model with one system and one logistic flow
 * with population maximum limit. Simulates 100 time units
 * and verifies that population converges to the maximum.
 */
void logisticalFuncionalTest() {
    // P inicial = 10, Pmax = 70, tempo = 100.
    // Esperado: população próxima de 70.

    System pop("Populacao", 10);
    LogisticFlow nascimento(nullptr, &pop, 70);

    Model model;
    model.add(&pop);
    model.add(&nascimento);

    model.run(0, 100);

    assert(isBetween(pop.getValue(), 69.9, 70.0001));

    cout << "logisticalFuncionalTest OK" << endl;
}

/**
 * @brief Implementation of complex functional test.
 *
 * Creates a complex network of 5 systems connected by 6 complex flows.
 * This represents a more realistic system with multiple interconnected
 * components. Simulates 100 time units and verifies all final values.
 */
void complexFuncionalTest() {
    System q1("Q1", 100.0);
    System q2("Q2", 0.0);
    System q3("Q3", 100.0);
    System q4("Q4", 0.0);
    System q5("Q5", 0.0);

    ComplexFlow f(&q1, &q2);
    ComplexFlow g(&q1, &q3);
    ComplexFlow r(&q2, &q5);
    ComplexFlow t(&q2, &q3);
    ComplexFlow u(&q3, &q4);
    ComplexFlow v(&q4, &q1);

    Model model;

    model.add(&q1);
    model.add(&q2);
    model.add(&q3);
    model.add(&q4);
    model.add(&q5);

    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);

    model.run(0, 100);

    assert(round4(q1.getValue()) == round4(31.8513));
    assert(round4(q2.getValue()) == round4(18.4003));
    assert(round4(q3.getValue()) == round4(77.1143));
    assert(round4(q4.getValue()) == round4(56.1728));
    assert(round4(q5.getValue()) == round4(16.4612));

    cout << "complexFuncionalTest OK" << endl;
}