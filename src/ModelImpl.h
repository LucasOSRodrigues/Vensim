#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <vector>
#include <string>

#include "Model.h"
#include "handleBody.h"

using namespace std;

class ModelBody : public Body {
private:
    string name;
    vector<System*> systems;
    vector<Flow*> flows;

public:
    ModelBody();
    ModelBody(const string& name);
    virtual ~ModelBody();

    string getName() const;
    void setName(const string& name);

    void add(System* system);
    void add(Flow* flow);
    System* createSystem(const string& name = "", double value = 0.0);
    void run(int begin, int end);

    size_t getSystemCount() const;
    size_t getFlowCount() const;

    friend class Handle<ModelBody>;
    friend class ModelImpl;
};

class ModelImpl : public Model, public Handle<ModelBody> {
public:
    ModelImpl(const string& name = "");
    virtual ~ModelImpl();

    ModelImpl(const ModelImpl& other);
    ModelImpl& operator=(const ModelImpl& other);

    string getName() const override;
    void setName(const string& name) override;

    void add(System* system) override;
    void add(Flow* flow) override;
    System* createSystem(const string& name = "", double value = 0.0) override;
    void run(int begin, int end) override;

    size_t getSystemCount() const;
    size_t getFlowCount() const;
};

#endif
