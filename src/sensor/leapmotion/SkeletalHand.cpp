//
// Created by David Komorowicz on 2018. 04. 18..
//

#include "SkeletalHand.h"

void SkeletalHand::UpdateHand() {
    SetPositions();
}

void SkeletalHand::SetPositions() {
    for (int f = 0; f < fingers.size(); ++f) {
//        if (fingers[f] != null) {
        fingers[f].UpdateFinger();
//        }
    }
/*
    if (palm != null) {
        palm.position = GetPalmCenter();
        palm.rotation = GetPalmRotation();
    }

    if (wristJoint != null) {
        wristJoint.position = GetWristPosition();
        wristJoint.rotation = GetPalmRotation();
    }

    if (forearm != null) {
        forearm.position = GetArmCenter();
        forearm.rotation = GetArmRotation();
    }*/
}