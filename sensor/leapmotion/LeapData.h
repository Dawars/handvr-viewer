//
// Created by David Komorowicz on 2018. 04. 07..
//

#ifndef HANDVR_LEAPDATA_H
#define HANDVR_LEAPDATA_H

#include "Leap.h"


class LeapData : public Leap::Listener {
public:
    LeapData();
    ~LeapData();

    virtual void onConnect(const Leap::Controller &);

    virtual void onFrame(const Leap::Controller &);
};


#endif //HANDVR_LEAPDATA_H
