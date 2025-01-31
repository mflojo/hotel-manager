#include <iostream>
#include <string>
#include "Hotel.h"
using namespace std;

Hotel h1;

void HotelMenu();
void MenuOne();
void MenuTwo();
void MenuThree();

int main() {
    HotelMenu();

    return 0;
}

void MenuOne() {
    h1.ShowRooms();
    HotelMenu();
}

void MenuTwo() {
    int input;
    cout << "Enter the number for the room you wish to book: ";
    cin >> input;
    h1.BookRoom(input);
    HotelMenu();
}

void MenuThree() {
    int input;
    cout << "Which room are you checking out of: ";
    cin >> input;
    h1.CheckOut(input);
    HotelMenu();
}

void HotelMenu() {
    int menuSelection  = -1;
    cout << "Welcome to the Hotel Booking app. Menu options are: \n";
    cout << " [0] - Exit the app\n [1] - Show All Rooms\n [2] - Book Room\n [3] - Check out\n";
    cout << "Enter your Selection: ";
    cin >> menuSelection;

    if (menuSelection == 0) {
        cout << "Closing app, goodbye.\n";
    } else if (menuSelection == 1) {
        MenuOne();
    } else if (menuSelection == 2) {
        MenuTwo();
    } else if (menuSelection == 3) {
        MenuThree();
    } else {
        cout << "Invalid menu option\n" << endl;
        HotelMenu();
    }
}