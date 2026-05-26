#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "Flow.h"

class ExponentialFlow : public Flow {
public:
    ExponentialFlow();
    ExponentialFlow(System* source, System* sink);
    virtual ~ExponentialFlow();

    ExponentialFlow(const ExponentialFlow& other);
    ExponentialFlow& operator=(const ExponentialFlow& other);

    double execute() override;
};

#endif