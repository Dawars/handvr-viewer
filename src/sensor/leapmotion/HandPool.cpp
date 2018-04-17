//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandPool.h"
#include "HandModelBase.h"

/**
     * MakeHandRepresentation receives a Hand and combines that with a HandModelBase to create a HandRepresentation
     * @param hand The Leap Hand data to be drive a HandModelBase
     * @param modelType Filters for a type of hand model, for example, physics or graphics hands.
     */

std::shared_ptr<HandRepresentation> HandPool::MakeHandRepresentation(Leap::Hand hand) {
    HandModelBase::Chirality handChirality = hand.isRight() ? HandModelBase::Chirality::Right
                                                            : HandModelBase::Chirality::Left;
    std::shared_ptr<HandRepresentation> handRep = std::make_shared(this, hand, handChirality);

    // todo
    /*for (int i = 0; i < ModelPool.Count; i++) {
        ModelGroup group = ModelPool[i];
        if (group.IsEnabled) {
            HandModelBase model = group.TryGetModel(handChirality);
            if (model != null) {
                handRep.AddModel(model);
                if (!modelToHandRepMapping.ContainsKey(model)) {
                    model.group = group;
                    modelToHandRepMapping.Add(model, handRep);
                }
            }
        }
    }*/
    activeHandReps.push_back(handRep);
    return handRep;
}