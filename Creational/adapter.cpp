#include <iostream>

using namespace std;

class Service {
public:
    virtual ~Service() = default;

    virtual string Request() const {
    return "Service: The default service's behavior.";
    }
};

class Adaptee {
public:
    string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Service {
private:
  Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    
    string Request() const override {
    string to_reverse = this->adaptee_->SpecificRequest();
    reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }
};

void ClientCode(const Service *service) {
    cout << service->Request();
};

int main() {
    cout << "Client: I can work just fine with the Target objects:\n";
    Service *service = new Service;
    
    ClientCode(service);
    cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    cout << "Adaptee: " << adaptee->SpecificRequest();
    cout << "\n\n";
    cout << "Client: But I can work with it via the Adapter:\n";
    
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    cout << "\n";

    delete service;
    delete adaptee;
    delete adapter;

    return 0;
}