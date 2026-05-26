/**
 * @file LogisticFlow.h
 * @brief Definition of the LogisticFlow class.
 *
 * @details
 * Implements a specific type of flow that uses a logistic function
 * to calculate the transfer of values, with maximum population limit.
 */

#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H

#include "Flow.h"

/**
 * @class LogisticFlow
 * @brief Implements a logistic flow with population limit.
 *
 * @details
 * The LogisticFlow calculates the value transferred through a logistic function
 * that simulates growth limited by environmental capacity.
 *
 * The formula used is: flow = 0.3 * P * (1 - P/pmax)
 * where P is the current value of the sink system and pmax is the maximum population.
 *
 * @author Development Team
 * @version 1.0
 * @date 2024
 */
class LogisticFlow : public Flow {
private:
    double pmax;  /**< Maximum population that limits growth */

public:
    /**
     * @brief Default constructor.
     */
    LogisticFlow();
    /**
     * @brief Constructor with parameters.
     *
     * @param source Pointer to the source system.
     * @param sink Pointer to the sink system.
     * @param pmax Maximum population value to limit growth.
     */
    LogisticFlow(System* source, System* sink, double pmax);
    /**
     * @brief Virtual destructor.
     */
    virtual ~LogisticFlow();

    /**
     * @brief Copy constructor.
     *
     * @param other LogisticFlow object to be copied.
     */
    LogisticFlow(const LogisticFlow& other);
    /**
     * @brief Assignment operator.
     *
     * @param other LogisticFlow object to be assigned.
     * @return Reference to the modified LogisticFlow object.
     */
    LogisticFlow& operator=(const LogisticFlow& other);

    /**
     * @brief Calculates and returns the logistic flow.
     *
     * @return Flow value calculated by the logistic function.
     *
     * @details
     * Implements the formula: 0.3 * P * (1 - P/pmax)
     * If the sink system is null, returns 0.
     */
    double execute() override;
};

#endif