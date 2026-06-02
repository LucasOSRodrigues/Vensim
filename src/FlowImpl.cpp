#include "FlowImpl.h"

FlowImpl::FlowImpl() : source(nullptr), sink(nullptr) {}

FlowImpl::FlowImpl(System* source, System* sink)
    : source(source), sink(sink) {}

FlowImpl::~FlowImpl() = default;

FlowImpl::FlowImpl(const FlowImpl& other)
    : source(other.source), sink(other.sink) {}

FlowImpl& FlowImpl::operator=(const FlowImpl& other) {
    if (this != &other) {
        source = other.source;
        sink = other.sink;
    }
    return *this;
}

System* FlowImpl::getSource() const {
    return source;
}

System* FlowImpl::getSink() const {
    return sink;
}
