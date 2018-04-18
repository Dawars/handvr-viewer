//
// Created by David Komorowicz on 2018. 04. 17..
//

#include <functional>
#include <Leap.h>
#include "LeapProvider.h"

void LeapProvider::addListener(callback_function funct) {
    listeners.push_back(funct);
}

void LeapProvider::dispatchUpdateFrameEvent(const Leap::Frame &frame) {
    for (auto &update : listeners) {
        update(frame);
    }
}
