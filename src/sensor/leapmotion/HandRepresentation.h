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
    std::shared_ptr<HandModelBase> handModel;

    HandRepresentation(HandPool *parent, std::shared_ptr<Leap::Hand> hand, HandModelBase::Chirality repChirality);

/** Calls Updates in HandModelBases that are part of this HandRepresentation */
    void UpdateRepresentation(std::shared_ptr<Leap::Hand> hand);

    void AddModel(std::shared_ptr<HandModelBase> model);


    HandModelBase::Chirality getRepChirality() const;

    const std::shared_ptr<Leap::Hand> &getMostRecentHand() const;

    /** To be called if the HandRepresentation no longer has a Leap Hand. */
    void Finish();

    int getHandID() const;

protected:
    HandModelBase::Chirality RepChirality;
    std::shared_ptr<Leap::Hand> MostRecentHand;
private:
    int HandID;
};


#endif //HANDVR_VIEWER_HANDREPRESENTATION_H
