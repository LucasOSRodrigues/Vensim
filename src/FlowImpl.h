#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include <string>
#include "Flow.h"
#include "handleBody.h"

using namespace std;

class FlowBody : public Body {
private:
    string name;
    System* source;
    System* sink;

public:
    FlowBody();
    FlowBody(System* source, System* sink);
    FlowBody(const string& name, System* source, System* sink);
    virtual ~FlowBody();

    string getName() const;
    void setName(const string& name);

    System* getSource() const;
    System* getSink() const;
    void setSource(System* source);
    void setSink(System* sink);

    friend class Handle<FlowBody>;
    friend class FlowImpl;
};

class FlowImpl : public Flow, public Handle<FlowBody> {
public:
    FlowImpl();
    FlowImpl(System* source, System* sink);
    FlowImpl(const string& name, System* source, System* sink);
    virtual ~FlowImpl();

    FlowImpl(const FlowImpl& other);
    FlowImpl& operator=(const FlowImpl& other);

    string getName() const;
    void setName(const string& name);

    System* getSource() const override;
    System* getSink() const override;
    void setSource(System* source);
    void setSink(System* sink);

    virtual double execute() = 0;
};

#endif
