#include "SystemImpl.h"

System* System::createSystem(const string& name, double value) {
    return new SystemImpl(name, value);
}

SystemBody::SystemBody() : name(""), value(0.0) {}

SystemBody::SystemBody(const string& name, double value)
    : name(name), value(value) {}

SystemBody::~SystemBody() = default;

void SystemBody::setName(const string& name) {
    this->name = name;
}

void SystemBody::setValue(double value) {
    this->value = value;
}

string SystemBody::getName() const {
    return name;
}

double SystemBody::getValue() const {
    return value;
}

SystemImpl::SystemImpl() : Handle<SystemBody>() {}

SystemImpl::SystemImpl(const string& name, double value) : Handle<SystemBody>() {
    pImpl_->setName(name);
    pImpl_->setValue(value);
}

SystemImpl::~SystemImpl() = default;

SystemImpl::SystemImpl(const SystemImpl& other) : Handle<SystemBody>() {
    pImpl_->setName(other.getName());
    pImpl_->setValue(other.getValue());
}

SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this != &other) {
        pImpl_->setName(other.getName());
        pImpl_->setValue(other.getValue());
    }
    return *this;
}

void SystemImpl::setName(const string& name) {
    pImpl_->setName(name);
}

void SystemImpl::setValue(double value) {
    pImpl_->setValue(value);
}

string SystemImpl::getName() const {
    return pImpl_->getName();
}

double SystemImpl::getValue() const {
    return pImpl_->getValue();
}
