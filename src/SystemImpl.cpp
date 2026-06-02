#include "SystemImpl.h"

SystemImpl::SystemImpl() : name(""), value(0.0) {}

SystemImpl::SystemImpl(const string& name, double value)
    : name(name), value(value) {}

SystemImpl::~SystemImpl() = default;

SystemImpl::SystemImpl(const SystemImpl& other)
    : name(other.name), value(other.value) {}

SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

void SystemImpl::setName(const string& name) {
    this->name = name;
}

void SystemImpl::setValue(double value) {
    this->value = value;
}

string SystemImpl::getName() const {
    return name;
}

double SystemImpl::getValue() const {
    return value;
}
