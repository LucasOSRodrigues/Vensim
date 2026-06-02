#include <assert.h>
#include <string>
#include "unit_System.h"
#include "../../src/System.h"
#include "../../src/SystemImpl.h"

using namespace std;

/**
 * @brief Test the default constructor of System.
 *
 * Tests that a SystemImpl created with the default constructor has:
 * - Empty name
 * - Value of 0.0
 */
void unit_System_defaultConstructor(void) {
    SystemImpl s;
    assert(s.getName() == "");
    assert(s.getValue() == 0.0);
}

/**
 * @brief Test the parameterized constructor of System.
 *
 * Tests that a SystemImpl created with parameters is initialized correctly
 * with the provided name and value.
 */
void unit_System_parameterizedConstructor(void) {
    SystemImpl s1("Tank", 100.0);
    assert(s1.getName() == "Tank");
    assert(s1.getValue() == 100.0);

    SystemImpl s2("Reservoir", 50.5);
    assert(s2.getName() == "Reservoir");
    assert(s2.getValue() == 50.5);
}

/**
 * @brief Test the copy constructor of System.
 *
 * Tests that a SystemImpl created as a copy of another System
 * has the same name and value.
 */
void unit_System_copyConstructor(void) {
    SystemImpl original("Source", 75.0);
    SystemImpl copy(original);

    assert(copy.getName() == "Source");
    assert(copy.getValue() == 75.0);

    // Verify they are independent objects
    copy.setValue(25.0);
    assert(original.getValue() == 75.0);
    assert(copy.getValue() == 25.0);
}

/**
 * @brief Test the destructor of System.
 *
 * Tests that the destructor can be called without errors.
 * Since SystemImpl doesn't manage dynamic memory, this is a simple test.
 */
void unit_System_destructor(void) {
    System* s = new SystemImpl("Test", 10.0);
    delete s;
    // If no errors occur, the destructor works correctly
}

/**
 * @brief Test the assignment operator of System.
 *
 * Tests that the assignment operator correctly copies the name and value
 * from one SystemImpl to another, and handles self-assignment properly.
 */
void unit_System_assignmentOperator(void) {
    SystemImpl s1("Original", 30.0);
    SystemImpl s2("Other", 50.0);

    s2 = s1;
    assert(s2.getName() == "Original");
    assert(s2.getValue() == 30.0);

    // Test self-assignment
    s1 = s1;
    assert(s1.getName() == "Original");
    assert(s1.getValue() == 30.0);
}

/**
 * @brief Test the setName method of System.
 *
 * Tests that setName correctly updates the name of the System.
 */
void unit_System_setName(void) {
    SystemImpl s("InitialName", 10.0);
    assert(s.getName() == "InitialName");

    s.setName("NewName");
    assert(s.getName() == "NewName");

    s.setName("");
    assert(s.getName() == "");
}

/**
 * @brief Test the setValue method of System.
 *
 * Tests that setValue correctly updates the value of the System.
 */
void unit_System_setValue(void) {
    SystemImpl s("TestSystem", 0.0);
    assert(s.getValue() == 0.0);

    s.setValue(100.0);
    assert(s.getValue() == 100.0);

    s.setValue(-50.5);
    assert(s.getValue() == -50.5);

    s.setValue(0.0);
    assert(s.getValue() == 0.0);
}

/**
 * @brief Test the getName method of System.
 *
 * Tests that getName correctly returns the name of the System.
 */
void unit_System_getName(void) {
    SystemImpl s1("MySystem", 10.0);
    assert(s1.getName() == "MySystem");

    SystemImpl s2;
    assert(s2.getName() == "");

    s2.setName("AnotherSystem");
    assert(s2.getName() == "AnotherSystem");
}

/**
 * @brief Test the getValue method of System.
 *
 * Tests that getValue correctly returns the current value of the System.
 */
void unit_System_getValue(void) {
    SystemImpl s1("Tank", 100.0);
    assert(s1.getValue() == 100.0);

    SystemImpl s2;
    assert(s2.getValue() == 0.0);

    s2.setValue(75.5);
    assert(s2.getValue() == 75.5);
}

/**
 * @brief Runs all unit tests for the SystemImpl class.
 */
void run_unit_test_System(void) {
    unit_System_defaultConstructor();
    unit_System_parameterizedConstructor();
    unit_System_copyConstructor();
    unit_System_destructor();
    unit_System_assignmentOperator();
    unit_System_setName();
    unit_System_setValue();
    unit_System_getName();
    unit_System_getValue();
}
