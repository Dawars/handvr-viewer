//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandModel.h"


std::shared_ptr<Leap::Hand> HandModel::GetLeapHand() const {
    return hand_;
}

void HandModel::SetLeapHand(std::shared_ptr<Leap::Hand> hand) {
    hand_ = hand;
    for (auto &finger : fingers) {
        if (finger != nullptr) { // fixme empty
            finger->SetLeapHand(hand_);
        }
    }
}

void HandModel::InitHand() {
    // todo check
    for (size_t f = 0; f < fingers.size(); ++f) {
        if (fingers[f] != nullptr) {
            fingers[f]->fingerType = (Leap::Finger::Type) f;
            fingers[f]->InitFinger();
        }
    }
}
