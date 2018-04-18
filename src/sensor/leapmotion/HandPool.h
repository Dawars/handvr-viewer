//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_HANDPOOL_H
#define HANDVR_VIEWER_HANDPOOL_H


#include <Leap.h>

class HandRepresentation;
class HandModelBase;

class HandPool {
public:
    /**
    * MakeHandRepresentation receives a Hand and combines that with a HandModelBase to create a HandRepresentation
    * @param hand The Leap Hand data to be drive a HandModelBase
    */
    std::shared_ptr<HandRepresentation> MakeHandRepresentation(Leap::Hand);

    void RemoveHandRepresentation(HandRepresentation );

    void ReturnToPool(HandModelBase &model);

private:
    std::vector<std::shared_ptr<HandRepresentation>> activeHandReps;

};


#endif //HANDVR_VIEWER_HANDPOOL_H
