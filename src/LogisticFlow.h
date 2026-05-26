#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H

#include "Flow.h"

class LogisticFlow : public Flow {
private:
    double pmax;

public:
    LogisticFlow();
    LogisticFlow(System* source, System* sink, double pmax);
    virtual ~LogisticFlow();

    LogisticFlow(const LogisticFlow& other);
    LogisticFlow& operator=(const LogisticFlow& other);

    double execute() override;
};

#endif