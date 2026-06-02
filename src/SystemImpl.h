#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h"

class SystemImpl : public System {
private:
    string name;
    double value;

public:
    SystemImpl();
    SystemImpl(const string& name, double value);
    virtual ~SystemImpl();

    SystemImpl(const SystemImpl& other);
    SystemImpl& operator=(const SystemImpl& other);

    void setName(const string& name) override;
    void setValue(double value) override;

    string getName() const override;
    double getValue() const override;
};

#endif
