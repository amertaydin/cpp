#include <iostream>
#include <memory> // Needed for smart pointers

using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor invoked" << endl;
    }

    ~MyClass() {
        cout << "Destructor invoked" << endl;
    }
};

int main() {
    // Unique pointer cannot be shared and destroyed at the end of scope
    unique_ptr<MyClass> uniquePtr = make_unique<MyClass>();

    // Shared pointer can be and destroyed at the end of scope
    shared_ptr<MyClass> sharedPtr = make_shared<MyClass>();

    // use_count can be used to show how many pointers sharing the same ownership
    cout << sharedPtr.use_count() << endl;

    // sharedPtr2 is have ownership to MyClass but sharedPtr is now NULL
    shared_ptr<MyClass> sharedPtr2 = sharedPtr;

    cout << sharedPtr.use_count() << endl;

    weak_ptr<int> weakPtr;
    {
        shared_ptr<int>sharedPtr = make_shared<int>(25);
        weakPtr = sharedPtr;
    }

    return 0;
}