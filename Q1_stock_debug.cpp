/*
 * Name       : wahjaht anwar
 * Reg No     : L1S26BSCS0151
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include <fstream> // FIX 1: File handling header
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    if (!inFile) { // FIX 2: Check file opening
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    ofstream reorder("reorder.txt", ios::app); // FIX 3: Keep old data
    char code[10];
    int qty, count = 0, low = 0;
    double price;
    double total = 0; // FIX 4: Store decimal values
    inFile.ignore(1000, '\n'); // FIX 5: Skip header line

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty << endl; // FIX 6: Write each item on a new line
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
