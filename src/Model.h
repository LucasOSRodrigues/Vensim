#ifndef MODEL_H
#define MODEL_H

#include <string>
#include "System.h"
#include "Flow.h"

using namespace std;

class Model {
public:
    virtual ~Model() {}

    static Model* createModel(const string& name = "");
    static void deleteModel(const string& name);

    virtual string getName() const = 0;
    virtual void setName(const string& name) = 0;

    virtual void add(System* system) = 0;
    virtual void add(Flow* flow) = 0;

    virtual System* createSystem(const string& name = "", double value = 0.0) = 0;

    template <typename FLOW_TYPE, typename... Args>
    FLOW_TYPE* createFlow(Args... args) {
        FLOW_TYPE* flow = new FLOW_TYPE(args...);
        add(flow);
        return flow;
    }

    virtual void run(int begin, int end) = 0;

};

#endif
