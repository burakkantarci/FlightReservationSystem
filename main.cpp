//
//  main.cpp
//  FlightReservationSystem
//
//  Created by burakkantarci on 27.07.2014.
//  Copyright (c) 2014 burakkantarci. All rights reserved.
//

#include <iostream>

#include "AirlineReservationSystem.h"

int main()
{
    const int id1 = 1;
    const int id2 = 2;
    const int id3 = 5;
    const int id4 = 7;
    const int id5 = 3;
    
    const string from1 = "İstanbul";
    const string to1= "Ankara";
    
    const string from2 = "İzmir";
    const string to2 = "Trabzon";
    
    const string from3 = "Isparta";
    const string to3 = "İstanbul";
    
    const string from4 = "Ankara";
    const string to4 = "İstanbul";
    
    const string from5 = "Ankara";
    const string to5 = "San Francisco";
    
    const string fName1 = "Burak";
    const string sName1 = "Kantarcı";
    
    const string fName2 = "Rana";
    const string sName2 = "Ulusoy";
    
    const string fName3 = "Oğuzhan";
    const string sName3 = "Karabacak";
    
    const string fName4 = "Başak";
    const string sName4 = "Kantarcı";
    
    
    AirlineReservationSystem a1;
    
    a1.addFlight(id1, from1, to1);
    a1.addFlight(id1, from2, to2);
    a1.addFlight(id2, from2, to2);
    a1.addFlight(id3, from3, to3);
    a1.addFlight(id4, from4, to4);
    a1.addFlight(id5, from5, to5);
    
    cout << endl;
    
    a1.showAllFlights();
    
    a1.removeFlight(id4);
    a1.removeFlight(id4);
    
    cout << endl;
    
    a1.showAllFlights();
    
    a1.addPassenger(id1, fName1, sName1);
    a1.addPassenger(id1, fName2, sName2);
    a1.addPassenger(id2, fName2, sName2);
    a1.addPassenger(id3, fName3, sName3);
    a1.addPassenger(id4, fName3, sName3);
    a1.addPassenger(id5, fName4, sName4);
    
    cout << endl;
    
    a1.showAllFlights();
    
    a1.removePassenger(id1, fName1, sName1);
    
    cout << endl;
    
    a1.showAllFlights();
    
    a1.showPassenger(fName2, sName2);
    
    cout << endl;
    
    a1.showFlight(id1);
    
    return 0;
    
}