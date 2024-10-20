#include "Appartment.h"

Appartment::Appartment(string City, string Street, int BuildingNumber, int AppartmentNumber)
    : Address(City, Street, BuildingNumber), appartmentNumber(AppartmentNumber) {}

int Appartment::GetAppartmentNumber() const {
    return appartmentNumber;
}

string Appartment::GetType() const {
    return "Appartment";
}
