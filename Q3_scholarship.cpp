
/*
 * Name       : wajhat anwar
 * Reg No     : l1s26bscs0151
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char path[100];

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 0;
    }

    int n;
    inFile >> n;
    inFile.ignore(1000, '\n');

    if (n > 30) {
        cout << "Too many students!" << endl;
        return 0;
    }

    if (n < 0) {
        cout << "No students found!" << endl;
        return 0;
    }

    char names[30][30];
    double cgpa[30];

    int count = 0;
    int eligible = 0;
    double total = 0;
    double highest = -1;
    int topIndex = 0;

    ofstream outFile("scholarship.txt");

    for (int i = 0; i < n; i++) {
        char name[30];
        double marks;

        inFile.getline(name, 30, ',');

        if (inFile.fail())
            break;

        if (!(inFile >> marks))
            break;

        inFile.ignore(1000, '\n');

        strcpy(names[count], name);
        cgpa[count] = marks;

        cout << "[" << names[count]
            << "] CGPA: " << cgpa[count] << endl;

        total += cgpa[count];

        if (cgpa[count] >= 3.50) {
            outFile << names[count] << ","
                << cgpa[count] << endl;
            eligible++;
        }

        if (cgpa[count] > highest) {
            highest = cgpa[count];
            topIndex = count;
        }

        count++;
    }

    inFile.close();
    outFile.close();

    if (count < n) {
        cout << "Warning: only " << count
            << " of " << n << " records found."
            << endl;
    }

    if (count == 0) {
        cout << "No students found!" << endl;
        return 0;
    }

    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << total / count << endl;
    cout << "Eligible for scholarship: "
        << eligible << endl;

    cout << "Top student: " << names[topIndex]
        << " (" << cgpa[topIndex] << ")" << endl;

    return 0;
}
