#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <iostream>
using namespace std;

class Hotel {
private: 
    unsigned long long int rooms;
public:
    Hotel() {
        rooms = 0;
    }

    bool CheckAvailability(int roomNumber) {
        if (roomNumber < 1 || roomNumber > 60) {
            cout << "Incorrect number entered, must be betwwen 1-60" << endl;
            return false;
        }

        cout << "Checking availability for room: " << roomNumber << endl;

        return ((rooms >> (roomNumber -1)) & 1) == 0;
    }

    void BookRoom(int roomNumber) {
        if (CheckAvailability(roomNumber)) {
            rooms |= (1 << roomNumber - 1);
            cout << "Room number " << roomNumber << " has successfully been booked!\n" << endl;
        } else {
            cout << "Room number " << roomNumber << " is already booked, try another room.\n" << endl;
        }
    }

    void CheckOut(int roomNumber) {
        if (CheckAvailability(roomNumber)) {
            cout << "Room " << roomNumber << " is not currently booked..\n" << endl;
        } else {
            rooms = rooms & ~(1 << (roomNumber - 1));
            cout << "Checkout: success! Room " << roomNumber << " is available again.\n" << endl;
        }
    }

    void ShowRooms() {
        unsigned long long int totalReserved = 0;
        unsigned long long int totalAvailable = 0;

        cout << "Now displaying full hotel availability:\n";
        
        for(unsigned long long roomNumber = 1, bit = 0; bit < 60; bit++, roomNumber <<= 1) {
            cout << "Room " << bit+1 << " is ";
            if ((rooms >> bit) & 1) {
                cout << "unavailable!~~~~~~~~~~\n";
                totalReserved = -(~totalReserved);
            } else {
                cout << "available.\n";
                totalAvailable = -(~totalAvailable);
            }
        }

        cout << "Total rooms available: " << totalAvailable << "." << endl;
        cout << "Total rooms reserved: " << totalReserved << ".\n" << endl;
    }
};

#endif