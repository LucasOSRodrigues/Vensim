#ifndef MOCK_SYSTEM_H
#define MOCK_SYSTEM_H

#include "../../src/System.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Mock implementation of System interface for testing.
 *
 * This mock allows you to:
 * - Set predefined values for testing
 * - Verify method calls
 * - Track call history
 */
class MockSystem : public System {
private:
    string name;
    double value;
    mutable vector<string> callHistory;  // Track method calls

public:
    MockSystem() : name(""), value(0.0) {}

    MockSystem(const string& n, double v) : name(n), value(v) {}

    virtual ~MockSystem() = default;

    // Setters
    virtual void setName(const string& n) override {
        callHistory.push_back("setName");
        name = n;
    }

    virtual void setValue(double v) override {
        callHistory.push_back("setValue");
        value = v;
    }

    // Getters
    virtual string getName() const override {
        callHistory.push_back("getName");
        return name;
    }

    virtual double getValue() const override {
        callHistory.push_back("getValue");
        return value;
    }

    // Mock-specific methods for testing
    /**
     * @brief Verify if a method was called.
     * @param methodName The name of the method to check
     * @return true if the method was called, false otherwise
     */
    bool wasCalled(const string& methodName) const {
        for (const auto& call : callHistory) {
            if (call == methodName) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Get the number of times a method was called.
     * @param methodName The name of the method to check
     * @return The number of times the method was called
     */
    int getCallCount(const string& methodName) const {
        int count = 0;
        for (const auto& call : callHistory) {
            if (call == methodName) {
                count++;
            }
        }
        return count;
    }

    /**
     * @brief Clear the call history.
     */
    void clearCallHistory() {
        callHistory.clear();
    }

    /**
     * @brief Get all calls made to this mock.
     * @return Vector of method names that were called
     */
    vector<string> getCallHistory() const {
        return callHistory;
    }
};

#endif // MOCK_SYSTEM_H
