#include <iostream> 
#include <new>

using namespace std ; 

int main ( ) {

    auto p = new int(10) ; 

    cout << "p point to " << p << " , addr[p] = " << &p << endl ; 

    return 0 ; 

}
