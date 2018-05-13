//
// Created by David Komorowicz on 2018. 04. 18..
//

#ifndef HANDVR_VIEWER_SKELETALHAND_H
#define HANDVR_VIEWER_SKELETALHAND_H


#include "HandModel.h"

class SkeletalHand : public HandModel {
public:
    SkeletalHand() = default;

    ~SkeletalHand() override = default;

    /** Updates the hand and its component parts by setting their positions and rotations. */
    void UpdateHand() override;
};


#endif //HANDVR_VIEWER_SKELETALHAND_H
