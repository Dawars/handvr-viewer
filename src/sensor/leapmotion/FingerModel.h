//
// Created by David Komorowicz on 2018. 04. 18..
//

#ifndef HANDVR_VIEWER_FINGERMODEL_H
#define HANDVR_VIEWER_FINGERMODEL_H

#include <Leap.h>
#include <QMatrix4x4>
#include <array>

/**
  * The base class for all fingers.
  *
  * This class serves as the interface between the HandController object,
  * the parent Hand object and the concrete finger objects.
  *
  * Subclasses of FingerModel must implement InitFinger() and UpdateFinger(). The InitHand() function
  * is typically called by the parent HandModel InitHand() method; likewise, the UpdateFinger()
  * function is typically called by the parent HandModel UpdateHand() function.
  */
class FingerModel {
/** The number of bones in a finger. */
public:

    FingerModel() = default;

    virtual ~FingerModel() = default;

    static const int NUM_BONES = 4;

    /** The number of joints in a finger. */
    static const int NUM_JOINTS = 3;

    Leap::Finger::Type fingerType = Leap::Finger::TYPE_INDEX;

    // Unity references
    /** Bones positioned and rotated by FingerModel. */
    std::array<QMatrix4x4, NUM_BONES> bones;
    /** Joints positioned and rotated by FingerModel. */
    std::array<QMatrix4x4, NUM_BONES - 1> joints;
protected:
    // Leap references
    /** The Leap Hand object. */
    std::shared_ptr<Leap::Hand> hand_;
    /** The Leap Finger object. */
    Leap::Finger finger_;

    /** Sets the Leap Hand and Leap Finger for this finger.
    * Note that Leap Hand and Finger objects are recreated every frame. The
    * parent HandModel object calls this function to set or update the underlying
    * finger. The tracking data in the Leap objects are used to update the FingerModel.
    */
public:
    void SetLeapHand(std::shared_ptr<Leap::Hand> hand);

    /** The Leap Hand object. */
    std::shared_ptr<Leap::Hand> GetLeapHand() { return hand_; }

    /** The Leap Finger object. */
    Leap::Finger GetLeapFinger() { return finger_; }

    /**
    * Implement this function to initialize this finger after it is created.
    * Typically, this function is called by the parent HandModel object.
    */
    virtual void InitFinger() {
        UpdateFinger();
    }

    /**
    * Implement this function to update this finger once per game loop.
    * Typically, this function is called by the parent HandModel object's
    * UpdateHand() function, which is called in the Unity Update() phase for
    * graphics hand models and in the FixedUpdate() phase for physics hand
    * models.
    */
    virtual void UpdateFinger() = 0;

};


#endif //HANDVR_VIEWER_FINGERMODEL_H
