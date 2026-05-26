#ifndef FLOW_H
#define FLOW_H

#include "System.h"

class Flow {
protected:
    System* source;
    System* sink;

public:
    Flow();
    Flow(System* source, System* sink);
    virtual ~Flow();

    Flow(const Flow& other);
    Flow& operator=(const Flow& other);

    virtual double execute() = 0;

    System* getSource() const;
    System* getSink() const;
};

#endif