#include <assert.h>
#include "unit_HandleBody.h"
#include "../../src/handleBody.h"

class TestBody : public Body {
private:
    int value;

public:
    TestBody() : value(0) {}
    void setValue(int value) { this->value = value; }
    int getValue() const { return value; }

    friend class Handle<TestBody>;
    friend class TestHandle;
};

class TestHandle : public Handle<TestBody> {
public:
    TestHandle() : Handle<TestBody>() {}
    void setValue(int value) { pImpl_->setValue(value); }
    int getValue() const { return pImpl_->getValue(); }
    int getRefCount() const { return pImpl_->refCount(); }
};

void unit_HandleBody_referenceCounting(void) {
    TestHandle h1;
    assert(h1.getRefCount() == 1);

    TestHandle h2(h1);
    assert(h1.getRefCount() == 2);
    assert(h2.getRefCount() == 2);

    h1.setValue(10);
    assert(h2.getValue() == 10);
}

void unit_HandleBody_assignment(void) {
    TestHandle h1;
    TestHandle h2;

    h1.setValue(25);
    h2 = h1;

    assert(h1.getRefCount() == 2);
    assert(h2.getRefCount() == 2);
    assert(h2.getValue() == 25);
}

void unit_HandleBody_debugCounters(void) {
    int handlesCreatedBefore = numHandleCreated;
    int handlesDeletedBefore = numHandleDeleted;
    int bodiesCreatedBefore = numBodyCreated;
    int bodiesDeletedBefore = numBodyDeleted;

    {
        TestHandle h1;
        TestHandle h2(h1);
        TestHandle h3;
        h3 = h1;

        assert(numHandleCreated == handlesCreatedBefore + 3);
        assert(numBodyCreated == bodiesCreatedBefore + 2);
    }

    assert(numHandleDeleted == handlesDeletedBefore + 3);
    assert(numBodyDeleted == bodiesDeletedBefore + 2);
}

void run_unit_test_HandleBody(void) {
    unit_HandleBody_referenceCounting();
    unit_HandleBody_assignment();
    unit_HandleBody_debugCounters();
}
