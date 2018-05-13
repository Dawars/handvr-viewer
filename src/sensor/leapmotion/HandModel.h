//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_HANDMODEL_H
#define HANDVR_VIEWER_HANDMODEL_H


#include "HandModelBase.h"
#include <array>
#include <qlogging.h>

class HandModel : public HandModelBase {
    /** The number of fingers on a hand.*/
public:
    static const int NUM_FINGERS = 5;

    // Leap references
    /** The Leap Hand object this hand model represents. */
protected:
    std::shared_ptr<Leap::Hand> hand_;

    HandModel() = default;

    ~HandModel() override = default;

public:

    /**
    * Returns the Leap Hand object represented by this HandModel.
    * Note that any physical quantities and directions obtained from the
    * Leap Hand object are relative to the Leap Motion coordinate system,
    * which uses a right-handed axes and units of millimeters.
    */
    std::shared_ptr<Leap::Hand> GetLeapHand() const override;

    /**
    * Assigns a Leap Hand object to this hand model.
    * Note that the Leap Hand objects are recreated every frame. The parent
    * HandController calls this method to set or update the underlying hand.
    */
    virtual void SetLeapHand(std::shared_ptr<Leap::Hand> hand) override;

    /**
       * Implement this function to initialise this hand after it is created.
       * This function is called by the HandController during the Unity Update() phase when a new hand is detected
       * by the Leap Motion device.
       */
    virtual void InitHand() override;
};


#endif //HANDVR_VIEWER_HANDMODEL_H
