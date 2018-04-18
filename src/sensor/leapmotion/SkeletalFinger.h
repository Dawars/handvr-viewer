//
// Created by David Komorowicz on 2018. 04. 18..
//

#ifndef HANDVR_VIEWER_SKELETALFINGER_H
#define HANDVR_VIEWER_SKELETALFINGER_H


#include "FingerModel.h"

class SkeletalFinger : public FingerModel {
    /** Initializes the finger bones and joints by setting their positions and rotations. */
public:
    SkeletalFinger() = default;

    ~SkeletalFinger() override = default;

    void InitFinger() override;

    /** Updates the finger bones and joints by setting their positions and rotations. */
    void UpdateFinger() override;

protected :
    void SetPositions();

};


#endif //HANDVR_VIEWER_SKELETALFINGER_H
