#include "AddressBook.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>


AddressBook::AddressBook(string FileName) : filename(FileName) {}

void AddressBook::addAddress(Address* address) {
    addresses.push_back(address);
}

void AddressBook::loadAddressesFromFile() {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        // Тут розбір рядка на тип адреси (PrivateHouse або Appartment) та додавання
        // відповідної адреси до списку `addresses`.
    }
}

void AddressBook::saveAddressToFile(Address* address) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        if (address->GetType() == "Private House") {
            file << "Private House " << address->GetCity() << " " << address->GetStreet() << " " << address->GetBuildingNumber() << endl;
        } else if (address->GetType() == "Appartment") {
            Appartment* appartment = dynamic_cast<Appartment*>(address);
            file << "Appartment " << appartment->GetCity() << " " << appartment->GetStreet() << " " << appartment->GetBuildingNumber() << " " << appartment->GetAppartmentNumber() << endl;
        }
    }
}

void AddressBook::analyzeAddresses() {
    int privateHouseCount = 0;
    int appartmentCount = 0;
    int buildingCount = 0;
    map<int, int> appartmentDistribution;

    for (const Address* address : addresses) {
        if (address->GetType() == "Private House") {
            privateHouseCount++;
        } else if (address->GetType() == "Appartment") {
            const Appartment* appartment = dynamic_cast<const Appartment*>(address);
            appartmentCount++;
            appartmentDistribution[appartment->GetBuildingNumber()]++;
        }
    }

    for (const auto& pair : appartmentDistribution) {
        buildingCount++;
    }

    cout << "Number of private houses: " << privateHouseCount << endl;
    cout << "Number of appartments: " << appartmentCount << endl;
    cout << "Average number of appartments per building: " << (appartmentCount / static_cast<double>(buildingCount)) << endl;
}

const std::vector<Address*>& AddressBook::getAddresses() const {
    return addresses;
}

AddressBook::~AddressBook() {
    for (Address* address : addresses) {
        delete address;
    }
}
