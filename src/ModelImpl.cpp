#include "ModelImpl.h"

ModelImpl::ModelImpl() = default;

ModelImpl::~ModelImpl() = default;

ModelImpl::ModelImpl(const ModelImpl& other)
    : systems(other.systems), flows(other.flows) {}

ModelImpl& ModelImpl::operator=(const ModelImpl& other) {
    if (this != &other) {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

void ModelImpl::add(System* system) {
    systems.push_back(system);
}

void ModelImpl::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelImpl::run(int begin, int end) {
    for (int time = begin; time < end; time++) {
        vector<double> values;

        for (auto flow : flows) {
            values.push_back(flow->execute());
        }

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

size_t ModelImpl::getSystemCount() const {
    return systems.size();
}

size_t ModelImpl::getFlowCount() const {
    return flows.size();
}
