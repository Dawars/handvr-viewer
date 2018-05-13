//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandModel.h"


std::shared_ptr<Leap::Hand> HandModel::GetLeapHand() const {
    return hand_;
}

void HandModel::SetLeapHand(std::shared_ptr<Leap::Hand> hand) {
    hand_ = hand;
}

void HandModel::InitHand() {

}
