#ifndef UNIT_MODEL
#define UNIT_MODEL

/**
 * @file unit_Model.h
 * @brief Unit tests for the Model class.
 */

// Constructor tests
void unit_Model_defaultConstructor(void);
void unit_Model_copyConstructor(void);

// Destructor test
void unit_Model_destructor(void);

// Assignment operator test
void unit_Model_assignmentOperator(void);

// Add system test
void unit_Model_addSystem(void);

// Add flow test
void unit_Model_addFlow(void);

// Run simulation test
void unit_Model_run(void);

// Runner function
void run_unit_test_Model(void);

#endif // UNIT_MODEL
