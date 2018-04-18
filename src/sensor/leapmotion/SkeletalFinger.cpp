//
// Created by David Komorowicz on 2018. 04. 18..
//

#include "SkeletalFinger.h"

/** Initializes the finger bones and joints by setting their positions and rotations. */
void SkeletalFinger::InitFinger() {
    SetPositions();
}

/** Updates the finger bones and joints by setting their positions and rotations. */
void SkeletalFinger::UpdateFinger() {
    SetPositions();
}

void SkeletalFinger::SetPositions() {
    for (size_t i = 0; i < bones.size(); ++i) {
//        if (bones[i] != null) {
//        bones[i].transform.position = GetBoneCenter(i);
//        bones[i].transform.rotation = GetBoneRotation(i);
//        }
    }

    for (size_t i = 0; i < joints.size(); ++i) {
//        if (joints[i] != null) {
//        joints[i].transform.position = GetJointPosition(i + 1);
//        joints[i].transform.rotation = GetBoneRotation(i + 1);
//        }
    }
}