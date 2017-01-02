#include "Trip.h"
#include <sstream>

/******************************************************************************
* The function Operation: Trip constructor.
******************************************************************************/
Trip::Trip(int id, Point start, Point end, int numOfPass, double price, int time):
        id(id), start(start), end(end), numOfPass(numOfPass), price(price),
        time(time), route(NULL), totalMeterPassed(0) {
    for (int i = 0; i < this->numOfPass; i++) {
        passengers.push_back(new Passenger());
    }
}

int Trip::getId() {
    return this->id;
}

/******************************************************************************
* The function Operation: Trip destructor - delete the route if it's exist
* delete the passengers
******************************************************************************/
Trip::~Trip() {
    if(this->route != NULL){
        for (int i = 0; i < route->size(); i++){
            delete route->at(i);
        }
        route->clear();
        delete route;
    }
    for(int j = 0; j < passengers.size(); j++){
        delete passengers.at(j);
    }
    passengers.clear();
}

/******************************************************************************
* The function Operation: add meter to the total meter that passed
******************************************************************************/
void Trip::addMeter(){
    this->totalMeterPassed += 1;
}

/******************************************************************************
* The function Operation: get the next point from the route copy it delete the
* point from the route and return the copy
******************************************************************************/
Point* Trip::getNextPoint(){
    if (route->size() != 0) {
        Point* nextPoint = this->route->front();
        //safe copy
        nextPoint = new Point(*nextPoint);
        // add meter one passed
        this->addMeter();
        delete route->front();
        this->route->erase(route->begin());
        return nextPoint;
    }
    // if route is empty
    return NULL;
}

/******************************************************************************
* The function Operation: return the trip's price
******************************************************************************/
double Trip::getPrice() {
    return this->price;
}

/******************************************************************************
* The function Operation: return the trip's number of passengers
******************************************************************************/
int Trip::getNumPassengers(){
    return numOfPass;
}

/******************************************************************************
* The function Operation: calculate the sum of passengers's satisfacation and
* return it
******************************************************************************/
int Trip::sumOfSatisfaction() {
    int sum = 0;
    for (int i = 0; i < this->passengers.size(); i++){
        sum += this->passengers.at(i)->satisfacation();
    }
    return sum;
}

string Trip::serialize() {
    stringstream str;
    string start(this->start.serialize());
    string end(this->end.serialize());
    str << this->id;
    str <<  ",";
    str << start;
    str << ",";
    str << end;
    str <<  ",";
    str << this->numOfPass;
    str << ",";
    str << this->price;
    str << ",";
    str << this->time;
    return string(str.str());
}

