//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandModelBase.h"

void HandModelBase::FinishHand() {
    /*if (OnFinish != null) {
        OnFinish();
    }*/
    isTracked = false;
}

bool HandModelBase::IsTracked() const {
    return isTracked;
}
