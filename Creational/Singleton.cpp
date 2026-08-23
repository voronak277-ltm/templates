#include <iostream>

using namespace std;

class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const) = delete;

    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }

    void doSomeWork()
    {
        cout << "Doing work\n";
    }

private:
    Singleton()
    {
        cout << "ctr\n";
    }

    ~Singleton()
    {
        cout << "dstr\n";
    }
};


int main()
{
    Singleton& s1 = Singleton::getInstance();
    s1.doSomeWork();

    Singleton& s2 = Singleton::getInstance();
    s2.doSomeWork();


    cout << "s1 address: " << &s1 << endl;
    cout << "s2 address: " << &s2 << endl;

    return 0;
}
