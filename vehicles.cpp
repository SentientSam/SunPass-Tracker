/*
    vehicles.cpp
    Samuel Lamb
    cop3330
    project 4
    2/26/2019
*/


#include <vehicles.h>
#include <cstring>
#include <shapes.h>
#include <fstream>

Vehicle::Vehicle() : serialNumber_(nullptr), passengerCapacity_(0), verbose_(false)
{

}

Vehicle::~Vehicle()
{
    if(Vehicle::verbose_)
    {
        std::cout << "~Vehicle()\n";
    }
}

Vehicle::Vehicle(const char* serialNumber, unsigned int passengerCapacity, bool verbose) : serialNumber_(nullptr), passengerCapacity_(passengerCapacity), verbose_(verbose)
{
    size_t sizeuno = std::strlen(serialNumber);
    serialNumber_ = new char[1 + sizeuno];
    serialNumber_[sizeuno] = '\0';
    std::strcpy(serialNumber_, serialNumber);
    if(Vehicle::verbose_)
    {
        std::cout << "Vehicle()\n";
    }
}

float Vehicle::LoadCapacity() const
{
    return (0.0);
}

const char* Vehicle::SerialNumber() const
{
    return serialNumber_;
}

float Vehicle::Toll() const
{
    return (2.0);
}

const char* Vehicle::ShortName() const
{
    return ("UNK");
}

unsigned int Vehicle::PassengerCapacity() const
{
    return (passengerCapacity_);
}

Car::Car(const char* serialNumber, unsigned int passengerCapacity, bool verbose) : Vehicle(serialNumber, passengerCapacity, verbose)
{
    if(Vehicle::verbose_)
    {
        std::cout << "Car()\n";
    }
}

Car::~Car()
{
    if(Vehicle::verbose_)
    {
        std::cout << "~Car()\n";
    }
}

const char* Car::ShortName() const
{
    return("CAR");
}

//Truck::Truck() : Vehicle()


Truck::Truck(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, bool verbose) : Vehicle(serialNumber, passengerCapacity, verbose), DOTLicense_(nullptr)
{
    if(Vehicle::verbose_)
    {
        std::cout << "Truck()\n";
    }
    size_t sizedos = std::strlen(DOTLicense);
    DOTLicense_ = new char[1 + sizedos];
    DOTLicense_[sizedos] = '\0';
    std::strcpy(DOTLicense_, DOTLicense); 
}

Truck::~Truck()
{
    if(Vehicle::verbose_)
    {
        std::cout << "~Truck()\n";
    }
    delete[] DOTLicense_;
}

const char* Truck::ShortName()const
{
    return("TRK");
}

float Truck::Toll() const
{
    return (10.00);
}

const char* Truck::DOTLicense()const
{
    return (DOTLicense_);
}

//Van::Van() : Truck() Box()

Van::Van(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float width, float length, float height, bool verbose) : Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Box(width, length, height, verbose)
{
    if(Vehicle::verbose_)
    {
        std::cout << "Van()\n";
    }
}

Van::~Van()
{
    if(Vehicle::verbose_)
    {
        std::cout << "~Van()\n";
    }
}

float Van::LoadCapacity() const
{
    return(this -> Volume());
}

const char* Van::ShortName() const
{
    return ("VAN");
}

Tanker::Tanker(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float radius, float height, bool verbose) : 
Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Cylinder(radius, height, verbose)
{
    if(Vehicle::verbose_)
    {
        std::cout << "Tanker()\n";
    }
}

Tanker::~Tanker()
{
    if(Vehicle::verbose_)
    {
        std::cout << "~Tanker()\n";
    }
}

float Tanker::LoadCapacity() const
{
    return (this -> Volume());
}

const char* Tanker::ShortName() const
{
    return ("TNK");
}

Flatbed::Flatbed(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float width, float length, bool verbose) : Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Rectangle(width, length, verbose)
{
    if(Vehicle::verbose_)
    {
        std::cout << "Flatbed()\n";
    }
}

Flatbed::~Flatbed()
{
    if(Vehicle::verbose_)
    {
        std::cout << "~Flatbed()\n";
    }
}

float Flatbed::LoadCapacity() const
{
    return(this -> Area());
}

const char* Flatbed::ShortName() const
{
    return("FLT");
}

VehicleType Vehicle::SnDecode(const char* sn)
{
switch(sn[0])
{
    case '1':

        return vehicle;
    case '2':

        return car;
    case '3':

        return truck;
    case '4':

        return van;
    case '5':

        return tanker;
    case '6':

        return flatbed;
    default: 

        return badSn;
}
return badSn;
}
