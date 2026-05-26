/**
 * @file Flow.cpp
 * @brief Implementation of the abstract Flow class.
 *
 * @details
 * Contains the implementation of the methods of the Flow base class,
 * except for the pure virtual method execute() which must be implemented
 * by subclasses.
 */

#include "Flow.h"

/**
 * @brief Implementation of the default constructor.
 *
 * Initializes the source and sink pointers as nullptr.
 */
Flow::Flow() : source(nullptr), sink(nullptr) {}

/**
 * @brief Implementation of the constructor with parameters.
 */
Flow::Flow(System* source, System* sink)
    : source(source), sink(sink) {}

/**
 * @brief Virtual destructor.
 */
Flow::~Flow() = default;

/**
 * @brief Implementation of the copy constructor.
 */
Flow::Flow(const Flow& other)
    : source(other.source), sink(other.sink) {}

/**
 * @brief Implementation of the assignment operator.
 *
 * Checks self-assignment before copying the pointers.
 */
Flow& Flow::operator=(const Flow& other) {
    if (this != &other) {
        source = other.source;
        sink = other.sink;
    }
    return *this;
}

/**
 * @brief Returns the pointer to the source system.
 */
System* Flow::getSource() const {
    return source;
}

/**
 * @brief Returns the pointer to the sink system.
 */
System* Flow::getSink() const {
    return sink;
}