//
//  Flight.h
//  FlightReservationSystem
//
//  Created by burakkantarci on 27.07.2014.
//  Copyright (c) 2014 burakkantarci. All rights reserved.
//

#ifndef __FlightReservationSystem__Flight__
#define __FlightReservationSystem__Flight__

#include <iostream>
#include <string>
using namespace std;


struct Passenger {
    string firstName;
    string lastName;
    Passenger* pNext;
};

class Flight {
public:
    Flight( const int flightId, const string fromCity, const string toCity );
    ~Flight();
    
    void setFlightId(const int fID);
    int getFlightId();
    
    void setFromCity (const string fCity);
    string getFromCity();
    
    void setToCity (const string tCity);
    string getToCity();
    
    void setPHead(Passenger * pHead);
    Passenger * getPHead();
    
    void setFNext(Flight * fNext);
    Flight * getFNext();
    
    void setPSize(int);
    int getPSize();

private:
    int flightId;
    string fromCity;
    string toCity;
    Passenger* pHead;
    Flight* fNext;
    
    int pSize; //Passenger size

};


#endif /* defined(__FlightReservationSystem__Flight__) */
