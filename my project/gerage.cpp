#include <iostream>
#include <string>

using namespace std;

// Constants for the maximum number of cars and the hourly rate
const int MAX_CARS = 100;
const double HOURLY_RATE = 2.00;

// Structure to represent a car
struct Car
{
    string make;
    string model;
    string licensePlate;
    int arrivalTime;
    int departureTime;
};

// Class to represent a parking garage
class ParkingGarage
{
private:
    // Array to store the cars
    Car cars[MAX_CARS];
    // Index of the next car to be parked
    int nextCar;

public:
    // Constructor to initialize the parking garage
    ParkingGarage()
    {
        nextCar = 0;
    }

    // Method to park a car
    void parkCar(string make, string model, string licensePlate, int arrivalTime)
    {
        if (nextCar >= MAX_CARS)
        {
            cout << "Sorry, the garage is full." << endl;
        }
        else
        {
            cars[nextCar].make = make;
            cars[nextCar].model = model;
            cars[nextCar].licensePlate = licensePlate;
            cars[nextCar].arrivalTime = arrivalTime;
            cars[nextCar].departureTime = -1;
            nextCar++;
        }
    }

    // Method to retrieve a car
    void retrieveCar(string licensePlate, int departureTime)
    {
        bool found = false;
        for (int i = 0; i < nextCar; i++)
        {
            if (cars[i].licensePlate == licensePlate && cars[i].departureTime == -1)
            {
                cars[i].departureTime = departureTime;
                found = true;
                break;
            }
            else if (cars[i].departureTime != -1)
            {
                cout << "Sorry, that car has already been retrieved." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Sorry, we could not find a car with that license plate in the garage." << endl;
        }
    }

    // Method to calculate the charges for a car
    double calculateCharges(int arrivalTime, int departureTime)
    {
        int hours = (departureTime - arrivalTime) / 60;
        double charges = hours * HOURLY_RATE;
        return charges;
    }

    // Method to display the parking history
    void displayHistory()
    {
        cout << "Parking history:" << endl;
        for (int i = 0; i < nextCar; i++)
        {
            cout << cars[i].make << " " << cars[i].model << " (" << cars[i].licensePlate << ")" << endl;
            cout << "Arrival time: " << cars[i].arrivalTime << " | Departure time: " << cars[i].departureTime << endl;
            cout << "Charge: $" << calculateCharges(cars[i].arrivalTime, cars[i].departureTime) << endl;
        }
    }
};

int main()
{
    // Create a parking garage
    ParkingGarage garage;

    // Park some cars
    garage.parkCar("Toyota", "Camry", "ABC123", 9 * 60 + 30);
    garage.parkCar("Ford", "F-150", "DEF456", 11 * 60 + 15);
    garage.parkCar("Honda", "Accord", "GHI789", 13 * 60 + 45);

    // Retrieve some cars
    garage.retrieveCar("ABC123", 17 * 60 + 30);
    garage.retrieveCar("GHI789", 18 * 60 + 45);
    garage.retrieveCar("DEF456", 19 * 60 + 15);

    // Display the parking history
    garage.displayHistory();

    return 0;
}