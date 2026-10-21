#include <iostream>
#include <stdexcept>
using namespace std;

double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero error!");
    }
    return numerator / denominator;
}

int main() {
    double num, den;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        double result = divideNumbers(num, den);
        cout << "\n✅ Result: " << num << " / " << den << " = " << result << endl;
    } 
    catch (const runtime_error& e) {
        cout << "\n❌ Exception Caught: " << e.what() << endl;
    }

    return 0;
}
