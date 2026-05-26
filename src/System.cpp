/**
 * @file System.cpp
 * @brief Implementation of the System class.
 *
 * @details
 * Contains the implementation of all methods of the System class,
 * including constructors, destructors, and access and modification methods.
 */

#include "System.h"

/**
 * @brief Implementation of the default constructor.
 *
 * Initializes the name as empty string and value as 0.0.
 */
System::System() : name(""), value(0.0) {}

/**
 * @brief Implementation of the constructor with parameters.
 *
 * Initializes the system with the provided name and value.
 */
System::System(const string& name, double value)
    : name(name), value(value) {}

/**
 * @brief Virtual destructor.
 */
System::~System() = default;

/**
 * @brief Implementation of the copy constructor.
 *
 * Copies the name and state values from the original object.
 */
System::System(const System& other)
    : name(other.name), value(other.value) {}

/**
 * @brief Implementation of the assignment operator.
 *
 * Checks self-assignment before copying the values.
 */
System& System::operator=(const System& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

/**
 * @brief Sets the name of the system.
 */
void System::setName(const string& name) {
    this->name = name;
}

/**
 * @brief Sets the value of the system state.
 */
void System::setValue(double value) {
    this->value = value;
}

/**
 * @brief Returns the name of the system.
 */
string System::getName() const {
    return name;
}

/**
 * @brief Returns the current value of the system.
 */
double System::getValue() const {
    return value;
}