#ifndef MOCK_FLOW_H
#define MOCK_FLOW_H

#include "../../src/Flow.h"
#include "../../src/System.h"
#include <vector>

using namespace std;

/**
 * @brief Mock implementation of Flow interface for testing.
 *
 * This mock allows you to:
 * - Set predefined return values for execute()
 * - Verify method calls
 * - Track call history
 * - Configure source and sink systems
 */
class MockFlow : public Flow {
private:
    System* source;
    System* sink;
    double executeReturnValue;
    mutable vector<string> callHistory;  // Track method calls

public:
    MockFlow();

    MockFlow(System* src, System* snk, double returnValue = 0.0);

    virtual ~MockFlow();

    // Main interface method
    virtual double execute() override;

    virtual System* getSource() const override;

    virtual System* getSink() const override;

    // Mock-specific setters for configuration
    /**
     * @brief Set the source system for this flow.
     * @param src Pointer to the source system
     */
    void setSource(System* src);

    /**
     * @brief Set the sink system for this flow.
     * @param snk Pointer to the sink system
     */
    void setSink(System* snk);

    /**
     * @brief Set the return value for the execute() method.
     * @param value The value to be returned by execute()
     */
    void setExecuteReturnValue(double value);

    // Mock-specific methods for testing/verification
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
     * @brief Verify that execute was called a specific number of times.
     * @param times The expected number of times
     * @return true if execute was called exactly 'times' times
     */
    bool executeCalledTimes(int times) const;

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

#endif // MOCK_FLOW_H
