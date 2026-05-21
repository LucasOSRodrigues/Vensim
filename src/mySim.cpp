#include "mySim.h"
#include <utility>

System::System() : name(""), value(0.0) {}

System::System(const string& name, double value)
    : name(name), value(value) {}

System::~System() = default;

System::System(const System& other)
    : name(other.name), value(other.value) {}

System& System::operator=(const System& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

System::System(System&& other) noexcept
    : name(std::move(other.name)), value(other.value) {}

System& System::operator=(System&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        value = other.value;
    }
    return *this;
}

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

Flow::Flow() : source(nullptr), sink(nullptr) {}

Flow::Flow(System* source, System* sink)
    : source(source), sink(sink) {}

Flow::~Flow() = default;

Flow::Flow(const Flow& other)
    : source(other.source), sink(other.sink) {}

Flow& Flow::operator=(const Flow& other) {
    if (this != &other) {
        source = other.source;
        sink = other.sink;
    }
    return *this;
}

Flow::Flow(Flow&& other) noexcept
    : source(other.source), sink(other.sink) {}

Flow& Flow::operator=(Flow&& other) noexcept {
    if (this != &other) {
        source = other.source;
        sink = other.sink;
    }
    return *this;
}

System* Flow::getSource() const {
    return source;
}

System* Flow::getSink() const {
    return sink;
}

ExponentialFlow::ExponentialFlow() : Flow() {}

ExponentialFlow::ExponentialFlow(System* source, System* sink)
    : Flow(source, sink) {}

ExponentialFlow::~ExponentialFlow() = default;

ExponentialFlow::ExponentialFlow(const ExponentialFlow& other)
    : Flow(other) {}

ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

ExponentialFlow::ExponentialFlow(ExponentialFlow&& other) noexcept
    : Flow(std::move(other)) {}

ExponentialFlow& ExponentialFlow::operator=(ExponentialFlow&& other) noexcept {
    if (this != &other) {
        Flow::operator=(std::move(other));
    }
    return *this;
}

double ExponentialFlow::execute() {
    // Crescimento exponencial:
    // nascimento = 0.3 * P
    if (sink != nullptr) {
        return 0.3 * sink->getValue();
    }
    return 0;
}

LogisticFlow::LogisticFlow() : Flow(), pmax(0.0) {}

LogisticFlow::LogisticFlow(System* source, System* sink, double pmax)
    : Flow(source, sink), pmax(pmax) {}

LogisticFlow::~LogisticFlow() = default;

LogisticFlow::LogisticFlow(const LogisticFlow& other)
    : Flow(other), pmax(other.pmax) {}

LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
        pmax = other.pmax;
    }
    return *this;
}

LogisticFlow::LogisticFlow(LogisticFlow&& other) noexcept
    : Flow(std::move(other)), pmax(other.pmax) {}

LogisticFlow& LogisticFlow::operator=(LogisticFlow&& other) noexcept {
    if (this != &other) {
        Flow::operator=(std::move(other));
        pmax = other.pmax;
    }
    return *this;
}

double LogisticFlow::execute() {
    // Crescimento logístico:
    // nascimento = 0.3 * P * (1 - P/Pmax)
    if (sink != nullptr) {
        double P = sink->getValue();
        return 0.3 * P * (1 - P / pmax);
    }
    return 0;
}

ComplexFlow::ComplexFlow() : Flow() {}

ComplexFlow::ComplexFlow(System* source, System* sink)
    : Flow(source, sink) {}

ComplexFlow::~ComplexFlow() = default;

ComplexFlow::ComplexFlow(const ComplexFlow& other)
    : Flow(other) {}

ComplexFlow& ComplexFlow::operator=(const ComplexFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

ComplexFlow::ComplexFlow(ComplexFlow&& other) noexcept
    : Flow(std::move(other)) {}

ComplexFlow& ComplexFlow::operator=(ComplexFlow&& other) noexcept {
    if (this != &other) {
        Flow::operator=(std::move(other));
    }
    return *this;
}

double ComplexFlow::execute() {
    return 0.1 * source->getValue();
}

Model::Model() = default;

Model::~Model() = default;

Model::Model(const Model& other)
    : systems(other.systems), flows(other.flows) {}

Model& Model::operator=(const Model& other) {
    if (this != &other) {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

Model::Model(Model&& other) noexcept
    : systems(std::move(other.systems)), flows(std::move(other.flows)) {}

Model& Model::operator=(Model&& other) noexcept {
    if (this != &other) {
        systems = std::move(other.systems);
        flows = std::move(other.flows);
    }
    return *this;
}

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
