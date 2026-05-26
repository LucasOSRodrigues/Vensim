#include "Model.h"

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

void Model::add(System* system) {
    systems.push_back(system);
}

void Model::add(Flow* flow) {
    flows.push_back(flow);
}

void Model::run(int begin, int end) {
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