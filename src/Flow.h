/**
 * @file Flow.h
 * @brief Definition of the abstract Flow class.
 *
 * @details
 * The Flow class defines the interface for flows that transfer values
 * between systems in the simulation. Flows are responsible for calculating
 * the amount of value that will be transferred from one system to another.
 */

#ifndef FLOW_H
#define FLOW_H

#include "System.h"

/**
 * @class Flow
 * @brief Abstract class that represents a flow between systems.
 *
 * @details
 * A flow transfers values between a source system and a sink system
 * during each iteration of the simulation. Subclasses implement
 * different transfer rules.
 *
 */
class Flow {
protected:
    System* source;   /**< Pointer to the source system of the flow */
    System* sink;     /**< Pointer to the sink system of the flow */

public:
    /**
     * @brief Default constructor.
     *
     * Initializes a flow with null source and sink.
     */
    Flow();
    /**
     * @brief Constructor with parameters.
     *
     * @param source Pointer to the source system.
     * @param sink Pointer to the sink system.
     */
    Flow(System* source, System* sink);
    /**
     * @brief Virtual destructor.
     */
    virtual ~Flow();

    /**
     * @brief Copy constructor.
     *
     * @param other Flow object to be copied.
     */
    Flow(const Flow& other);
    /**
     * @brief Assignment operator.
     *
     * @param other Flow object to be assigned.
     * @return Reference to the modified Flow object.
     */
    Flow& operator=(const Flow& other);

    /**
     * @brief Executes the flow calculation.
     *
     * Pure virtual method that must be implemented by subclasses
     * to calculate the value transferred in this iteration.
     *
     * @return Value to be transferred from source to sink system.
     */
    virtual double execute() = 0;

    /**
     * @brief Gets the source system of the flow.
     *
     * @return Pointer to the source system.
     */
    System* getSource() const;
    /**
     * @brief Gets the sink system of the flow.
     *
     * @return Pointer to the sink system.
     */
    System* getSink() const;
};

#endif