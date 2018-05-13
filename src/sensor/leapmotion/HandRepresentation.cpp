//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandRepresentation.h"

HandRepresentation::HandRepresentation(HandPool *parent, std::shared_ptr<Leap::Hand> hand,
                                       HandModelBase::Chirality repChirality) {

    this->parent = parent;
    this->HandID = hand->id();
    this->RepChirality = repChirality;
    this->MostRecentHand = hand;
}

int HandRepresentation::getHandID() const {
    return HandID;
}

HandModelBase::Chirality HandRepresentation::getRepChirality() const {
    return RepChirality;
}

const std::shared_ptr<Leap::Hand> &HandRepresentation::getMostRecentHand() const {
    return MostRecentHand;
}

void HandRepresentation::UpdateRepresentation(std::shared_ptr<Leap::Hand> hand) {
    MostRecentHand = hand;
    handModel->SetLeapHand(hand); // update Leap::Hand
    handModel->UpdateHand(); // update model based on Leap::Hand
}

void HandRepresentation::Finish() {
    handModel->FinishHand();
    handModel = nullptr;

    parent->RemoveHandRepresentation(this);
}

void HandRepresentation::AddModel(std::shared_ptr<HandModelBase> model) {
    handModel = model; // fixme add model
    auto hand = model->GetLeapHand();
    if (hand == nullptr) {
        model->SetLeapHand(MostRecentHand);
        model->InitHand();
        model->BeginHand();
        model->UpdateHand();
    } else {
        model->SetLeapHand(MostRecentHand);
        model->BeginHand();
    }
}
