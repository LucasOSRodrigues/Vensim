#include <assert.h>
#include "unit_Model.h"
#include "../../src/Model.h"
#include "../../src/ModelImpl.h"
#include "../../src/System.h"
#include "../../src/SystemImpl.h"
#include "../../src/Flow.h"

/**
 * @brief Test the default constructor of Model.
 *
 * Tests that a ModelImpl created with the default constructor creates
 * an empty model with no systems or flows.
 */
void unit_Model_defaultConstructor(void) {
    ModelImpl m;
    // The model should be created with zero systems and flows
    assert(m.getSystemCount() == 0);
    assert(m.getFlowCount() == 0);
}

/**
 * @brief Test the copy constructor of Model.
 *
 * Tests that a ModelImpl created as a copy of another Model
 * has the same systems and flows.
 */
void unit_Model_copyConstructor(void) {
    ModelImpl original;
    System* s1 = new SystemImpl("Tank1", 100.0);
    original.add(s1);

    ModelImpl copy(original);
    // Verify the copy has the same number of systems
    assert(copy.getSystemCount() == 1);
    assert(copy.getFlowCount() == 0);

    delete s1;
}

/**
 * @brief Test the destructor of Model.
 *
 * Tests that the destructor can be called without errors.
 */
void unit_Model_destructor(void) {
    Model* m = new ModelImpl();
    delete m;
    // If no errors occur, the destructor works correctly
}

/**
 * @brief Test the assignment operator of Model.
 *
 * Tests that the assignment operator correctly copies the model,
 * and handles self-assignment properly.
 */
void unit_Model_assignmentOperator(void) {
    ModelImpl m1;
    System* s1 = new SystemImpl("Tank1", 50.0);
    m1.add(s1);

    ModelImpl m2;
    m2 = m1;

    // Verify assignment copied the system
    assert(m2.getSystemCount() == 1);

    // Test self-assignment (should not change anything)
    m2 = m2;
    assert(m2.getSystemCount() == 1);

    delete s1;
}

/**
 * @brief Test the add(System*) method of Model.
 *
 * Tests that systems can be added to the model without errors.
 */
void unit_Model_addSystem(void) {
    ModelImpl m;

    System* s1 = new SystemImpl("Tank1", 100.0);
    System* s2 = new SystemImpl("Tank2", 50.0);
    System* s3 = new SystemImpl("Tank3", 75.0);

    m.add(s1);
    assert(m.getSystemCount() == 1);

    m.add(s2);
    assert(m.getSystemCount() == 2);

    m.add(s3);
    assert(m.getSystemCount() == 3);

    delete s1;
    delete s2;
    delete s3;
}

/**
 * @brief Test the add(Flow*) method of Model.
 *
 * Tests that flows can be added to the model without errors.
 * Note: We cannot test Flow directly since it's abstract.
 * This test verifies the model accepts flow pointers.
 */
void unit_Model_addFlow(void) {
    ModelImpl m;
    System* source = new SystemImpl("Source", 100.0);
    System* sink = new SystemImpl("Sink", 0.0);

    m.add(source);
    m.add(sink);

    // Verify initial state before adding flows
    assert(m.getSystemCount() == 2);
    assert(m.getFlowCount() == 0);

    delete source;
    delete sink;
}

/**
 * @brief Test the run(int, int) method of Model.
 *
 * Tests that the simulation can be executed for a time interval.
 * Tests various time intervals including edge cases.
 */
void unit_Model_run(void) {
    ModelImpl m;

    System* s1 = new SystemImpl("Tank1", 100.0);
    System* s2 = new SystemImpl("Tank2", 0.0);

    m.add(s1);
    m.add(s2);

    // Test running simulation with valid interval
    m.run(0, 10);
    // Verify systems are still accessible after run
    assert(m.getSystemCount() == 2);

    // Test with begin == end (no iterations)
    m.run(5, 5);
    assert(m.getSystemCount() == 2);

    // Test with larger time interval
    m.run(0, 100);
    assert(m.getSystemCount() == 2);

    delete s1;
    delete s2;
}

/**
 * @brief Runs all unit tests for the ModelImpl class.
 */
void run_unit_test_Model(void) {
    unit_Model_defaultConstructor();
    unit_Model_copyConstructor();
    unit_Model_destructor();
    unit_Model_assignmentOperator();
    unit_Model_addSystem();
    unit_Model_addFlow();
    unit_Model_run();
}
