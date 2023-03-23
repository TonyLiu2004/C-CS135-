#include <iostream>
using namespace std;
class Counter{
    public:
    void reset();
    void add(int);
    void subtract(int);
    int get();

    private:
    int count;
};

void Counter::reset(){
    count = 0;
}
void Counter::add(int a){
    count+=a;
}

void Counter::subtract(int a){
    count-=a;
}

int Counter::get(){
    return count;
}

int main(){
    Counter c;
    c.reset();
    c.add(10);
    cout << c.get() << "\n";
    c.add(10);
    cout << c.get() << "\n";
    c.subtract(7);
    cout << c.get() << "\n";
}