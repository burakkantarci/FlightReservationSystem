//
//  AirlineReservationSystem.h
//  FlightReservationSystem
//
//  Created by burakkantarci on 27.07.2014.
//  Copyright (c) 2014 burakkantarci. All rights reserved.
//

#ifndef __FlightReservationSystem__AirlineReservationSystem__
#define __FlightReservationSystem__AirlineReservationSystem__

#include <iostream>
#include <string>
#include "Flight.h"
using namespace std;

class AirlineReservationSystem {
public:
    AirlineReservationSystem();
    ~AirlineReservationSystem();
    void addFlight( const int flightId, const string fromCity, const string toCity );
    void removeFlight( const int flightId );
    void addPassenger( const int flightId, const string firstName, const string lastName );
    void removePassenger( const int flightId, const string firstName, const string lastName );
    void showFlight( const int flightId ) const;
    void showPassenger( const string firstName, const string lastName ) const;
    void showAllFlights() const;
    
    bool findFlight(const int flightId);
    bool findPassenger (Flight * currentFlight, const string firstName, const string lastName);
private:
    Flight* fHead;
    int fSize; //Flight size
};

#endif /* defined(__FlightReservationSystem__AirlineReservationSystem__) */
