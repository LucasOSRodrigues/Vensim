#ifndef MYSIM_H
#define MYSIM_H


/**
 * @file MySim.h
 * @brief Main header file for the MySim library.
 *
 * @mainpage MySim - Systems Dynamics Simulation Framework
 *
 * @section intro Introduction
 * MySim is a C++ framework for simulating dynamic systems using the concept
 * of stocks and flows, similar to the Systems Dynamics approach
 * of Vensim software.
 *
 * @section components Main Components
 *
 * - **System**: Represents a stock (accumulator) that maintains a value over time.
 * - **Flow**: Abstract class for different types of transfer flows.
 * - **ExponentialFlow**: Implements exponential growth.
 * - **LogisticFlow**: Implements logistic growth with limit.
 * - **ComplexFlow**: Implements flow with specific rule.
 * - **Model**: Orchestrates the simulation, managing systems and flows.
 *
 * @section usage Basic Usage
 *
 * Example of creating a simulation:
 * @code
 * Model sim;
 * System stock1("Stock 1", 100.0);
 * System stock2("Stock 2", 0.0);
 * ExponentialFlow flow(&stock1, &stock2);
 *
 * sim.add(&stock1);
 * sim.add(&stock2);
 * sim.add(&flow);
 * sim.run(0, 100);
 * @endcode
 *
 * @author Development Team
 * @version 1.0
 * @date 2024
 *
 * @details
 * Bundles all simulator classes for easy framework utilization.
 */

#include "System.h"
#include "Flow.h"
#include "ExponentialFlow.h"
#include "LogisticFlow.h"
#include "ComplexFlow.h"
#include "Model.h"

#endif