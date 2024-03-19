#include <cstdlib>
#include <iostream>
using namespace std;
void swap(int & a,int &b)
{
    auto tmp = a;
    a = b;
    b = tmp;

}
int main(int argc ,char **argv)
{
     int a = 10,b=20 ;
     swap(a,b);
     cout << "a is "<< a << "b is "<<b<<endl;


    exit(0);
}
