#include <iostream>
#include <unordered_map>

using namespace std;

enum Type {
  PROTOTYPE_1,
  PROTOTYPE_2
};

class Prototype {

protected:
    
  string prototype_name_;
  float prototype_field_;

public:
    Prototype() {}
    Prototype(string name, float field) : prototype_name_(name),
                                          prototype_field_(field) {}
    virtual ~Prototype() {}

    virtual Prototype *clone() const = 0;
    virtual void method() {
      cout << "Call method() from " << prototype_name_ 
           << " with field : " << prototype_field_ << endl;
    }
};

class ConcretePrototype1 : public Prototype {

private:
  float concrete_prototype_field_;

public:
  ConcretePrototype1(string name, float field_base, float field)
      : Prototype(name, field_base), concrete_prototype_field_(field) {}

    Prototype* clone() const override {
      return new ConcretePrototype1(this->prototype_name_, 
                                   this->prototype_field_,
                                   this->concrete_prototype_field_);
    }
};

class ConcretePrototype2 : public Prototype {

private:
  float concrete_prototype_field_;

public:
  ConcretePrototype2(string name, float field_base, float field)
      : Prototype(name, field_base), concrete_prototype_field_(field) {}

    Prototype* clone() const override {
      return new ConcretePrototype2(this->prototype_name_, 
                                   this->prototype_field_,
                                   this->concrete_prototype_field_);
    }
};

class PrototypeFactory {
private:
    unordered_map<Type, Prototype*, hash<int>> prototypes_;

public:
  PrototypeFactory() {
    prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f,  51.f);
    prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f,  61.f);
  }

  ~PrototypeFactory() {
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
  }

  Prototype *CreatePrototype(Type type) {
    return prototypes_[type]->clone();
  }
};

void Client(PrototypeFactory &prototype_factory) {
    cout << "Let's create a Prototype \n";

    Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->method();
    delete prototype;

    cout << "\n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->method();
    delete prototype;
}

int main() {

    PrototypeFactory *prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}