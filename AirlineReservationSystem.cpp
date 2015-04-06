//
//  AirlineReservationSystem.cpp
//  FlightReservationSystem
//
//  Created by burakkantarci on 27.07.2014.
//  Copyright (c) 2014 burakkantarci. All rights reserved.
//

#include "AirlineReservationSystem.h"

AirlineReservationSystem::AirlineReservationSystem(){
    
    fHead = NULL;
    fSize = 0;
    
}

AirlineReservationSystem::~AirlineReservationSystem(){
    
    while(fSize != 0) {
        Flight * cur = fHead;
        fHead = cur -> Flight::getFNext();
        delete cur;
        cur = NULL;
        fSize--;
    }
    delete fHead;
    fHead = NULL;
    
}

void AirlineReservationSystem::addFlight(const int flightId,const string fromCity, const string toCity){
    
    if(findFlight(flightId) == false){
        
        Flight * newFlight = new Flight(flightId, fromCity, toCity);
        
        if(fSize == 0) {
            fHead = newFlight;
            fSize++;
        }
        else {
            if(fHead -> Flight::getFlightId() > flightId){
                newFlight -> Flight::setFNext(fHead);
                fHead = newFlight;
                fSize++;
            }
            else {
                Flight * currentFlight = fHead;
                
                //Go previous
                while((currentFlight -> Flight::getFNext() != NULL) && (flightId > currentFlight -> Flight::getFNext() -> Flight::getFlightId()))
                    currentFlight = currentFlight -> Flight::getFNext();
                
                //Add Flight to the target
                newFlight -> Flight::setFNext(currentFlight -> Flight::getFNext());
                currentFlight -> setFNext(newFlight);
                fSize++;
            }
        }
        cout << "Flight with id: " << flightId << " from: " << fromCity << " to: " << toCity << " added to system" << endl;
        
    }
    else
        cout << " ! " << flightId << " flightID is already in the system. You cannot add more than one flight with the same ID" << endl;
    
}
void AirlineReservationSystem::removeFlight(const int flightId){
 
   if(findFlight(flightId) == true){
       
       if(fSize == 1) {
           delete fHead;
           fHead = NULL;
           fSize--;
       }
       else {
           
           if (fHead -> Flight::getFlightId() == flightId) {
               Flight * cur = fHead;
               fHead = fHead -> Flight::getFNext();
               delete cur;
               cur = NULL;
           } else {
               
               Flight * prevFlight = fHead;
               //Go previous
               while((prevFlight -> Flight::getFNext() != NULL) && (flightId != prevFlight -> Flight::getFNext() -> Flight::getFlightId()))
                   prevFlight = prevFlight -> Flight::getFNext();
               
               //Delete flight at the target
               Flight * currentFlight = prevFlight -> Flight::getFNext();
               prevFlight -> Flight::setFNext(prevFlight -> Flight::getFNext() -> Flight::getFNext());
               
               delete currentFlight;
               currentFlight = NULL;
           }
           fSize--;
           cout << "Flight with id: " << flightId << " removed." << endl;
       }
       
   }
   else
       cout << " ! " << flightId << " flightID is not in the system. You cannot remove a flight that is not in the system." << endl;

}

void AirlineReservationSystem::addPassenger(const int flightId, const string firstName, const string lastName){
    Flight * currentFlight = NULL;
    
    if(fHead != NULL){
        
        //Find the flight
        currentFlight = fHead;
        
        while((currentFlight -> Flight::getFNext() != NULL) && (currentFlight -> Flight::getFlightId() != flightId ))
            currentFlight = currentFlight -> Flight::getFNext();
        
        if(currentFlight -> Flight::getFlightId() == flightId){
            //Check the passenger
            if(findPassenger(currentFlight, firstName, lastName) == false){
                
                Passenger * newPassenger = new Passenger;
                newPassenger -> firstName = firstName;
                newPassenger -> lastName = lastName;
                
                int pSize = currentFlight -> Flight::getPSize();
                
                if(pSize == 0){
                    currentFlight -> Flight::setPHead(newPassenger);
                    newPassenger -> pNext = NULL;
                    pSize++;
                    currentFlight -> Flight::setPSize(pSize);
                } else {
                    Passenger * last = currentFlight -> getPHead();
                    while(last -> pNext != NULL)
                        last = last -> pNext;
                    
                    last -> pNext = newPassenger;
                    newPassenger -> pNext = NULL;
                    pSize++;
                    currentFlight -> Flight::setPSize(pSize);
                }
                
                cout << firstName << " " << lastName << " added to the flight with id:" << currentFlight -> Flight::getFlightId() << " From: " << currentFlight -> Flight::getFromCity() << " To: " << currentFlight -> Flight::getToCity() <<  endl;
            }
            else
                cout << "! Error at adding passenger! " << firstName << " " << lastName<< " is already in the system." << endl;
        }
        else
            cout << "! Error at adding passenger! " << "There is no flight with id: " << flightId << endl;
    }
    else
        cout << "! Error at adding passenger! There is no flight" << endl;
}

