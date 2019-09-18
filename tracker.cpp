// 
//  Tracker.cpp
//  Samuel Lamb 
//  3/19/2019
//  cop3330
//

#include <iostream>
#include <iomanip> //needed for pointed precision, etc.
#include <vehicles.h>
#include <typeinfo> //found out about this online


int main(int, char**)
{
  std::cout << "\nSTL::Tracker started...\n\n";
  int segmentSize = 1;
  char sn[50];
  char dot[50];
  int passengers = 0;
  std::cout << std::fixed << std::showpoint << std::setprecision(2); //allows my double values to show as such
  while (segmentSize != 0)
  {
    std::cin >> segmentSize; //input the segmentSize, if it is 0 or above 100 the program will exit
    if (segmentSize == 0) {
      std::cout << "\n\n...Thank you for using SunPass Tracker.\n\n"; //first attempt at having message on exit
      return 0;
    }
    if (segmentSize > 100) {
      std::cout << "\n\n** Tracker error: max segment size exceeded.\n\n";
      return 0;
    }
    int typeCounts[] = {
            0, 0, 0, 0, 0, 0, 0
    };
    double tons = 0.0; //initializing my tonnes and toll as doubles
    double toll = 0.0;
    int l, w, h;
    Vehicle* vehicles[segmentSize];
    for (int i = 0; i < segmentSize; i++)
    {
      std::cin >> sn;
      std::cin >> passengers;
      if (sn[0] == '1')
      {
        typeCounts[0]++;
        Vehicle* vehicle = new Vehicle(sn, passengers, false);
        vehicles[i] = vehicle;
        toll += vehicle->Toll(); //adds the vehicle specific toll and loadcapacity values into their variables for addition
        tons += vehicle->LoadCapacity();
      } else if (sn[0] == '2')
      {
        typeCounts[1]++;
        Car* car = new Car(sn, passengers, false);
        vehicles[i] = static_cast<Vehicle*>(car);
        toll += car->Toll();
        tons += car->LoadCapacity();
      } else if (sn[0] == '3')
      {
        typeCounts[2]++;
        std::cin >> dot;
        Truck* truck = new Truck(sn, passengers, dot, false);
        vehicles[i] = static_cast<Truck*>(truck);
        toll += truck->Toll();
        tons += truck->LoadCapacity();
      } else if (sn[0] == '4')
      {
        typeCounts[3]++;
        std::cin >> dot;
        std::cin >> l;
        std::cin >> w;
        std::cin >> h;
        Van* van = new Van(sn, passengers, dot, l, w, h, false);
        vehicles[i] = static_cast<Van*>(van);
        toll += van->Toll();
        tons += van->LoadCapacity();
      } else if (sn[0] == '5')
      {
        typeCounts[4]++;
        std::cin >> dot;
        std::cin >> l;
        std::cin >> w;
        Tanker* tanker = new Tanker(sn, passengers, dot, l, w, false);
        vehicles[i] = static_cast<Tanker*>(tanker);
        toll += tanker->Toll();
        tons += tanker->LoadCapacity();
      } else if (sn[0] == '6')
      {
        typeCounts[5]++;
        std::cin >> dot;
        std::cin >> l;
        std::cin >> w;
        Flatbed* flatbed = new Flatbed(sn, passengers, dot, l, w, false);
        vehicles[i] = static_cast<Flatbed*>(flatbed);
        toll += flatbed->Toll();
        tons += flatbed->LoadCapacity();
      }
      else {
        typeCounts[6]++;
      }
    }
    std::cout << "Segment Summary\n===============\n\n"; //formatting to look like the excecutable
    std::cout << "  Cars:     " << typeCounts[1] << "\n";
    std::cout << "  Trucks:   " << typeCounts[2] << "\n";
    std::cout << "  Vans:     " << typeCounts[3] << "\n";
    std::cout << "  Tankers:  " << typeCounts[4] << "\n";
    std::cout << "  Flatbeds: " << typeCounts[5] << "\n";
    std::cout << "  Unknowns: " << typeCounts[0] << "\n";
    std::cout << "  Badsn:    " << typeCounts[6] << "\n";
    std::cout << "  Tonnage:  " << tons << "\n";
    std::cout << "  Tolls:    $" << toll << "\n";

    std::cout << "\nSegment Details\n===============\n\n";
    std::cout << std::setw(6) << "Type"
              << std::setw(7) << "Toll"
              << std::setw(10) << "Pass Cap"
              << std::setw(11) << "Load Cap "
              << std::setw(13) << "DOT License "
              << std::setw(15) << "Serial Number\n";

    std::cout << std::setw(6) << "----"
              << std::setw(7) << "----"
              << std::setw(10) << "--------"
              << std::setw(10) << "--------"
              << std::setw(13) << "-----------"
              << std::setw(16) << "-------------\n";

    int size = sizeof(vehicles)/sizeof(vehicles[0]);
    for (int i = 0; i < size; i++) //series of if loops essentially saying if the vehicle id type is found, display that series of data
    {
      if (typeid(*vehicles[i]) == typeid(Vehicle))
      {
        Vehicle* vehicle = vehicles[i];
        std::cout << std::setw(6) << vehicle->ShortName()
                  << std::setw(7) << vehicle->Toll()
                  << std::setw(10) << vehicle->PassengerCapacity()
                  << std::setw(10) << vehicle->LoadCapacity()
                  << std::setw(13) << "(NA)"
                  << std::setw(15) << vehicle->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Car))
      {
        Car* car = (Car*) vehicles[i];
        std::cout << std::setw(6) << car->ShortName()
                  << std::setw(7) << car->Toll()
                  << std::setw(10) << car->PassengerCapacity()
                  << std::setw(10) << car->LoadCapacity()
                  << std::setw(13) << "(NA)"
                  << std::setw(15) <<  car->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Truck))
      {
        Truck* truck = (Truck*) vehicles[i];
        std::cout << std::setw(6) << truck->ShortName()
                  << std::setw(7) << truck->Toll()
                  << std::setw(10) << truck->PassengerCapacity()
                  << std::setw(10) << truck->LoadCapacity()
                  << std::setw(13) << truck->DOTLicense()
                  << std::setw(15) << truck->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Van))
      {
        Van* van = (Van*) vehicles[i];
        std::cout << std::setw(6) << van->ShortName()
                  << std::setw(7) << van->Toll()
                  << std::setw(10) << van->PassengerCapacity()
                  << std::setw(10) << van->LoadCapacity()
                  << std::setw(13) << van->DOTLicense()
                  << std::setw(15) << van->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Tanker))
      {
        Tanker* tanker = (Tanker*) vehicles[i];
        std::cout << std::setw(6) << tanker->ShortName()
                  << std::setw(7) << tanker->Toll()
                  << std::setw(10) << tanker->PassengerCapacity()
                  << std::setw(10) << tanker->LoadCapacity()
                  << std::setw(13) << tanker->DOTLicense()
                  << std::setw(15) << tanker->SerialNumber();
      }
      if (typeid(*vehicles[i]) == typeid(Flatbed))
      {
        Flatbed* flatbed = (Flatbed*) vehicles[i];
        std::cout << std::setw(6) << flatbed->ShortName()
                  << std::setw(7) << flatbed->Toll()
                  << std::setw(10) << flatbed->PassengerCapacity()
                  << std::setw(10) << flatbed->LoadCapacity()
                  << std::setw(13) << flatbed->DOTLicense()
                  << std::setw(15) << flatbed->SerialNumber();
      }
      std::cout << "\n";
    }
  }
  std::cout << "\n\n...Thank you for using SunPass Tracker.\n\n"; //my attempts to have the display message on exit
  if (segmentSize == 0)
  {
    std::cout << "\n\n...Thank you for using SunPass Tracker.\n\n";
    return 0;
  }
  if (segmentSize > 100)
  {
    std::cout << "\n\n** Tracker error: max segment size exceeded.\n\n";
    return 0;
  }
  return 0;
}
