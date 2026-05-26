#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "Flow.h"

class ComplexFlow : public Flow {
public:
    ComplexFlow();
    ComplexFlow(System* source, System* sink);
    virtual ~ComplexFlow();

    ComplexFlow(const ComplexFlow& other);
    ComplexFlow& operator=(const ComplexFlow& other);

    double execute() override;
};

#endif