/**
 * @file Model.h
 * @brief Definition of the Model class.
 *
 * @details
 * The Model class is responsible for orchestrating the simulation,
 * managing systems and flows, and executing the temporal evolution
 * of the system.
 */

#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "System.h"
#include "Flow.h"

using namespace std;

/**
 * @class Model
 * @brief Class responsible for executing the simulation.
 *
 * @details
 * The model contains and manages a set of systems and flows.
 * It is responsible for storing them and executing the temporal
 * evolution of the simulation, applying the transfer rules
 * between systems in each iteration.
 *
 * @author Development Team
 * @version 1.0
 * @date 2024
 */
class Model {
private:
    vector<System*> systems;  /**< Vector of pointers to systems in the model */
    vector<Flow*> flows;      /**< Vector of pointers to flows in the model */

public:
    /**
     * @brief Default constructor.
     *
     * Initializes an empty model.
     */
    Model();
    /**
     * @brief Virtual destructor.
     */
    virtual ~Model();

    /**
     * @brief Copy constructor.
     *
     * @param other Model object to be copied.
     */
    Model(const Model& other);
    /**
     * @brief Assignment operator.
     *
     * @param other Model object to be assigned.
     * @return Reference to the modified Model object.
     */
    Model& operator=(const Model& other);

    /**
     * @brief Adds a system to the model.
     *
     * @param system Pointer to the system to be added.
     */
    void add(System* system);

    /**
     * @brief Adds a flow to the model.
     *
     * @param flow Pointer to the flow to be added.
     */
    void add(Flow* flow);

    /**
     * @brief Executes the simulation in the specified time interval.
     *
     * Simulates the evolution of the system from the initial time to the final time,
     * applying flows in each iteration and updating system values.
     *
     * @param begin Initial simulation time (inclusive).
     * @param end Final simulation time (exclusive).
     *
     * @details
     * For each time unit in the interval [begin, end):
     * 1. Calculates the value transferred by each flow
     * 2. Reduces the value of the source system
     * 3. Increases the value of the sink system
     */
    void run(int begin, int end);
};

#endif