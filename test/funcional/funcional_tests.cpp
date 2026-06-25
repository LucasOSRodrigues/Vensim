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

using namespace std;

/**
 * @brief Rounds a double value to 4 decimal places.
 *
 * @param value The value to round.
 * @return The rounded value.
 */
int round4(double value) {
    return int(round(value * 10000.0));
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

    Model* model = Model::createModel("Exponential Model");

    System* pop = model->createSystem("Populacao", 10);
    model->createFlow<ExponentialFlow>("nascimento", nullptr, pop);

    model->run(0, 10);

    assert(round4(pop->getValue()) == round4(137.858491849));

    cout << "exponentialFuncionalTest OK" << endl;

    Model::deleteModel("Exponential Model");
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

    Model* model = Model::createModel("Logistic Model");

    System* pop = model->createSystem("Populacao", 10);
    model->createFlow<LogisticFlow>("nascimento", nullptr, pop, 70);

    model->run(0, 100);

    assert(isBetween(pop->getValue(), 69.9, 70.0001));

    cout << "logisticalFuncionalTest OK" << endl;

    Model::deleteModel("Logistic Model");
}
/**
 * @brief Implementation of complex functional test.
 *
 * Creates a complex network of 5 systems connected by 6 complex flows.
 * This represents a more realistic system with multiple interconnected
 * components. Simulates 100 time units and verifies all final values.
 */
void complexFuncionalTest() {
    Model* model = Model::createModel("Complex Model");

    System* q1 = model->createSystem("Q1", 100.0);
    System* q2 = model->createSystem("Q2", 0.0);
    System* q3 = model->createSystem("Q3", 100.0);
    System* q4 = model->createSystem("Q4", 0.0);
    System* q5 = model->createSystem("Q5", 0.0);

    model->createFlow<ComplexFlow>("f", q1, q2);
    model->createFlow<ComplexFlow>("g", q1, q3);
    model->createFlow<ComplexFlow>("r", q2, q5);
    model->createFlow<ComplexFlow>("t", q2, q3);
    model->createFlow<ComplexFlow>("u", q3, q4);
    model->createFlow<ComplexFlow>("v", q4, q1);

    model->run(0, 100);

    assert(round4(q1->getValue()) == round4(31.8513));
    assert(round4(q2->getValue()) == round4(18.4003));
    assert(round4(q3->getValue()) == round4(77.1143));
    assert(round4(q4->getValue()) == round4(56.1728));
    assert(round4(q5->getValue()) == round4(16.4612));

    cout << "complexFuncionalTest OK" << endl;

    Model::deleteModel("Complex Model");
}