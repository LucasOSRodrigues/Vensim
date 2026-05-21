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

Flow::Flow(System* source, System* sink)
    : source(source), sink(sink) {}

Flow::~Flow() {}

System* Flow::getSource() const {
    return source;
}

System* Flow::getSink() const {
    return sink;
}

ExponentialFlow::ExponentialFlow(System* source, System* sink)
    : Flow(source, sink) {}

double ExponentialFlow::execute() {
    // Crescimento exponencial:
    // nascimento = 0.3 * P
    if (sink != nullptr) {
        return 0.3 * sink->getValue();
    }
    return 0;
}

LogisticFlow::LogisticFlow(System* source, System* sink, double pmax)
    : Flow(source, sink), pmax(pmax) {}

double LogisticFlow::execute() {
    // Crescimento logístico:
    // nascimento = 0.3 * P * (1 - P/Pmax)
    if (sink != nullptr) {
        double P = sink->getValue();
        return 0.3 * P * (1 - P / pmax);
    }
    return 0;
}

ComplexFlow::ComplexFlow(System* source, System* sink)
    : Flow(source, sink) {}

double ComplexFlow::execute() {
    // Transfere 10% do valor da source para o sink.
    return 0.1 * source->getValue();
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

            System* source = flow->getSource();
            System* sink = flow->getSink();

            double value = values[i];

            if (source != nullptr) {
                source->setValue(source->getValue() - value);
            }

            if (sink != nullptr) {
                sink->setValue(sink->getValue() + value);
            }
        }
    }
}
