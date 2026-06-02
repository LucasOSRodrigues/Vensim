#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"

class FlowImpl : public Flow {
protected:
    System* source;
    System* sink;

public:
    FlowImpl();
    FlowImpl(System* source, System* sink);
    virtual ~FlowImpl();

    FlowImpl(const FlowImpl& other);
    FlowImpl& operator=(const FlowImpl& other);

    System* getSource() const override;
    System* getSink() const override;

    virtual double execute() = 0;
};

#endif
