#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "System.h"
#include "Flow.h"

using namespace std;

class Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;

public:
    Model();
    virtual ~Model();

    Model(const Model& other);
    Model& operator=(const Model& other);

    void add(System* system);
    void add(Flow* flow);

    void run(int begin, int end);
};

#endif