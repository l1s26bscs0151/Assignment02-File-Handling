/*
 * Name       : wahajat anwar
 * Reg No     : l1s26bscs0151
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream inFile("parking.txt");

    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;
    inFile.ignore(1000, '\n');
    inFile.ignore(1000, '\n');

    cout << "Parking report for " << d << "/"
        << m << "/" << y << endl;

    ofstream outFile("receipts.txt");
    outFile << "Receipts for " << d << "/"
        << m << "/" << y << endl;

    char plate[15], longestPlate[15] = "";
    char type;
    int inH, inM, outH, outM;
    int vehicles = 0, cars = 0, bikes = 0;
    int total = 0, longest = -1;

    while (inFile >> plate >> type
        >> inH >> slash >> inM
        >> outH >> slash >> outM) {

        int start = inH * 60 + inM;
        int finish = outH * 60 + outM;
        int minutes = finish - start;

        if (minutes < 0)
            minutes += 24 * 60;

        int hours = (minutes + 59) / 60;

        if (hours == 0)
            hours = 1;

        int fee;

        if (type == 'C') {
            fee = hours * 100;
            cars++;
        }
        else {
            fee = hours * 40;
            bikes++;
        }

        cout << plate << " "
            << (type == 'C' ? "Car" : "Bike") << " "
            << minutes / 60 << " h "
            << minutes % 60 << " min Fee: "
            << fee << endl;

        outFile << plate << " " << fee << endl;

        vehicles++;
        total += fee;

        if (minutes > longest) {
            longest = minutes;
            strcpy(longestPlate, plate);
        }
    }

    inFile.close();
    outFile.close();

    if (vehicles == 0) {
        cout << "No vehicles found!" << endl;
        return 0;
    }

    cout << "Vehicles: " << vehicles << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << total << endl;
    cout << "Longest stay: " << longestPlate
        << " (" << longest / 60 << " h "
        << longest % 60 << " min)" << endl;

    return 0;
}