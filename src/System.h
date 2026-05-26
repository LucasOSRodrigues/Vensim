#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
private:
    string name;
    double value;

public:
    System();
    System(const string& name, double value);
    virtual ~System();

    System(const System& other);
    System& operator=(const System& other);

    void setName(const string& name);
    void setValue(double value);

    string getName() const;
    double getValue() const;
};

#endif