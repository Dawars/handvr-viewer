//
// Created by David Komorowicz on 2018. 04. 18..
//

#include "FingerModel.h"

void FingerModel::SetLeapHand(Leap::Hand hand) {
    hand_ = hand;
//        if (hand_ != null) {
    finger_ = hand.fingers()[(int) fingerType];
//        }
}