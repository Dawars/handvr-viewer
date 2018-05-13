//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandPool.h"
#include "HandModelBase.h"
#include "HandRepresentation.h"
#include "HandModel.h"
#include "SkeletalHand.h"
#include <algorithm>
#include <memory>
#include <qdebug.h>
/**
 * MakeHandRepresentation receives a Hand and combines that with a HandModelBase to create a HandRepresentation
 * @param hand The Leap Hand data to be drive a HandModelBase
 */
std::shared_ptr<HandRepresentation> HandPool::MakeHandRepresentation(std::shared_ptr<Leap::Hand> hand) {
    qDebug() << "HandPool::MakeHandRepr " << hand->id();

    HandModelBase::Chirality handChirality = hand->isRight() ? HandModelBase::Chirality::Right
                                                             : HandModelBase::Chirality::Left;
    auto handRep = std::make_shared<HandRepresentation>(this, hand, handChirality);

    std::shared_ptr<HandModelBase> model{std::make_shared<SkeletalHand>()};
    handRep->AddModel(model);
    activeHandReps.push_back(handRep);
    return handRep;
}

void HandPool::RemoveHandRepresentation(HandRepresentation *handRepresentation) {
    auto it = std::find_if(activeHandReps.begin(), activeHandReps.end(), [&](std::shared_ptr<HandRepresentation> p) {
        return &*p == handRepresentation;
    });

    if (it != activeHandReps.end()) {
        activeHandReps.erase(it);
    }
}


const std::vector<std::shared_ptr<HandRepresentation>> &HandPool::getActiveHandReps() const {
    return activeHandReps;
}
