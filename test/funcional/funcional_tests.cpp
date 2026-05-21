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
    // Dois sistemas e um fluxo de transferência.
    // O fluxo transfere 10% da origem para o destino.
    //
    // Sistema A inicia com 100.
    // Sistema B inicia com 0.
    // Após 1 iteração:
    // A = 90
    // B = 10

    System A("Sistema A", 100);
    System B("Sistema B", 0);

    ComplexFlow transferencia(&A, &B);

    Model model;
    model.add(&A);
    model.add(&B);
    model.add(&transferencia);

    model.run(0, 1);

    assert(almostEqual(A.getValue(), 90));
    assert(almostEqual(B.getValue(), 10));

    cout << "complexFuncionalTest OK" << endl;
}