void AirlineReservationSystem::removePassenger(const int flightId, const string firstName, const string lastName){
    Flight * currentFlight = NULL;
    
    if(fHead != NULL){
        
        currentFlight = fHead;
        
        while((currentFlight -> Flight::getFNext() != NULL) && (currentFlight -> Flight::getFlightId() != flightId))
            currentFlight = currentFlight -> getFNext();
        
        if(currentFlight -> Flight::getFlightId() == flightId){
            if(findPassenger(currentFlight, firstName, lastName)){
                
                Passenger * curPas = currentFlight -> Flight::getPHead();
                int pSize = currentFlight -> Flight::getPSize();

                if(pSize == 1){
                    delete curPas;
                    curPas = NULL;
                    currentFlight -> setPHead(NULL);
                    pSize--;
                    currentFlight -> Flight::setPSize(pSize);
                }
                if(pSize > 1){
                    
                    Passenger * prevPas = currentFlight -> Flight::getPHead();
                    
                    if(prevPas -> firstName == firstName && prevPas -> lastName == lastName){
                        
                        currentFlight -> setPHead(prevPas -> pNext);
                        delete prevPas;
                        prevPas = NULL;
                        pSize--;
                        currentFlight -> Flight::setPSize(pSize);
                        
                    } else{
                    
                        while( (prevPas -> pNext != NULL) && (prevPas -> pNext -> firstName != firstName) && (prevPas -> pNext -> lastName != lastName))
                            prevPas = prevPas -> pNext;
                        
                        Passenger * curPas = prevPas -> pNext;
                        prevPas -> pNext = curPas -> pNext;
                        
                        delete curPas;
                        curPas = NULL;
                        pSize--;
                        currentFlight -> Flight::setPSize(pSize);
                    }
                }
                cout << firstName << " " << lastName << " successfully removed from the flight with id:" << currentFlight -> Flight::getFlightId() << " From: " << currentFlight -> Flight::getFromCity() << " To: " << currentFlight -> Flight::getToCity() <<  endl;

                
            } else
                cout << "! Error at removing passenger! " << firstName << " " << lastName<< " is not in the system." << endl;
        }
        else
            cout << "! Error at removing passenger! " << "There is no flight with id: " << flightId << endl;
    }
    else
        cout << "! Error at removing passenger! There is no flight" << endl;
}

void AirlineReservationSystem::showFlight(const int flightId) const{
    
    Flight * currentFlight = NULL;
    
    if(fHead != NULL){
        
        //Find the flight
        currentFlight = fHead;
        
        while((currentFlight -> Flight::getFNext() != NULL) && (currentFlight -> Flight::getFlightId() != flightId ))
            currentFlight = currentFlight -> Flight::getFNext();
        
        
        if(currentFlight -> Flight::getFlightId() == flightId){
            
            cout << "Flight " << currentFlight -> Flight::getFlightId() << " From: " << currentFlight -> Flight::getFromCity() << " To: " << currentFlight -> Flight::getToCity() << endl;
            
            Passenger * curPas = currentFlight -> Flight::getPHead();

            for(int i = 0; i < currentFlight -> Flight::getPSize() ; i++){
                cout << " - " << curPas -> firstName << " " << curPas -> lastName << endl;
                curPas = curPas -> pNext;
            }
            
        } else
            cout << "! Error at showing flight with id: " << flightId << " There is no matching flight." << endl;
    } else
        cout << "! Error at showing flightwith id: " << flightId << " There is no flight." << endl;

    
}

void AirlineReservationSystem::showPassenger(const string firstName, const string lastName) const{
    
    cout << "Flights for " << firstName << " " << lastName << endl;
    
    for(Flight * cur = fHead; cur != NULL ; cur = cur -> Flight::getFNext())
    {
        Passenger * curPas = cur -> Flight::getPHead();
        
        while ((curPas != NULL)) {
            
            if((curPas -> firstName == firstName) && (curPas -> lastName == lastName) )
                cout << " - " << "Flight " << cur -> Flight::getFlightId() << " From: " << cur -> Flight::getFromCity() << " To: " << cur -> Flight::getToCity() << endl;
        
            curPas = curPas -> pNext;
        }
        
        delete curPas;
        curPas = NULL;
    }
    
}

void AirlineReservationSystem::showAllFlights() const{
    
    cout << "All Flights " << endl;
    cout << endl;
    
    for(Flight * cur = fHead ; cur!=NULL ; cur = cur -> Flight::getFNext()){
        
        cout << "Flight " << cur -> Flight::getFlightId() << " From: " << cur -> Flight::getFromCity() << " To: " << cur -> Flight::getToCity() << endl;
        cout << endl;
        if( cur -> Flight::getPHead() != NULL) {
            for(Passenger * curPas = cur -> Flight::getPHead(); curPas != NULL ; curPas = curPas -> pNext){
                cout << " - " << curPas -> firstName << " " << curPas -> lastName << endl;
            }
        } else
            cout << " - No passenger" << endl;
        cout << endl;

    }
    
}

bool AirlineReservationSystem::findFlight(const int flightId){
    
    Flight * currentFlight;
    bool result = false;
    
    if(fHead != NULL){
        
        currentFlight = fHead;
        
        while((currentFlight -> Flight::getFNext() != NULL) && (currentFlight -> Flight::getFlightId() != flightId ))
            currentFlight = currentFlight -> Flight::getFNext();
            
        if(currentFlight -> Flight::getFlightId() == flightId)
            result = true;
        
    }
    
    currentFlight = NULL;
    
    return result;
}

bool AirlineReservationSystem::findPassenger(Flight * currentFlight, const string firstName, const string lastName){
    bool result = false;
    
    Passenger * pCurrent = currentFlight -> Flight::getPHead();
    
    if ( pCurrent != NULL){
        while ( (pCurrent -> pNext != NULL) && (pCurrent -> firstName != firstName) && (pCurrent -> lastName != lastName )) {
            pCurrent = pCurrent -> pNext;
        }
        
       if((pCurrent -> firstName == firstName) && (pCurrent -> lastName == lastName ))
           result = true;
    }
    
    pCurrent = NULL;
    
    return result;
}
