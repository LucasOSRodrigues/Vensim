#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <vector>

#include "Model.h"

using namespace std;

class ModelImpl : public Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;

public:
    ModelImpl();
    virtual ~ModelImpl();

    ModelImpl(const ModelImpl& other);
    ModelImpl& operator=(const ModelImpl& other);

    void add(System* system) override;
    void add(Flow* flow) override;
    void run(int begin, int end) override;

    size_t getSystemCount() const;
    size_t getFlowCount() const;
};

#endif
