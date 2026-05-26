#include "LogisticFlow.h"

LogisticFlow::LogisticFlow() : Flow(), pmax(0.0) {}

LogisticFlow::LogisticFlow(System* source, System* sink, double pmax)
    : Flow(source, sink), pmax(pmax) {}

LogisticFlow::~LogisticFlow() = default;

LogisticFlow::LogisticFlow(const LogisticFlow& other)
    : Flow(other), pmax(other.pmax) {}

LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
        pmax = other.pmax;
    }
    return *this;
}

double LogisticFlow::execute() {
    if (sink != nullptr) {
        double P = sink->getValue();
        return 0.3 * P * (1 - P / pmax);
    }
    return 0;
}