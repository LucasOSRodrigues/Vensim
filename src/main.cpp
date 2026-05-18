#include <iostream>
#include "mySim.h"

using namespace std;

void exponentialModel() {
    double initialPopulation;
    int time;

    cout << "\n=== MODELO EXPONENCIAL ===" << endl;
    cout << "Populacao inicial: ";
    cin >> initialPopulation;

    cout << "Tempo de simulacao: ";
    cin >> time;

    System pop("Populacao", initialPopulation);
    ExponentialFlow nascimento(nullptr, &pop);

    Model model;
    model.add(&pop);
    model.add(&nascimento);

    model.run(0, time);

    cout << "Populacao final: " << pop.getValue() << endl;
}

void logisticModel() {
    double initialPopulation;
    double pmax;
    int time;

    cout << "\n=== MODELO LOGISTICO ===" << endl;
    cout << "Populacao inicial: ";
    cin >> initialPopulation;

    cout << "Pmax: ";
    cin >> pmax;

    cout << "Tempo de simulacao: ";
    cin >> time;

    System pop("Populacao", initialPopulation);
    LogisticFlow nascimento(nullptr, &pop, pmax);

    Model model;
    model.add(&pop);
    model.add(&nascimento);

    model.run(0, time);

    cout << "Populacao final: " << pop.getValue() << endl;
}

int main() {
    int option;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Modelo Exponencial" << endl;
        cout << "2 - Modelo Logistico" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> option;

        switch (option) {
            case 1:
                exponentialModel();
                break;

            case 2:
                logisticModel();
                break;

            case 0:
                cout << "Encerrando programa..." << endl;
                break;

            default:
                cout << "Opcao invalida." << endl;
        }

    } while (option != 0);

    return 0;
}
