/**
 * @file ComplexFlow.cpp
 * @brief Implementation of the ComplexFlow class.
 *
 * @details
 * Contains the implementation of the methods of the ComplexFlow class,
 * including the complex flow calculation algorithm.
 */

#include "ComplexFlow.h"

/**
 * @brief Implementation of the default constructor.
 */
ComplexFlow::ComplexFlow() : Flow() {}

/**
 * @brief Implementation of the constructor with parameters.
 */
ComplexFlow::ComplexFlow(System* source, System* sink)
    : Flow(source, sink) {}

/**
 * @brief Virtual destructor.
 */
ComplexFlow::~ComplexFlow() = default;

/**
 * @brief Implementation of the copy constructor.
 */
ComplexFlow::ComplexFlow(const ComplexFlow& other)
    : Flow(other) {}

/**
 * @brief Implementation of the assignment operator.
 */
ComplexFlow& ComplexFlow::operator=(const ComplexFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

/**
 * @brief Implementation of the execute() method.
 *
 * Calculates the complex flow as: 0.01 * source_value
 *
 * @return Transfer value calculated by the complex formula.
 */
double ComplexFlow::execute() {
    return 0.01 * source->getValue();
}