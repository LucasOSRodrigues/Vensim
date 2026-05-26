#include "System.h"

System::System() : name(""), value(0.0) {}

System::System(const string& name, double value)
    : name(name), value(value) {}

System::~System() = default;

System::System(const System& other)
    : name(other.name), value(other.value) {}

System& System::operator=(const System& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

void System::setName(const string& name) {
    this->name = name;
}

void System::setValue(double value) {
    this->value = value;
}

string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}