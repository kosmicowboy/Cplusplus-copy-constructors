#include <iostream>

using namespace std;

class Test
{
public:
    Test() { size = 10; l = new int[size]; }
    Test(int x) { size = x; l = new int[size]; }
    //copy constructor
    Test(Test& right)
    {
        cout << "copy constructor is called \n";
        size = right.size;
        l = new int[size];
        for (int i = 0; i < size; i++)
        {
            l[i] = right.l[i];
        }
    }

    //overloading the assignment operator
    Test& operator=(const Test& right)
    {
        cout << "assignment operator is called" << endl;
        if (this !=&right)
        {
            size = right.size;
            l = new int[size];
            for (int i = 0; i < size; i++)
                l[i] = right.l[i];
            return *this;
        }
    }

    void setL() { l[0] = 2; l[1] = 4, l[2] = 10;}
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << l[i] << " ";
        }
        cout << "\n";
    };
private:
    int size;
    int* l; // a pointer as a data member
};

void cpy(Test tcpy)
{
    tcpy.print();
}

int main() {
    Test t(3);
    t.setL();
    t.print();
    cpy(t);
    Test t2 = t;
    Test t4(4);
    t4 = t;
    t4.print();

    return 0;
}