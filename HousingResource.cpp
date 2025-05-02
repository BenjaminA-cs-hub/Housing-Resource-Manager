//
//  HousingResources.cpp
//  Console Application
//
//  Created by Benjamin on 4/26/25.
//

#include <iostream>
#include <cstring>
#include "HousingResource.h"
using namespace std;

void HousingResource::insertData() {
    cout << "\nEnter Resource ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(name, 100);
    cout << "Enter Type (Shelter/Apartment/Room): ";
    cin.getline(type, 50);
    cout << "Enter Address: ";
    cin.getline(address, 100);
    cout << "Enter Contact Info: ";
    cin.getline(contact, 50);
    cout << "Enter Monthly Cost (0 if Free): ";
    cin >> cost;
    cout << "Available? (1 for Yes, 0 for No): ";
    cin >> available;
}

void HousingResource::printData() const {
    cout << "\nResource ID: " << id;
    cout << "\nName: " << name;
    cout << "\nType: " << type;
    cout << "\nAddress: " << address;
    cout << "\nContact: " << contact;
    cout << "\nCost: $" << cost;
    cout << "\nAvailability: " << (available ? "Yes" : "No") << endl;
}

int HousingResource::getId() const {
    return id;
}

double HousingResource::getCost() const {
    return cost;
}

bool HousingResource::isAvailable() const {
    return available;
}
