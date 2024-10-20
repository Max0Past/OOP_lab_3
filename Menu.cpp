#include "Menu.h"
#include <iostream>

void Menu::start() {
    AddressBook addressBook("addresses.txt");
    int choice;

    do {
        cout << "1. Load addresses from file\n";
        cout << "2. Add private house\n";
        cout << "3. Add appartment\n";
        cout << "4. Analyze addresses\n";
        cout << "5. Save addresses to file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addressBook.loadAddressesFromFile();
        } else if (choice == 2) {
            string city, street;
            int number;
            cout << "Enter city, street and building number: ";
            cin >> city >> street >> number;
            addressBook.addAddress(new PrivateHouse(city, street, number));
        } else if (choice == 3) {
            string city, street;
            int number, appartmentNumber;
            cout << "Enter city, street, building number and appartment number: ";
            cin >> city >> street >> number >> appartmentNumber;
            addressBook.addAddress(new Appartment(city, street, number, appartmentNumber));
        } else if (choice == 4) {
            addressBook.analyzeAddresses();
        } else if (choice == 5) {
            for (Address* address : addressBook.getAddresses()) {
                addressBook.saveAddressToFile(address);
            }
        }
    } while (choice != 0);
}
