#include "MockSystem.h"

MockSystem::MockSystem() : name(""), value(0.0) {}

MockSystem::MockSystem(const string& n, double v) : name(n), value(v) {}

MockSystem::~MockSystem() = default;

void MockSystem::setName(const string& n) {
    callHistory.push_back("setName");
    name = n;
}

void MockSystem::setValue(double v) {
    callHistory.push_back("setValue");
    value = v;
}

string MockSystem::getName() const {
    callHistory.push_back("getName");
    return name;
}

double MockSystem::getValue() const {
    callHistory.push_back("getValue");
    return value;
}

bool MockSystem::wasCalled(const string& methodName) const {
    for (const auto& call : callHistory) {
        if (call == methodName) {
            return true;
        }
    }
    return false;
}

int MockSystem::getCallCount(const string& methodName) const {
    int count = 0;
    for (const auto& call : callHistory) {
        if (call == methodName) {
            count++;
        }
    }
    return count;
}

void MockSystem::clearCallHistory() {
    callHistory.clear();
}

vector<string> MockSystem::getCallHistory() const {
    return callHistory;
}
