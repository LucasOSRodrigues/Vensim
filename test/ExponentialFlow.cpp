/**
 * @file ExponentialFlow.cpp
 * @brief Implementation of the ExponentialFlow class.
 *
 * @details
 * Contains the implementation of the methods of the ExponentialFlow class,
 * including the exponential flow calculation algorithm.
 */

#include "ExponentialFlow.h"

/**
 * @brief Implementation of the default constructor.
 */
ExponentialFlow::ExponentialFlow() : Flow() {}

/**
 * @brief Implementation of the constructor with parameters.
 */
ExponentialFlow::ExponentialFlow(System* source, System* sink)
    : Flow(source, sink) {}

/**
 * @brief Virtual destructor.
 */
ExponentialFlow::~ExponentialFlow() = default;

/**
 * @brief Implementation of the copy constructor.
 */
ExponentialFlow::ExponentialFlow(const ExponentialFlow& other)
    : Flow(other) {}

/**
 * @brief Implementation of the assignment operator.
 */
ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

/**
 * @brief Implementation of the execute() method.
 *
 * Calculates the exponential flow as: 0.3 * sink_value
 *
 * @return Transfer value calculated by the exponential formula.
 */
double ExponentialFlow::execute() {
    if (sink != nullptr) {
        return 0.3 * sink->getValue();
    }
    return 0;
}