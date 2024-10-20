#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include "Address.h"
#include "PrivateHouse.h"
#include "Appartment.h"
#include "Address.cpp"
#include "PrivateHouse.cpp"
#include "Appartment.cpp"

class AddressBook {
private:
    std::vector<Address*> addresses;
    string filename;
public:
    AddressBook(string FileName);
    void addAddress(Address* address);
    void loadAddressesFromFile();
    void saveAddressToFile(Address* address);
    void analyzeAddresses();
    const std::vector<Address*>& getAddresses() const;
    ~AddressBook();
};

#endif // ADDRESSBOOK_H
