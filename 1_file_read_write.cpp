#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "sample.txt";
    string textToWrite, line;

    // 1. Writing to file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    cout << "Enter text to write into file: ";
    getline(cin, textToWrite);
    outFile << textToWrite << endl;
    outFile.close();
    cout << "✅ Data written to '" << filename << "' successfully." << endl;

    // 2. Reading back from file
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\n--- Reading Content From File ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
