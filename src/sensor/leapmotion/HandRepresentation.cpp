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
    for (auto &handModel : handModels) {
        /*if (handModel.group != null && handModel.group.HandPostProcesses.GetPersistentEventCount() > 0) {
            PostProcessHand.CopyFrom(hand);
            handModel.group.HandPostProcesses.Invoke(PostProcessHand);
            handModel.SetLeapHand(PostProcessHand);
        } else {*/
        handModel->SetLeapHand(hand); // update Leap::Hand
//                }
        handModel->UpdateHand(); // update model based on Leap::Hand
    }
}

void HandRepresentation::Finish() {
    for (auto &handModel : handModels) {
        handModel->FinishHand();
        parent->ReturnToPool(handModel);
        handModel = nullptr;
    }
    parent->RemoveHandRepresentation(this);
}

void HandRepresentation::AddModel(std::shared_ptr<HandModelBase> model) {
    handModels.push_back(model); // fixme add model
    /*if (model->GetLeapHand() == nullptr) {
        model->SetLeapHand(MostRecentHand);
        model->InitHand();
        model->BeginHand();
        model->UpdateHand();
    } else {
        model->SetLeapHand(MostRecentHand);
        model->BeginHand();
    }*/
}

void HandRepresentation::RemoveModel(std::shared_ptr<HandModelBase> model) {
    handModels.erase(std::remove(handModels.begin(), handModels.end(), model), handModels.end());
}
