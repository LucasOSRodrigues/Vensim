#ifndef MYSIM_H
#define MYSIM_H

#include <string>
#include <vector>

using namespace std;

class System {
private:
    string name;
    double value;

public:
    System();
    System(const string& name, double value);
    ~System();
    System(const System& other);
    System& operator=(const System& other);
    System(System&& other) noexcept;
    System& operator=(System&& other) noexcept;

    void setName(const string& name);
    void setValue(double value);

    string getName() const;
    double getValue() const;
};

class Flow {
protected:
    System* source;
    System* sink;

public:
    Flow();
    Flow(System* source, System* sink);
    virtual ~Flow();
    Flow(const Flow& other);
    Flow& operator=(const Flow& other);
    Flow(Flow&& other) noexcept;
    Flow& operator=(Flow&& other) noexcept;

    virtual double execute() = 0;

    System* getSource() const;
    System* getSink() const;
};

class ExponentialFlow : public Flow {
public:
    // Forma canônica
    ExponentialFlow();
    ExponentialFlow(System* source, System* sink);
    ~ExponentialFlow();
    ExponentialFlow(const ExponentialFlow& other);
    ExponentialFlow& operator=(const ExponentialFlow& other);
    ExponentialFlow(ExponentialFlow&& other) noexcept;
    ExponentialFlow& operator=(ExponentialFlow&& other) noexcept;

    double execute() override;
};

class LogisticFlow : public Flow {
private:
    double pmax;

public:
    LogisticFlow();
    LogisticFlow(System* source, System* sink, double pmax);
    ~LogisticFlow();
    LogisticFlow(const LogisticFlow& other);
    LogisticFlow& operator=(const LogisticFlow& other);
    LogisticFlow(LogisticFlow&& other) noexcept;
    LogisticFlow& operator=(LogisticFlow&& other) noexcept;

    double execute() override;
};

class ComplexFlow : public Flow {
public:
    ComplexFlow();
    ComplexFlow(System* source, System* sink);
    ~ComplexFlow();
    ComplexFlow(const ComplexFlow& other);
    ComplexFlow& operator=(const ComplexFlow& other);
    ComplexFlow(ComplexFlow&& other) noexcept;
    ComplexFlow& operator=(ComplexFlow&& other) noexcept;

    double execute() override;
};

class Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;

public:
    Model();
    ~Model();
    Model(const Model& other);
    Model& operator=(const Model& other);
    Model(Model&& other) noexcept;
    Model& operator=(Model&& other) noexcept;

    void add(System* system);
    void add(Flow* flow);

    void run(int begin, int end);
};

#endif
