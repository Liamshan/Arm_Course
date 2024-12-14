#include <iostream>
using namespace std;

int main() {
    float note[] = {0.5, 0.4, 0.3, 0.2}; // Array of 4 floats
    cout << "Total size of note array (bytes): " << sizeof(note) << endl;
    cout << "Size of one float (bytes): " << sizeof(float) << endl;
    cout << "Number of elements in note array: " << sizeof(note) / sizeof(float) << endl;
    return 0;
}
