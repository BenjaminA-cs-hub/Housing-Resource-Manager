#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "HousingResource.h"
using namespace std;

vector<HousingResource> resources;


void addResource();
void displayAllResources();
void displayResource(int);
void updateResource(int);
void deleteResource(int);
void saveToFile();
void loadFromFile();
void sortByCost();

int main() {
    char choice;
    int id;
    loadFromFile();
    do {
        system("clear"); 
        cout << "\n===== HOUSING RESOURCE MANAGER =====";
        cout << "\n1. Add Housing Resource";
        cout << "\n2. Search Housing Resource by ID";
        cout << "\n3. Display All Housing Resources";
        cout << "\n4. Update Housing Resource";
        cout << "\n5. Delete Housing Resource";
        cout << "\n6. Sort Resources by Cost";
        cout << "\n7. Save and Exit";
        cout << "\nEnter your choice (1-7): ";
        cin >> choice;
        system("clear");

        switch(choice) {
            case '1': addResource(); break;
            case '2': cout << "Enter Resource ID: "; cin >> id; displayResource(id); break;
            case '3': displayAllResources(); break;
            case '4': cout << "Enter Resource ID to update: "; cin >> id; updateResource(id); break;
            case '5': cout << "Enter Resource ID to delete: "; cin >> id; deleteResource(id); break;
            case '6': sortByCost(); break;
            case '7': saveToFile(); cout << "Saved! Exiting..."; break;
            default: cout << "Invalid choice!"; cin.ignore(); cin.get();
        }
    } while (choice != '7');
    return 0;
}


void addResource() {
    HousingResource hr;
    hr.insertData();
    resources.push_back(hr);
    cout << "\nResource Added! Press Enter to continue.";
    cin.ignore(); cin.get();
}

void displayAllResources() {
    cout << "\n=== All Housing Resources ===";
    for (const auto& res : resources)
        res.printData();
    cout << "\nPress Enter to continue.";
    cin.ignore(); cin.get();
}

void displayResource(int id) {
    bool found = false;
    for (const auto& res : resources) {
        if (res.getId() == id) {
            res.printData();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nResource Not Found!";
    cout << "\nPress Enter to continue.";
    cin.ignore(); cin.get();
}

void updateResource(int id) {
    bool found = false;
    for (auto& res : resources) {
        if (res.getId() == id) {
            cout << "Current details:";
            res.printData();
            cout << "\nEnter new details:";
            res.insertData();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nResource Not Found!";
    cout << "\nPress Enter to continue.";
    cin.ignore(); cin.get();
}

void deleteResource(int id) {
    auto it = remove_if(resources.begin(), resources.end(), [id](const HousingResource& res) {
        return res.getId() == id;
    });
    if (it != resources.end()) {
        resources.erase(it, resources.end());
        cout << "\nResource Deleted.";
    } else {
        cout << "\nResource Not Found.";
    }
    cout << "\nPress Enter to continue.";
    cin.ignore(); cin.get();
}

void saveToFile() {
    ofstream outFile("housing.dat", ios::binary | ios::out);
    for (const auto& res : resources) {
        outFile.write(reinterpret_cast<const char*>(&res), sizeof(HousingResource));
    }
    outFile.close();
}

void loadFromFile() {
    HousingResource hr;
    ifstream inFile("housing.dat", ios::binary | ios::in);
    if (!inFile) return; // No file to load
    while (inFile.read(reinterpret_cast<char*>(&hr), sizeof(HousingResource))) {
        resources.push_back(hr);
    }
    inFile.close();
}

void sortByCost() {
    sort(resources.begin(), resources.end(), [](const HousingResource& a, const HousingResource& b) {
        return a.getCost() < b.getCost();
    });
    cout << "\nResources sorted by cost.";
    cout << "\nPress Enter to continue.";
    cin.ignore(); cin.get();
}

