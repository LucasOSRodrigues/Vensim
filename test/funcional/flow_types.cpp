#include "flow_types.h"

ExponentialFlow::ExponentialFlow() : FlowImpl() {}
ExponentialFlow::ExponentialFlow(System* source, System* sink)
    : FlowImpl(source, sink) {}
ExponentialFlow::ExponentialFlow(const string& name, System* source, System* sink)
    : FlowImpl(name, source, sink) {}
ExponentialFlow::~ExponentialFlow() = default;
ExponentialFlow::ExponentialFlow(const ExponentialFlow& other)
    : FlowImpl(other) {}
ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this != &other) {
        FlowImpl::operator=(other);
    }
    return *this;
}
double ExponentialFlow::execute() {
    System* sink = getSink();
    if (sink != nullptr) {
        return 0.3 * sink->getValue();
    }
    return 0.0;
}

LogisticFlow::LogisticFlow() : FlowImpl(), pmax(0.0) {}
LogisticFlow::LogisticFlow(System* source, System* sink, double pmax)
    : FlowImpl(source, sink), pmax(pmax) {}
LogisticFlow::LogisticFlow(const string& name, System* source, System* sink, double pmax)
    : FlowImpl(name, source, sink), pmax(pmax) {}
LogisticFlow::~LogisticFlow() = default;
LogisticFlow::LogisticFlow(const LogisticFlow& other)
    : FlowImpl(other), pmax(other.pmax) {}
LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this != &other) {
        FlowImpl::operator=(other);
        pmax = other.pmax;
    }
    return *this;
}
double LogisticFlow::execute() {
    System* sink = getSink();
    if (sink != nullptr && pmax != 0.0) {
        double P = sink->getValue();
        return 0.3 * P * (1 - P / pmax);
    }
    return 0.0;
}

ComplexFlow::ComplexFlow() : FlowImpl() {}
ComplexFlow::ComplexFlow(System* source, System* sink)
    : FlowImpl(source, sink) {}
ComplexFlow::ComplexFlow(const string& name, System* source, System* sink)
    : FlowImpl(name, source, sink) {}
ComplexFlow::~ComplexFlow() = default;
ComplexFlow::ComplexFlow(const ComplexFlow& other)
    : FlowImpl(other) {}
ComplexFlow& ComplexFlow::operator=(const ComplexFlow& other) {
    if (this != &other) {
        FlowImpl::operator=(other);
    }
    return *this;
}
double ComplexFlow::execute() {
    System* source = getSource();
    if (source != nullptr) {
        return 0.01 * source->getValue();
    }
    return 0.0;
}
