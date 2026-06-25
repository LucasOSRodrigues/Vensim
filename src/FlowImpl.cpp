#include "FlowImpl.h"

FlowBody::FlowBody() : name(""), source(nullptr), sink(nullptr) {}

FlowBody::FlowBody(System* source, System* sink)
    : name(""), source(source), sink(sink) {}

FlowBody::FlowBody(const string& name, System* source, System* sink)
    : name(name), source(source), sink(sink) {}

FlowBody::~FlowBody() = default;

string FlowBody::getName() const { return name; }
void FlowBody::setName(const string& name) { this->name = name; }
System* FlowBody::getSource() const { return source; }
System* FlowBody::getSink() const { return sink; }
void FlowBody::setSource(System* source) { this->source = source; }
void FlowBody::setSink(System* sink) { this->sink = sink; }

FlowImpl::FlowImpl() : Handle<FlowBody>() {}

FlowImpl::FlowImpl(System* source, System* sink) : Handle<FlowBody>() {
    pImpl_->setSource(source);
    pImpl_->setSink(sink);
}

FlowImpl::FlowImpl(const string& name, System* source, System* sink) : Handle<FlowBody>() {
    pImpl_->setName(name);
    pImpl_->setSource(source);
    pImpl_->setSink(sink);
}

FlowImpl::~FlowImpl() = default;

FlowImpl::FlowImpl(const FlowImpl& other) : Handle<FlowBody>() {
    pImpl_->setName(other.getName());
    pImpl_->setSource(other.getSource());
    pImpl_->setSink(other.getSink());
}

FlowImpl& FlowImpl::operator=(const FlowImpl& other) {
    if (this != &other) {
        pImpl_->setName(other.getName());
        pImpl_->setSource(other.getSource());
        pImpl_->setSink(other.getSink());
    }
    return *this;
}

string FlowImpl::getName() const { return pImpl_->getName(); }
void FlowImpl::setName(const string& name) { pImpl_->setName(name); }
System* FlowImpl::getSource() const { return pImpl_->getSource(); }
System* FlowImpl::getSink() const { return pImpl_->getSink(); }
void FlowImpl::setSource(System* source) { pImpl_->setSource(source); }
void FlowImpl::setSink(System* sink) { pImpl_->setSink(sink); }
