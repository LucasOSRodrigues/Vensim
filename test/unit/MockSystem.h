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
    MockSystem();

    MockSystem(const string& n, double v);

    virtual ~MockSystem();

    // Setters
    virtual void setName(const string& n) override;

    virtual void setValue(double v) override;

    // Getters
    virtual string getName() const override;

    virtual double getValue() const override;

    // Mock-specific methods for testing
    /**
     * @brief Verify if a method was called.
     * @param methodName The name of the method to check
     * @return true if the method was called, false otherwise
     */
    bool wasCalled(const string& methodName) const;

    /**
     * @brief Get the number of times a method was called.
     * @param methodName The name of the method to check
     * @return The number of times the method was called
     */
    int getCallCount(const string& methodName) const;

    /**
     * @brief Clear the call history.
     */
    void clearCallHistory();

    /**
     * @brief Get all calls made to this mock.
     * @return Vector of method names that were called
     */
    vector<string> getCallHistory() const;
};

#endif // MOCK_SYSTEM_H
