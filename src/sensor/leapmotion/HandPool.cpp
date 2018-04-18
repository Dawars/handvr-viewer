//
// Created by David Komorowicz on 2018. 04. 17..
//

#include "HandPool.h"
#include "HandModelBase.h"
#include "HandRepresentation.h"
#include <algorithm>

/**
     * MakeHandRepresentation receives a Hand and combines that with a HandModelBase to create a HandRepresentation
     * @param hand The Leap Hand data to be drive a HandModelBase
     * @param modelType Filters for a type of hand model, for example, physics or graphics hands.
     */

std::shared_ptr<HandRepresentation> HandPool::MakeHandRepresentation(Leap::Hand hand) {
    HandModelBase::Chirality handChirality = hand.isRight() ? HandModelBase::Chirality::Right
                                                            : HandModelBase::Chirality::Left;
    auto handRep= std::make_shared<HandRepresentation>(this, hand, handChirality);

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
    return handRep;// todo shared
}

void HandPool::RemoveHandRepresentation(HandRepresentation handRepresentation) {
//    activeHandReps.erase(std::remove(activeHandReps.begin(), activeHandReps.end(), handRepresentation),
//                         activeHandReps.end());//delete by value
}

void HandPool::ReturnToPool(HandModelBase &model) {
    /* ModelGroup modelGroup;
     bool groupFound = modelGroupMapping.TryGetValue(model, out modelGroup);
     Assert.IsTrue(groupFound);
     //First see if there is another active Representation that can use this model
     for (int i = 0; i < activeHandReps.Count; i++) {
         HandRepresentation rep = activeHandReps[i];
         if (rep.RepChirality == model.Handedness && rep.RepType == model.HandModelType) {
             bool modelFromGroupFound = false;
             if (rep.handModels != null) {
                 //And that Represention does not contain a model from this model's modelGroup
                 for (int j = 0; j < modelGroup.modelsCheckedOut.Count; j++) {
                     HandModelBase modelToCompare = modelGroup.modelsCheckedOut[j];
                     for (int k = 0; k < rep.handModels.Count; k++) {
                         if (rep.handModels[k] == modelToCompare) {
                             modelFromGroupFound = true;
                         }
                     }
                 }
             }
             if (!modelFromGroupFound) {
                 rep.AddModel(model);
                 modelToHandRepMapping[model] = rep;
                 return;
             }
         }
     }
     //Otherwise return to pool
     modelGroup.ReturnToGroup(model);
 */
}
