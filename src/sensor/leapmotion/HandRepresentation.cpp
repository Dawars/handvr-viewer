//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandRepresentation.h"

HandRepresentation::HandRepresentation(HandPool *parent, Leap::Hand hand, HandModelBase::Chirality repChirality) {

    this->parent = parent;
    HandID = hand.id();
    this->RepChirality = repChirality;
    this->MostRecentHand = hand;
    this->PostProcessHand = Leap::Hand();
}

int HandRepresentation::getHandID() const {
    return HandID;
}

HandModelBase::Chirality HandRepresentation::getRepChirality() const {
    return RepChirality;
}

const Leap::Hand &HandRepresentation::getMostRecentHand() const {
    return MostRecentHand;
}

void HandRepresentation::UpdateRepresentation(Leap::Hand hand) {
    MostRecentHand = hand;
    for (int i = 0; i < handModels.size(); i++) {
        /*if (handModels[i].group != null && handModels[i].group.HandPostProcesses.GetPersistentEventCount() > 0) {
            PostProcessHand.CopyFrom(hand);
            handModels[i].group.HandPostProcesses.Invoke(PostProcessHand);
            handModels[i].SetLeapHand(PostProcessHand);
        } else {*/
        handModels[i].SetLeapHand(hand);
//                }
        handModels[i].UpdateHand();
    }
}

void HandRepresentation::Finish() {
    for (auto &handModel : handModels) {
        handModel.FinishHand();
        parent->ReturnToPool(handModel);
//        handModel = null;
    }
//    parent->RemoveHandRepresentation(*this);
}
