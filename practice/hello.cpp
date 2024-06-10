#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << "\n";
    int x = 4;
    int y = 28;
    cout << y / x << "\n";

    string str = "ABC";
    cout << str << "\n";

    cout << "Type a message!" << "\n";
    string response;
    cin >> response;
    cout << "You inputted: " << response << "\n";

    int value1;
    int value2;
    cout << "Type a number: ";
    cin >> value1;
    cout << "Type a second number: ";
    cin >> value2;
    cout << value1 << " minus " << value2 << " equals " << value1 - value2 << "\n";
    cout << value1 << " times " << value2 << " equals  " << value1 * value2 << "\n";
    return 0;
}