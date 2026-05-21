#include <cassert>
#include <cmath>
#include <iostream>

#include "funcional_tests.h"
#include "../../src/mySim.h"

using namespace std;

bool almostEqual(double a, double b, double tolerance = 0.0001) {
    return fabs(a - b) < tolerance;
}

bool isBetween(double value, double lower, double upper) {
    return value >= lower && value <= upper;
}

void exponentialFuncionalTest() {
    // P inicial = 10, tempo = 10.
    // Esperado: 10 * 1.3^10 = aproximadamente 137.858491849.

    System pop("Populacao", 10);
    ExponentialFlow nascimento(nullptr, &pop);

    Model model;
    model.add(&pop);
    model.add(&nascimento);

    model.run(0, 10);

    assert(almostEqual(pop.getValue(), 137.858491849));

    cout << "exponentialFuncionalTest OK" << endl;
}

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

    assert(almostEqual(q1.getValue(), 31.8513));
    assert(almostEqual(q2.getValue(), 18.4003));
    assert(almostEqual(q3.getValue(), 77.1143));
    assert(almostEqual(q4.getValue(), 56.1728));
    assert(almostEqual(q5.getValue(), 16.4612));

    cout << "complexFuncionalTest OK" << endl;
}