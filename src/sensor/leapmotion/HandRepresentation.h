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

protected:
    HandModelBase::Chirality RepChirality;
public:
    HandModelBase::Chirality getRepChirality() const;

    const Leap::Hand &getMostRecentHand() const;

protected:
    Leap::Hand MostRecentHand;
private:
    int HandID;
public:
    int getHandID() const;

};


#endif //HANDVR_VIEWER_HANDREPRESENTATION_H
