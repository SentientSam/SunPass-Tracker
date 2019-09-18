/*
    vehicles.h
    Samuel Lamb
    cop3330
    project 4
    2/26/2019
*/

#ifndef _VEHICLES_H 
#define _VEHICLES_H

#include <shapes.h>

enum VehicleType {badSn, vehicle, car, truck, van, tanker, flatbed};

class Vehicle //class Vehicle
{
public:
    Vehicle();
    Vehicle(const char*, unsigned int, bool verbose = false);
	virtual ~Vehicle();
	const char* SerialNumber() const; 
	unsigned int PassengerCapacity() const;
    virtual float LoadCapacity() const; 
	virtual const char* ShortName() const;
	virtual float Toll() const;
	static VehicleType SnDecode(const char* sn);
    

private:
    char* serialNumber_;
    unsigned int passengerCapacity_;
    Vehicle(const Vehicle&); //Copy Constructor
    Vehicle& operator = (const Vehicle);

protected:
	bool verbose_;
};

class Car : public Vehicle //class Car
{
public:
	Car();
	Car(const char*, unsigned int, bool verbose = false);
	virtual const char* ShortName() const;
    virtual ~Car();
private:
	Car (const Car&); //copy constructor
	Car& operator = (const Car);
};

class Truck : public Vehicle //class Truck
{
public:
	Truck();
	Truck(const char*, unsigned int, const char*,bool verbose = false);
	virtual ~Truck();
	virtual const char* ShortName() const;
	virtual float Toll() const;
    const char* DOTLicense() const;
private:
    char* DOTLicense_;
	Truck (const Truck&); //copy constructor
	Truck& operator = (const Truck);
};

class Van : public Truck, public Box //class Van
{
public:
	Van();
	Van(const char*, unsigned int, const char*, float, float, float, bool verbose = false);
	virtual float LoadCapacity() const;
	virtual const char* ShortName() const;
    virtual ~Van();
private:
	Van (const Van&); //copy constructor
	Van& operator = (const Van);
};

class Tanker : public Truck, public Cylinder //class Tanker
{
public:
	Tanker();
	Tanker(const char*, unsigned int, const char*, float, float, bool verbose = false);
	virtual ~Tanker();
	virtual float LoadCapacity() const;
	virtual const char* ShortName() const;
    
private:
	Tanker (const Tanker&); //copy constructor
	Tanker& operator = (const Tanker);
};

class Flatbed : public Truck, public Rectangle //class Flatbed
{
public:
	Flatbed();
	Flatbed(const char*, unsigned int, const char*, float, float, bool verbose = false);
	virtual float LoadCapacity() const;
	virtual const char* ShortName() const;
    virtual ~Flatbed();
private:
	Flatbed (const Flatbed&); //copy constructor
	Flatbed& operator = (const Flatbed);
};

#endif
