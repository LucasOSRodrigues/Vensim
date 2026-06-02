/**
 * @file LogisticFlow.cpp
 * @brief Implementation of the LogisticFlow class.
 *
 * @details
 * Contains the implementation of the methods of the LogisticFlow class,
 * including the logistic flow calculation algorithm.
 */

#include "LogisticFlow.h"

/**
 * @brief Implementation of the default constructor.
 */
LogisticFlow::LogisticFlow() : FlowImpl(), pmax(0.0) {}

/**
 * @brief Implementation of the constructor with parameters.
 */
LogisticFlow::LogisticFlow(System* source, System* sink, double pmax)
    : FlowImpl(source, sink), pmax(pmax) {}

/**
 * @brief Virtual destructor.
 */
LogisticFlow::~LogisticFlow() = default;

/**
 * @brief Implementation of the copy constructor.
 */
LogisticFlow::LogisticFlow(const LogisticFlow& other)
    : FlowImpl(other), pmax(other.pmax) {}

/**
 * @brief Implementation of the assignment operator.
 */
LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this != &other) {
        FlowImpl::operator=(other);
        pmax = other.pmax;
    }
    return *this;
}

/**
 * @brief Implementation of the execute() method.
 *
 * Calculates the logistic flow as: 0.3 * P * (1 - P/pmax)
 * where P is the value of the sink system and pmax is the maximum population.
 *
 * @return Transfer value calculated by the logistic formula.
 */
double LogisticFlow::execute() {
    if (sink != nullptr) {
        double P = sink->getValue();
        return 0.3 * P * (1 - P / pmax);
    }
    return 0;
}