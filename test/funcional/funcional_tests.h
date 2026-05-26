/**
 * @file funcional_tests.h
 * @brief Functional tests for the MySim framework.
 *
 * @details
 * This file defines the interface for functional tests that validate
 * the behavior of the entire simulation system with complete workflows.
 * Tests verify population dynamics models with different flow types.
 */

#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

/**
 * @brief Functional test for exponential flow.
 *
 * Validates that exponential flow correctly simulates population growth
 * following an exponential curve. Tests with initial population of 10
 * over 10 time units.
 *
 * Expected behavior: P(10) = 10 * 1.3^10 ≈ 137.858491849
 */
void exponentialFuncionalTest();

/**
 * @brief Functional test for logistic flow.
 *
 * Validates that logistic flow correctly simulates bounded population growth.
 * Tests with initial population of 10, maximum population of 70,
 * over 100 time units. Population should stabilize at maximum.
 *
 * Expected behavior: Population converges to approximately 70
 */
void logisticalFuncionalTest();

/**
 * @brief Functional test for complex flow network.
 *
 * Validates a complex system with 5 systems (Q1-Q5) connected by
 * 6 complex flows forming a network. Verifies the final state
 * of all systems after 100 simulation steps.
 *
 * Expected results:
 * - Q1 ≈ 31.8513
 * - Q2 ≈ 18.4003
 * - Q3 ≈ 77.1143
 * - Q4 ≈ 56.1728
 * - Q5 ≈ 16.4612
 */
void complexFuncionalTest();

#endif
