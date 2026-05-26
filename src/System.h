/**
 * @file System.h
 * @brief Definition of the System class.
 *
 * @details
 * The System class represents a fundamental component of the simulation,
 * maintaining a state (value) identified by a name. Systems are
 * connected through flows to form transfer networks.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/**
 * @class System
 * @brief Represents a system with variable state in the simulation.
 *
 * @details
 * A system has an identifier name and a value that represents
 * its current state. Systems can be connected through flows
 * to transfer values between them during simulation execution.
 *
 * @author Development Team
 * @version 1.0
 * @date 2024
 */
class System {
private:
    string name;    /**< Identifier name of the system */
    double value;   /**< Current value of the system state */

public:
    /**
     * @brief Default constructor of the System class.
     *
     * Initializes the system with empty name and zero value.
     */
    System();
    /**
     * @brief Constructor with parameters.
     *
     * @param name Identifier name of the system.
     * @param value Initial value of the system state.
     */
    System(const string& name, double value);
    /**
     * @brief Virtual destructor.
     */
    virtual ~System();

    /**
     * @brief Copy constructor.
     *
     * @param other System object to be copied.
     */
    System(const System& other);
    /**
     * @brief Assignment operator.
     *
     * @param other System object to be assigned.
     * @return Reference to the modified System object.
     */
    System& operator=(const System& other);

    /**
     * @brief Sets the name of the system.
     *
     * @param name New name of the system.
     */
    void setName(const string& name);
    /**
     * @brief Sets the value of the system state.
     *
     * @param value New value of the state.
     */
    void setValue(double value);

    /**
     * @brief Gets the name of the system.
     *
     * @return Name of the system.
     */
    string getName() const;
    /**
     * @brief Gets the current value of the system.
     *
     * @return Current value of the state.
     */
    double getValue() const;
};

#endif