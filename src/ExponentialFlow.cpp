#include "ExponentialFlow.h"

ExponentialFlow::ExponentialFlow() : Flow() {}

ExponentialFlow::ExponentialFlow(System* source, System* sink)
    : Flow(source, sink) {}

ExponentialFlow::~ExponentialFlow() = default;

ExponentialFlow::ExponentialFlow(const ExponentialFlow& other)
    : Flow(other) {}

ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

double ExponentialFlow::execute() {
    if (sink != nullptr) {
        return 0.3 * sink->getValue();
    }
    return 0;
}