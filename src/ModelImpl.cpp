#include "ModelImpl.h"
#include "SystemImpl.h"

#include <vector>

static vector<Model*> models;

Model* Model::createModel(const string& name) {
    Model* model = new ModelImpl(name);
    models.push_back(model);
    return model;
}

void Model::deleteModel(const string& name) {
    for (auto it = models.begin(); it != models.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            models.erase(it);
            return;
        }
    }
}

ModelBody::ModelBody() : name("") {}

ModelBody::ModelBody(const string& name) : name(name) {}

ModelBody::~ModelBody() {
    for (auto system : systems) {
        delete system;
    }
    for (auto flow : flows) {
        delete flow;
    }
}

string ModelBody::getName() const { return name; }
void ModelBody::setName(const string& name) { this->name = name; }
void ModelBody::add(System* system) { systems.push_back(system); }
void ModelBody::add(Flow* flow) { flows.push_back(flow); }

System* ModelBody::createSystem(const string& name, double value) {
    System* system = new SystemImpl(name, value);
    add(system);
    return system;
}

void ModelBody::run(int begin, int end) {
    for (int time = begin; time < end; time++) {
        vector<double> values;

        for (auto flow : flows) {
            values.push_back(flow->execute());
        }

        for (size_t i = 0; i < flows.size(); i++) {
            Flow* flow = flows[i];
            System* source = flow->getSource();
            System* sink = flow->getSink();
            double value = values[i];

            if (source != nullptr) {
                source->setValue(source->getValue() - value);
            }
            if (sink != nullptr) {
                sink->setValue(sink->getValue() + value);
            }
        }
    }
}

size_t ModelBody::getSystemCount() const { return systems.size(); }
size_t ModelBody::getFlowCount() const { return flows.size(); }

ModelImpl::ModelImpl(const string& name) : Handle<ModelBody>() {
    pImpl_->setName(name);
}

ModelImpl::~ModelImpl() = default;

ModelImpl::ModelImpl(const ModelImpl& other) : Handle<ModelBody>(other) {}

ModelImpl& ModelImpl::operator=(const ModelImpl& other) {
    Handle<ModelBody>::operator=(other);
    return *this;
}

string ModelImpl::getName() const { return pImpl_->getName(); }
void ModelImpl::setName(const string& name) { pImpl_->setName(name); }
void ModelImpl::add(System* system) { pImpl_->add(system); }
void ModelImpl::add(Flow* flow) { pImpl_->add(flow); }
System* ModelImpl::createSystem(const string& name, double value) { return pImpl_->createSystem(name, value); }
void ModelImpl::run(int begin, int end) { pImpl_->run(begin, end); }
size_t ModelImpl::getSystemCount() const { return pImpl_->getSystemCount(); }
size_t ModelImpl::getFlowCount() const { return pImpl_->getFlowCount(); }
