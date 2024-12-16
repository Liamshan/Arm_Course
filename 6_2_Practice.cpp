#include <iostream>

int main() {
    float note[] = {1.54, 5.5, 24.11, 10.0, 4.3};

    std::cout << "The float size is:  "<< sizeof(float) << "  bytes \n";
    std::cout << "The note vector is: "<< sizeof(note) << "  bytes \n";
    std::cout << "The number of elements in 'note' is:  "<< (sizeof(note) / sizeof(float)) << "  elements \n";

}