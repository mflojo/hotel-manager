#ifndef HOTEL_H
#define HOTEL_H
#include <string>
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
};

#endif