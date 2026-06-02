#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"

class Model {
public:
    virtual ~Model() {}

    virtual void add(System* system) = 0;
    virtual void add(Flow* flow) = 0;
    virtual void run(int begin, int end) = 0;
};

#endif
