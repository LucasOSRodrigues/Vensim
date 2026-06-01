/**
 * @file main.cpp
 * @brief Main entry point for unit tests.
 *
 * This file includes all unit test headers and invokes the test runner
 * functions for each class and global functions.
 */

#include <iostream>
#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Model.h"
#include "unit_Flow.h"

using namespace std;

/**
 * @brief Main function that runs all unit tests.
 *
 * This function:
 * 1. Runs all tests for global functions
 * 2. Runs all tests for the System class
 * 3. Runs all tests for the Model class
 * 4. Runs all tests for the Flow class
 *
 * @return 0 if all tests pass, non-zero if any test fails
 */
int main(void) {
    cout << "Starting unit tests..." << endl;

    try {
        cout << "Running global function tests..." << endl;
        run_unit_test_globals();
        cout << "✓ Global function tests passed!" << endl;

        cout << "Running System class tests..." << endl;
        run_unit_test_System();
        cout << "✓ System class tests passed!" << endl;

        cout << "Running Model class tests..." << endl;
        run_unit_test_Model();
        cout << "✓ Model class tests passed!" << endl;

        cout << "Running Flow class tests..." << endl;
        run_unit_test_Flow();
        cout << "✓ Flow class tests passed!" << endl;

        cout << "\n✓ All unit tests passed successfully!" << endl;
        return 0;
    }
    catch (const exception& e) {
        cerr << "\n✗ Test execution failed: " << e.what() << endl;
        return 1;
    }
}
