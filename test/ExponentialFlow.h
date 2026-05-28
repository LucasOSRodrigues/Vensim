/**
 * @file ExponentialFlow.h
 * @brief Definition of the ExponentialFlow class.
 *
 * @details
 * Implements a specific type of flow that uses an exponential
 * growth equation to calculate the transfer of values.
 */

#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "../src/Flow.h"

/**
 * @class ExponentialFlow
 * @brief Implements a flow with exponential growth.
 *
 * @details
 * The ExponentialFlow calculates the value transferred through an
 * exponential growth equation, where the transfer rate is proportional
 * to the current value of the sink system.
 *
 * The formula used is: flow = 0.3 * sink_value
 *
 */
class ExponentialFlow : public Flow {
public:
    /**
     * @brief Default constructor.
     */
    ExponentialFlow();
    /**
     * @brief Constructor with parameters.
     *
     * @param source Pointer to the source system.
     * @param sink Pointer to the sink system.
     */
    ExponentialFlow(System* source, System* sink);
    /**
     * @brief Virtual destructor.
     */
    virtual ~ExponentialFlow();

    /**
     * @brief Copy constructor.
     *
     * @param other ExponentialFlow object to be copied.
     */
    ExponentialFlow(const ExponentialFlow& other);
    /**
     * @brief Assignment operator.
     *
     * @param other ExponentialFlow object to be assigned.
     * @return Reference to the modified ExponentialFlow object.
     */
    ExponentialFlow& operator=(const ExponentialFlow& other);

    /**
     * @brief Calculates and returns the exponential flow.
     *
     * @return Flow value calculated as 0.3 * sink_value.
     *
     * @details
     * If the sink system is null, returns 0.
     */
    double execute() override;
};

#endif