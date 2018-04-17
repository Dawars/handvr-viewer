//
// Created by David Komorowicz on 2018. 04. 07..
//

#ifndef HANDVR_LEAPDATA_H
#define HANDVR_LEAPDATA_H

#include <Leap.h>
#include "LeapProvider.h"

// Model??
class LeapController {
public:
    LeapController();

    ~LeapController();

    virtual void OnUpdateFrame(const Leap::Frame &);

protected:
    std::unique_ptr<LeapProvider> provider;

private:
//    Leap::Frame frame;

};


#endif //HANDVR_LEAPDATA_H
