#ifndef FLOW_TYPES_H
#define FLOW_TYPES_H

#include <string>
#include "../../src/FlowImpl.h"

using namespace std;

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow();
    ExponentialFlow(System* source, System* sink);
    ExponentialFlow(const string& name, System* source, System* sink);
    virtual ~ExponentialFlow();

    ExponentialFlow(const ExponentialFlow& other);
    ExponentialFlow& operator=(const ExponentialFlow& other);

    double execute() override;
};

class LogisticFlow : public FlowImpl {
private:
    double pmax;

public:
    LogisticFlow();
    LogisticFlow(System* source, System* sink, double pmax);
    LogisticFlow(const string& name, System* source, System* sink, double pmax);
    virtual ~LogisticFlow();

    LogisticFlow(const LogisticFlow& other);
    LogisticFlow& operator=(const LogisticFlow& other);

    double execute() override;
};

class ComplexFlow : public FlowImpl {
public:
    ComplexFlow();
    ComplexFlow(System* source, System* sink);
    ComplexFlow(const string& name, System* source, System* sink);
    virtual ~ComplexFlow();

    ComplexFlow(const ComplexFlow& other);
    ComplexFlow& operator=(const ComplexFlow& other);

    double execute() override;
};

#endif
