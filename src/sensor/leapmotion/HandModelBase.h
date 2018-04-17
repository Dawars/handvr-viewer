//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_HANDMODELBASE_H
#define HANDVR_VIEWER_HANDMODELBASE_H


#include <Leap.h>

class HandModelBase {
public:
    enum Chirality {
        Left, Right
    };

    virtual void UpdateHand();

    virtual Leap::Hand GetLeapHand();

    virtual void SetLeapHand(Leap::Hand hand);
};


#endif //HANDVR_VIEWER_HANDMODELBASE_H
