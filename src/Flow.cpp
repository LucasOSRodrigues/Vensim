#include "Flow.h"

Flow::Flow() : source(nullptr), sink(nullptr) {}

Flow::Flow(System* source, System* sink)
    : source(source), sink(sink) {}

Flow::~Flow() = default;

Flow::Flow(const Flow& other)
    : source(other.source), sink(other.sink) {}

Flow& Flow::operator=(const Flow& other) {
    if (this != &other) {
        source = other.source;
        sink = other.sink;
    }
    return *this;
}

System* Flow::getSource() const {
    return source;
}

System* Flow::getSink() const {
    return sink;
}