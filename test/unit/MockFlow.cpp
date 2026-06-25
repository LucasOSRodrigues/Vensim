#include "MockFlow.h"

MockFlow::MockFlow()
    : source(nullptr), sink(nullptr), executeReturnValue(0.0) {}

MockFlow::MockFlow(System* src, System* snk, double returnValue)
    : source(src), sink(snk), executeReturnValue(returnValue) {}

MockFlow::~MockFlow() = default;

double MockFlow::execute() {
    callHistory.push_back("execute");
    return executeReturnValue;
}

System* MockFlow::getSource() const {
    callHistory.push_back("getSource");
    return source;
}

System* MockFlow::getSink() const {
    callHistory.push_back("getSink");
    return sink;
}

void MockFlow::setSource(System* src) {
    source = src;
}

void MockFlow::setSink(System* snk) {
    sink = snk;
}

void MockFlow::setExecuteReturnValue(double value) {
    executeReturnValue = value;
}

bool MockFlow::wasCalled(const string& methodName) const {
    for (const auto& call : callHistory) {
        if (call == methodName) {
            return true;
        }
    }
    return false;
}

int MockFlow::getCallCount(const string& methodName) const {
    int count = 0;
    for (const auto& call : callHistory) {
        if (call == methodName) {
            count++;
        }
    }
    return count;
}

bool MockFlow::executeCalledTimes(int times) const {
    return getCallCount("execute") == times;
}

void MockFlow::clearCallHistory() {
    callHistory.clear();
}

vector<string> MockFlow::getCallHistory() const {
    return callHistory;
}
