//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_HANDREPRESENTATION_H
#define HANDVR_VIEWER_HANDREPRESENTATION_H


#include "HandPool.h"
#include "HandModelBase.h"

class HandRepresentation {
    HandPool *parent;
public:
    int LastUpdatedTime;
    bool IsMarked;
    Leap::Hand PostProcessHand;
    std::vector<HandModelBase> handModels;

    HandRepresentation(HandPool *parent, Leap::Hand hand, HandModelBase::Chirality repChirality);

/** Calls Updates in HandModelBases that are part of this HandRepresentation */
    void UpdateRepresentation(Leap::Hand hand);

    HandModelBase::Chirality getRepChirality() const;

    const Leap::Hand &getMostRecentHand() const;

    /** To be called if the HandRepresentation no longer has a Leap Hand. */
    void Finish();

    int getHandID() const;

protected:
    HandModelBase::Chirality RepChirality;
    Leap::Hand MostRecentHand;
private:
    int HandID;
};


#endif //HANDVR_VIEWER_HANDREPRESENTATION_H
