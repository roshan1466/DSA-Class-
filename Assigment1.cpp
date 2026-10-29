#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

const int TOTAL_SEATS = 30;

struct Passenger {
    int seatNo;
    string name;
    int age;
    char gender;
    Passenger* next;
};

int* seats = nullptr;
Passenger* head = nullptr;

void bookTicket() {
    int seat = -1;

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            seat = i;
            break;
        }
    }

    if (seat == -1) {
        cout << "\nSorry! No seats available.\n";
        return;
    }

    string name;
    int age;
    char gender;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    cout << "Enter Age: ";
    if (!(cin >> age) || age <= 0) {
        cout << "Invalid age.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter Gender (M/F/O): ";
    if (!(cin >> gender)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (gender >= 'a' && gender <= 'z') {
        gender = gender - 'a' + 'A';
    }

    if (gender != 'M' && gender != 'F' && gender != 'O') {
        cout << "Enter M, F, or O for gender.\n";
        return;
    }

    Passenger* newPassenger = new Passenger;

    newPassenger->seatNo = seat + 1;
    newPassenger->name = name;
    newPassenger->age = age;
    newPassenger->gender = gender;
    newPassenger->next = nullptr;

    if (head == nullptr) {
        head = newPassenger;
    } else {
        Passenger* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newPassenger;
    }

    seats[seat] = 1;

    cout << "\nTicket booked successfully!\n";
    cout << "Seat No: " << seat + 1 << "\n";
}

void cancelTicket() {
    int seatNo;

    cout << "Enter Seat Number to Cancel (1-30): ";

    if (!(cin >> seatNo)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        cout << "Invalid seat number.\n";
        return;
    }

    if (seats[seatNo - 1] == 0) {
        cout << "This seat is already available.\n";
        return;
    }

    Passenger* temp = head;
    Passenger* previous = nullptr;

    while (temp != nullptr && temp->seatNo != seatNo) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Passenger record not found.\n";
        return;
    }

    if (previous == nullptr) {
        head = temp->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;
    seats[seatNo - 1] = 0;

    cout << "Ticket cancelled successfully for Seat No: "
         << seatNo << "\n";
}

void viewTrainStatus() {
    cout << "\n----- TRAIN SEAT STATUS -----\n";

    for (int i = 0; i < TOTAL_SEATS; i++) {
        cout << "Seat " << i + 1 << ": ";

        if (seats[i] == 1) {
            cout << "Booked\n";
        } else {
            cout << "Available\n";
        }
    }
}

void viewPassengerList() {
    Passenger* temp = head;

    cout << "\n----- PASSENGER LIST -----\n";

    if (temp == nullptr) {
        cout << "No passengers booked.\n";
        return;
    }

    while (temp != nullptr) {
        cout << "Seat No: " << temp->seatNo
             << " | Name: " << temp->name
             << " | Age: " << temp->age
             << " | Gender: " << temp->gender << "\n";

        temp = temp->next;
    }
}

void cleanup() {
    Passenger* temp = head;

    while (temp != nullptr) {
        Passenger* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = nullptr;

    free(seats);
    seats = nullptr;
}

int main() {
    seats = (int*)malloc(TOTAL_SEATS * sizeof(int));

    if (seats == nullptr) {
        cout << "Memory allocation failed.\n";
        return 1;
    }

    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = 0;
    }

    int choice;

    do {
        cout << "\n===== RAILWAY RESERVATION SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Train Status\n";
        cout << "4. View Passenger List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                bookTicket();
                break;

            case 2:
                cancelTicket();
                break;

            case 3:
                viewTrainStatus();
                break;

            case 4:
                viewPassengerList();
                break;

            case 5:
                cleanup();
                cout << "All allocated memory released.\n";
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
