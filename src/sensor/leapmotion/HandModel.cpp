//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandModel.h"


Leap::Hand HandModel::GetLeapHand() const {
    return hand_;
}

void HandModel::SetLeapHand(Leap::Hand hand) {
    hand_ = hand;
    for (auto &finger : fingers) {
//        if (fingers[i] != null) {
        finger.SetLeapHand(hand_);
//        }
    }
}

void HandModel::InitHand() {
    for (int f = 0; f < fingers.size(); ++f) {
//        if (fingers[f] != null) {
        fingers[f].fingerType = (Leap::Finger::Type) f;
        fingers[f].InitFinger();
//        }
    }
}