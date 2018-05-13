//
// Created by David Komorowicz on 2018. 05. 13..
//

#ifndef HANDVR_VIEWER_HANDRENDERER_H
#define HANDVR_VIEWER_HANDRENDERER_H


#include <Leap.h>
#include <src/sensor/leapmotion/HandModel.h>

class HandRenderer {

public:
    HandRenderer() = default;

    virtual ~HandRenderer() = default;

    virtual void initialize()=0;

    virtual void paint(std::shared_ptr<HandModelBase> hand)=0;

};


#endif //HANDVR_VIEWER_HANDRENDERER_H
