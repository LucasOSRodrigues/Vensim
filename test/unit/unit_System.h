#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

/**
 * @file unit_System.h
 * @brief Unit tests for the System class.
 */

// Constructor tests
void unit_System_defaultConstructor(void);
void unit_System_parameterizedConstructor(void);
void unit_System_copyConstructor(void);

// Destructor test
void unit_System_destructor(void);

// Assignment operator test
void unit_System_assignmentOperator(void);

// Setter tests
void unit_System_setName(void);
void unit_System_setValue(void);

// Getter tests
void unit_System_getName(void);
void unit_System_getValue(void);

// Runner function
void run_unit_test_System(void);

#endif // UNIT_SYSTEM
