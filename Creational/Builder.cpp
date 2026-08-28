#include <iostream>
using namespace std;

class Product1
{
public:
    void addPart(const string& part) { cout << "Added " << part << endl; }

    void getInfo() { cout << "I'm Product1" << endl; }
};

class Product2
{
public:
    void addPart(const string& part) { cout << "Added " << part << endl; }
    
    void getInfo() { cout << "I'm Product2" << endl; }
};

class Builder {

public:
    virtual ~Builder() = default;
    virtual void buildStepA() = 0;
    virtual void buildStepB() = 0;
    virtual void buildStepZ() = 0;
    virtual void reset() = 0;
};

class ConcreteBuilder1 : public Builder {
private:
    Product1* result = nullptr;
public:
    ConcreteBuilder1(){
        reset();
    }

    ~ConcreteBuilder1() override {
        delete result;
    }

    void buildStepA() override { result->addPart("Part1"); }
    void buildStepB() override { result->addPart("Part2"); }
    void buildStepZ() override { result->addPart("Part3"); }
    void reset() override {
        delete result;
        result = new Product1();      
    };

    Product1* getResult() {
        return result;
    }
};

class ConcreteBuilder2 : public Builder {
private:
    Product2* result = nullptr;
public:
    ConcreteBuilder2() {
        reset();
    }
    ~ConcreteBuilder2() override {
        delete result;
    }
    
    void buildStepA() override { result->addPart("Part1"); }
    void buildStepB() override { result->addPart("Part2"); }
    void buildStepZ() override { result->addPart("Part3"); }
    void reset() override {
        delete result;
        result = new Product2();        
    };

    Product2* getResult() {
        return result;
    }
};

class Director {

private:
    Builder* builder;

public:
    Director (Builder* b) {
        builder = b;
    }

    void changeBuilder (Builder* b) {
        builder = b;
    }

    void make(const string& type = "simple") {
        builder->reset();

        if (type == "simple") {
            builder->buildStepA();
        } else {
            builder->buildStepA();
            builder->buildStepB();
            builder->buildStepZ();
        }
    }
};

int main()
{
   ConcreteBuilder1* b1 = new ConcreteBuilder1();
   
   Director* director = new Director(b1);

   director->make();

   Product1* p1 = b1->getResult();
   p1->getInfo();

   delete director;
   delete b1;

   return 0;
}
