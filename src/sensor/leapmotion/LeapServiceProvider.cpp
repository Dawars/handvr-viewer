//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "LeapServiceProvider.h"


void LeapServiceProvider::onConnect(const Leap::Controller &controller) {
    std::cout << "Connected" << controller.isConnected() << std::endl;
}


LeapServiceProvider::LeapServiceProvider() {
    leap_controller.addListener(*this);
}

LeapServiceProvider::~LeapServiceProvider() {
    leap_controller.removeListener(*this);
}

void LeapServiceProvider::onFrame(const Leap::Controller &controller) {
    dispatchUpdateFrameEvent(controller.frame());
}


const Leap::Controller &LeapServiceProvider::getLeapController() const {
    return leap_controller;
}

bool LeapServiceProvider::isConnected() {
    return getLeapController().isConnected();
}