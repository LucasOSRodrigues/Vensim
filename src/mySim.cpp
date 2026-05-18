#include "mySim.h"

System::System(const string& name, double value)
    : name(name), value(value) {}

void System::setName(const string& name) {
    this->name = name;
}

void System::setValue(double value) {
    this->value = value;
}

string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}

Flow::Flow(System* origem, System* destino)
    : origem(origem), destino(destino) {}

Flow::~Flow() {}

System* Flow::getOrigem() const {
    return origem;
}

System* Flow::getDestino() const {
    return destino;
}

ExponentialFlow::ExponentialFlow(System* origem, System* destino)
    : Flow(origem, destino) {}

double ExponentialFlow::execute() {
    // Crescimento exponencial:
    // nascimento = 0.3 * P
    return 0.3 * destino->getValue();
}

LogisticFlow::LogisticFlow(System* origem, System* destino, double pmax)
    : Flow(origem, destino), pmax(pmax) {}

double LogisticFlow::execute() {
    // Crescimento logístico:
    // nascimento = 0.3 * P * (1 - P/Pmax)
    double P = destino->getValue();
    return 0.3 * P * (1 - P / pmax);
}

ComplexFlow::ComplexFlow(System* origem, System* destino)
    : Flow(origem, destino) {}

double ComplexFlow::execute() {
    // Transfere 10% do valor da origem para o destino.
    return 0.1 * origem->getValue();
}

Model::Model() {}

void Model::add(System* system) {
    systems.push_back(system);
}

void Model::add(Flow* flow) {
    flows.push_back(flow);
}

void Model::run(int begin, int end) {
    for (int time = begin; time < end; time++) {

        vector<double> values;

        // Primeiro calcula todos os fluxos.
        // Isso evita que um fluxo altere o resultado de outro no mesmo instante.
        for (auto flow : flows) {
            values.push_back(flow->execute());
        }

        // Depois aplica os valores calculados aos sistemas.
        for (size_t i = 0; i < flows.size(); i++) {
            Flow* flow = flows[i];

            System* origem = flow->getOrigem();
            System* destino = flow->getDestino();

            double value = values[i];

            if (origem != nullptr) {
                origem->setValue(origem->getValue() - value);
            }

            if (destino != nullptr) {
                destino->setValue(destino->getValue() + value);
            }
        }
    }
}
