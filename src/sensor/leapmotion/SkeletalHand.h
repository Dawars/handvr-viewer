//
// Created by David Komorowicz on 2018. 04. 18..
//

#ifndef HANDVR_VIEWER_SKELETALHAND_H
#define HANDVR_VIEWER_SKELETALHAND_H


#include "HandModel.h"

class SkeletalHand : public HandModel {

    /** Updates the hand and its component parts by setting their positions and rotations. */
    void UpdateHand();

protected:
    void SetPositions();
};


#endif //HANDVR_VIEWER_SKELETALHAND_H
