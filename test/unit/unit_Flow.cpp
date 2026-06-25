#include <assert.h>
#include "unit_Flow.h"
#include "mocks.h"
#include "../../src/FlowImpl.h"
#include "../../src/System.h"

/**
 * @brief Concrete implementation of Flow for testing purposes.
 *
 * Since Flow is abstract, we create a simple concrete implementation
 * with a fixed return value for testing the base Flow functionality.
 */
class TestFlow : public FlowImpl {
public:
    TestFlow() : FlowImpl() {}
    TestFlow(System* source, System* sink) : FlowImpl(source, sink) {}
    virtual double execute(void) {
        return 10.0;
    }
};

/**
 * @brief Test the default constructor of Flow.
 *
 * Tests that a Flow created with the default constructor has
 * null source and sink pointers.
 */
void unit_Flow_defaultConstructor(void) {
    TestFlow f;
    assert(f.getSource() == nullptr);
    assert(f.getSink() == nullptr);
}

/**
 * @brief Test the parameterized constructor of Flow.
 *
 * Tests that a Flow created with source and sink systems
 * is initialized correctly with those pointers.
 */
void unit_Flow_parameterizedConstructor(void) {
    System* source = new MockSystem("Source", 100.0);
    System* sink = new MockSystem("Sink", 0.0);

    TestFlow f(source, sink);
    assert(f.getSource() == source);
    assert(f.getSink() == sink);

    delete source;
    delete sink;
}

/**
 * @brief Test the copy constructor of Flow.
 *
 * Tests that a Flow created as a copy of another Flow
 * has the same source and sink pointers.
 */
void unit_Flow_copyConstructor(void) {
    System* source = new MockSystem("Source", 100.0);
    System* sink = new MockSystem("Sink", 0.0);

    TestFlow original(source, sink);
    TestFlow copy(original);

    assert(copy.getSource() == source);
    assert(copy.getSink() == sink);

    delete source;
    delete sink;
}

/**
 * @brief Test the destructor of Flow.
 *
 * Tests that the destructor can be called without errors.
 */
void unit_Flow_destructor(void) {
    System* source = new MockSystem("Source", 100.0);
    System* sink = new MockSystem("Sink", 0.0);

    TestFlow* f = new TestFlow(source, sink);
    delete f;

    // If no errors occur, the destructor works correctly
    // Note: the Flow destructor does not delete source and sink
    delete source;
    delete sink;
}

/**
 * @brief Test the assignment operator of Flow.
 *
 * Tests that the assignment operator correctly copies the flow,
 * and handles self-assignment properly.
 */
void unit_Flow_assignmentOperator(void) {
    System* s1 = new MockSystem("Source1", 100.0);
    System* s2 = new MockSystem("Sink1", 0.0);
    System* s3 = new MockSystem("Source2", 50.0);
    System* s4 = new MockSystem("Sink2", 25.0);

    TestFlow f1(s1, s2);
    TestFlow f2(s3, s4);

    f2 = f1;
    assert(f2.getSource() == s1);
    assert(f2.getSink() == s2);

    // Test self-assignment
    f1 = f1;
    assert(f1.getSource() == s1);
    assert(f1.getSink() == s2);

    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

/**
 * @brief Test the getSource method of Flow.
 *
 * Tests that getSource correctly returns the source system pointer.
 */
void unit_Flow_getSource(void) {
    System* source = new MockSystem("Source", 100.0);
    System* sink = new MockSystem("Sink", 0.0);

    TestFlow f1;
    assert(f1.getSource() == nullptr);

    TestFlow f2(source, sink);
    assert(f2.getSource() == source);
    assert(f2.getSource()->getValue() == 100.0);
    assert(f2.getSource()->getName() == "Source");

    delete source;
    delete sink;
}

/**
 * @brief Test the getSink method of Flow.
 *
 * Tests that getSink correctly returns the sink system pointer.
 */
void unit_Flow_getSink(void) {
    System* source = new MockSystem("Source", 100.0);
    System* sink = new MockSystem("Sink", 0.0);

    TestFlow f1;
    assert(f1.getSink() == nullptr);

    TestFlow f2(source, sink);
    assert(f2.getSink() == sink);
    assert(f2.getSink()->getValue() == 0.0);
    assert(f2.getSink()->getName() == "Sink");

    delete source;
    delete sink;
}

/**
 * @brief Runs all unit tests for the Flow class.
 */
void run_unit_test_Flow(void) {
    unit_Flow_defaultConstructor();
    unit_Flow_parameterizedConstructor();
    unit_Flow_copyConstructor();
    unit_Flow_destructor();
    unit_Flow_assignmentOperator();
    unit_Flow_getSource();
    unit_Flow_getSink();
}
