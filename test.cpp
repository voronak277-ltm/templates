#include <iostream>

using namespace std;

class Person {

private:
    string name;
    int age;

public:
    void setname(string n) { name = n; }
    string getname() { return name; }
    
    int getage() { return age; }
    void setage(int a) { age = a; }

};

int main() {
    
    Person p;
    p.setname("Кирилл");
    p.setage(21);

    cout << "Имя: " << p.getname() << endl;
    cout << "Возраст: " << p.getage() << endl;
    return 0;
}