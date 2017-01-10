//
// Created by ori on 28/11/16.
//

#ifndef ASS2_FLOW_H
#define ASS2_FLOW_H

#include "src/TaxiCenter.h"
#include "src/Parser.h"

/******************************************************************************
* Flow: handlesthe program flow. this class uses the input parser to
* initialize and update the taxi center.
******************************************************************************/
class TaxiCenterFlow {
private:
    Parser parser;
    TaxiCenter* center;
public:
    bool shouldStop;
    TaxiCenterFlow(int port);
    ~TaxiCenterFlow();
    void initialize();
    static void* createRoute(void* center);
    void run();
};

#endif //ASS2_FLOW_H
