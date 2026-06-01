#ifndef UNIT_FLOW
#define UNIT_FLOW

/**
 * @file unit_Flow.h
 * @brief Unit tests for the Flow class.
 */

// Constructor tests
void unit_Flow_defaultConstructor(void);
void unit_Flow_parameterizedConstructor(void);
void unit_Flow_copyConstructor(void);

// Destructor test
void unit_Flow_destructor(void);

// Assignment operator test
void unit_Flow_assignmentOperator(void);

// Getter tests
void unit_Flow_getSource(void);
void unit_Flow_getSink(void);

// Runner function
void run_unit_test_Flow(void);

#endif // UNIT_FLOW
