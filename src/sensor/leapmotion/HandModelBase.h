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

    virtual ~HandModelBase() = default;


    virtual Leap::Hand GetLeapHand() const = 0;

    virtual void SetLeapHand(Leap::Hand hand) = 0;

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

};


#endif //HANDVR_VIEWER_HANDMODELBASE_H
