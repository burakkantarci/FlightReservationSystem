//
//  Flight.cpp
//  FlightReservationSystem
//
//  Created by burakkantarci on 27.07.2014.
//  Copyright (c) 2014 burakkantarci. All rights reserved.
//

#include "Flight.h"

Flight::Flight( const int flightId, const string fromCity, const string toCity ){
    setFlightId(flightId);
    setFromCity(fromCity);
    setToCity(toCity);
    setPHead(NULL);
    setFNext(NULL);
    setPSize(0);
}
Flight::~Flight(){
    
    while(pHead != NULL) {
        Passenger * cur = pHead;
        pHead = cur -> pNext;
        delete cur;
        cur = NULL;
    }
    delete pHead;
    pHead = NULL;
    
}


void Flight::setFlightId(const int fId){
    flightId = fId;
}

int Flight::getFlightId(){
    return flightId;
}

void Flight::setFromCity(const string fCity){
    fromCity = fCity;
}
string Flight::getFromCity(){
    return fromCity;
}

void Flight::setToCity(const string tCity){
    toCity = tCity;
}
string Flight::getToCity() {
    return toCity;
}

void Flight::setFNext(Flight * fNexxt){
    fNext = fNexxt;
}
Flight * Flight::getFNext(){
    return fNext;
}

void Flight::setPHead(Passenger * pasHead){
    pHead = pasHead;
}

Passenger * Flight::getPHead(){
    return pHead;
}

void Flight::setPSize(int size){
    pSize = size;
}
int Flight::getPSize(){
    return pSize;
}

