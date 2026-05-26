/**
 * @file ComplexFlow.h
 * @brief Definition of the ComplexFlow class.
 *
 * @details
 * Implements a specific type of flow that uses a specific calculation rule
 * for transfer between systems.
 */

#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "Flow.h"

/**
 * @class ComplexFlow
 * @brief Implements a flow with specific calculation rule.
 *
 * @details
 * The ComplexFlow calculates the value transferred based on a specific rule
 * that depends on the value of the source system.
 *
 * The formula used is: flow = 0.01 * source_value
 *
 * @author Development Team
 * @version 1.0
 * @date 2024
 */
class ComplexFlow : public Flow {
public:
    /**
     * @brief Default constructor.
     */
    ComplexFlow();
    /**
     * @brief Constructor with parameters.
     *
     * @param source Pointer to the source system.
     * @param sink Pointer to the sink system.
     */
    ComplexFlow(System* source, System* sink);
    /**
     * @brief Virtual destructor.
     */
    virtual ~ComplexFlow();

    /**
     * @brief Copy constructor.
     *
     * @param other ComplexFlow object to be copied.
     */
    ComplexFlow(const ComplexFlow& other);
    /**
     * @brief Assignment operator.
     *
     * @param other ComplexFlow object to be assigned.
     * @return Reference to the modified ComplexFlow object.
     */
    ComplexFlow& operator=(const ComplexFlow& other);

    /**
     * @brief Calculates and returns the complex flow.
     *
     * @return Flow value calculated as 0.01 * source_value.
     *
     * @details
     * The transfer is based on the value of the source system.
     */
    double execute() override;
};

#endif