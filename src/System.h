#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
public:
    virtual ~System() {}

    static System* createSystem(const string& name = "", double value = 0.0);

    virtual void setName(const string& name) = 0;
    virtual void setValue(double value) = 0;

    virtual string getName() const = 0;
    virtual double getValue() const = 0;
};

#endif
