//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_HANDMODELBASE_H
#define HANDVR_VIEWER_HANDMODELBASE_H


#include <Leap.h>

class HandModelBase {
public:
    enum Chirality {
        Left, Right
    };

    /**
    * Returns the Leap Hand object represented by this HandModel.
    * Note that any physical quantities and directions obtained from the
    * Leap Hand object are relative to the Leap Motion coordinate system,
    * which uses a right-handed axes and units of millimeters.
    */
    virtual std::shared_ptr<Leap::Hand> GetLeapHand() const = 0;

    /**
    * Assigns a Leap Hand object to this hand model.
    * Note that the Leap Hand objects are recreated every frame. The parent
    * HandController calls this method to set or update the underlying hand.
    */
//    virtual void SetLeapHand(Leap::Hand hand) = 0;
    virtual void SetLeapHand(std::shared_ptr<Leap::Hand> hand) = 0;

    /**
       * Implement this function to initialise this hand after it is created.
       * This function is called by the HandController during the Unity Update() phase when a new hand is detected
       * by the Leap Motion device.
       */
    virtual void InitHand() = 0;

    virtual void BeginHand();

    virtual void UpdateHand() = 0;

    virtual void FinishHand();


private:
    bool isTracked = false;
public:
    bool IsTracked() const;

protected:
    HandModelBase() = default;

    virtual ~HandModelBase() = default;
};


#endif //HANDVR_VIEWER_HANDMODELBASE_H
