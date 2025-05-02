//
//  HousingResources.h
//  Console Application
//
//  Created by Benjamin on 4/26/25.
//

#ifndef HOUSINGRESOURCE_H
#define HOUSINGRESOURCE_H

class HousingResource {
private:
    int id;
    char name[100];
    char type[50];
    char address[100];
    char contact[50];
    double cost;
    bool available;

public:
    void insertData();
    void printData() const;
    int getId() const;
    double getCost() const;
    bool isAvailable() const;
};

#endif
