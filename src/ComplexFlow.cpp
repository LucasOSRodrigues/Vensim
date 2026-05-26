#include "ComplexFlow.h"

ComplexFlow::ComplexFlow() : Flow() {}

ComplexFlow::ComplexFlow(System* source, System* sink)
    : Flow(source, sink) {}

ComplexFlow::~ComplexFlow() = default;

ComplexFlow::ComplexFlow(const ComplexFlow& other)
    : Flow(other) {}

ComplexFlow& ComplexFlow::operator=(const ComplexFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

double ComplexFlow::execute() {
    return 0.01 * source->getValue();
}