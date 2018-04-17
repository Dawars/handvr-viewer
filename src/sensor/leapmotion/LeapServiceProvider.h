//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_LEAPSERVICEPROVIDER_H
#define HANDVR_VIEWER_LEAPSERVICEPROVIDER_H


#include "LeapProvider.h"

class LeapServiceProvider : public LeapProvider, public Leap::Listener {

public:
    LeapServiceProvider();

    ~LeapServiceProvider() override;

    Leap::Frame CurrentFrame;

    const Leap::Controller &getLeapController() const;

    /** True, if the Leap Motion hardware is plugged in and this application is connected to the Leap Motion service. */
    bool isConnected();

protected:
    Leap::Controller leap_controller;

private:
    void onConnect(const Leap::Controller &) override;

    void onFrame(const Leap::Controller &) override;

};


#endif //HANDVR_VIEWER_LEAPSERVICEPROVIDER_H
