#include <iostream>

using namespace std;

class Prototype {

protected:
    
string prototype_name_;
float prototype_field_;

public:
    Prototype() {}
    Prototype(string prototype_name) : prototype_name_(prototype_name) {
  }
    virtual ~Prototype() {}
    virtual Prototype *Clone() const = 0;
    virtual void Method(float prototype_field) {
    cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << endl;
  }
};

class ConcretePrototype : public Prototype {

private:
    float concrete_prototype_field_;

public:
  ConcretePrototype(string prototype_name,)
      : Prototype(prototype_name), concrete_prototype_field_(concrete_prototype_field_) {
  }

    Prototype *Clone() const override {
    return new ConcretePrototype;
  }
};

class PrototypeFactory {
private:
    unordered_map<Type, Prototype *, hash<int>> prototype_;

public:
  PrototypeFactory() {
    prototype_[Type::PROTOTYPE] = new ConcretePrototype("PROTOTYPE ", 50.f);
    }

  ~PrototypeFactory() {
    delete prototype_[Type::PROTOTYPE];
    }

  Prototype *CreatePrototype(Type type) {
    return prototype_[type]->Clone();
    }
};

void Client(PrototypeFactory &prototype_factory) {
    cout << "Let's create a Prototype \n";

    Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE);
    prototype->Method(90);
    delete prototype;

    cout << "\n";
}

int main() {
    PrototypeFactory *prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}