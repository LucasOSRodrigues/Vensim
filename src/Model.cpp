/**
 * @file Model.cpp
 * @brief Implementation of the Model class.
 *
 * @details
 * Contains the implementation of all methods of the Model class,
 * particularly the simulation formula.
 */

#include "Model.h"

/**
 * @brief Implementation of the default constructor.
 */
Model::Model() = default;

/**
 * @brief Virtual destructor.
 */
Model::~Model() = default;

/**
 * @brief Implementation of the copy constructor.
 *
 * Copies the systems and flows vectors from the original model.
 */
Model::Model(const Model& other)
    : systems(other.systems), flows(other.flows) {}

/**
 * @brief Implementation of the assignment operator.
 */
Model& Model::operator=(const Model& other) {
    if (this != &other) {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

/**
 * @brief Adds a system to the model.
 *
 * Inserts the system pointer into the systems vector.
 */
void Model::add(System* system) {
    systems.push_back(system);
}

/**
 * @brief Adds a flow to the model.
 *
 * Inserts the flow pointer into the flows vector.
 */
void Model::add(Flow* flow) {
    flows.push_back(flow);
}

/**
 * @brief Executes the simulation in the specified time interval.
 *
 * @details
 * For each time unit in the interval [begin, end):
 * 1. Executes each flow and stores its return value
 * 2. For each flow:
 *    - Deducts the value from the source system (if not null)
 *    - Adds the value to the sink system (if not null)
 */
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