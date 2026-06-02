#ifndef FLOW_H
#define FLOW_H

#include "System.h"

class Flow {
public:
    virtual ~Flow() {}

    virtual double execute() = 0;

    virtual System* getSource() const = 0;
    virtual System* getSink() const = 0;
};

#endif
