#ifndef MYSIM_H
#define MYSIM_H

#include <string>
#include <vector>

using namespace std;

// Representa um estoque/acumulador do modelo.
class System {
private:
    string name;
    double value;

public:
    System(const string& name, double value);

    void setName(const string& name);
    void setValue(double value);

    string getName() const;
    double getValue() const;
};

// Classe abstrata que representa um fluxo entre sistemas.
class Flow {
protected:
    System* source;
    System* sink;

public:
    Flow(System* source, System* sink);
    virtual ~Flow();

    // Função virtual pura. Cada fluxo concreto define sua própria equação.
    virtual double execute() = 0;

    System* getSource() const;
    System* getSink() const;
};

// Fluxo concreto para crescimento exponencial.
class ExponentialFlow : public Flow {
public:
    ExponentialFlow(System* source, System* sink);
    double execute() override;
};

// Fluxo concreto para crescimento logístico.
class LogisticFlow : public Flow {
private:
    double pmax;

public:
    LogisticFlow(System* source, System* sink, double pmax);
    double execute() override;
};

// Fluxo concreto usado no teste funcional complexo.
class ComplexFlow : public Flow {
public:
    ComplexFlow(System* source, System* sink);
    double execute() override;
};

// Modelo que contém sistemas e fluxos.
class Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;

public:
    Model();

    void add(System* system);
    void add(Flow* flow);

    void run(int begin, int end);
};

#endif
