/**
 * @file unit_tests.h
 * @brief Unit tests for individual components of MySim framework.
 *
 * @details
 * This file defines the interface for unit tests that validate
 * the behavior of individual classes and methods in isolation.
 * Tests cover basic functionality of System and Flow classes.
 */

#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

/**
 * @brief Unit test for System class.
 *
 * Validates System creation, getters, and setters.
 * Tests:
 * - System creation with name and value
 * - getName() and getValue() methods
 * - setName() and setValue() methods
 */
void systemUnitTest();

/**
 * @brief Unit test for ExponentialFlow class.
 *
 * Validates ExponentialFlow execution method.
 * Tests the formula: flow = 0.3 * sink_value
 * with sink value of 100, expecting result of 30.
 */
void exponentialFlowUnitTest();

/**
 * @brief Unit test for LogisticFlow class.
 *
 * Validates LogisticFlow execution method.
 * Tests the formula: flow = 0.3 * P * (1 - P/pmax)
 * with P=10 and pmax=70.
 */
void logisticFlowUnitTest();

#endif
