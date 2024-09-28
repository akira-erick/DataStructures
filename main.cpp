#include "Array/Array.h"
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Array<int> myArray(arr, 5);
    myArray.print();
    
    cout << myArray.get(2);

    return 0;
}