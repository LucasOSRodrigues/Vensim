#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <string>
#include "System.h"
#include "handleBody.h"

using namespace std;

class SystemBody : public Body {
private:
    string name;
    double value;

public:
    SystemBody();
    SystemBody(const string& name, double value);
    virtual ~SystemBody();

    void setName(const string& name);
    void setValue(double value);

    string getName() const;
    double getValue() const;

    friend class Handle<SystemBody>;
    friend class SystemImpl;
};

class SystemImpl : public System, public Handle<SystemBody> {
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
