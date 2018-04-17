//
// Created by David Komorowicz on 2018. 04. 17..
//

#ifndef HANDVR_VIEWER_LEAPPROVIDER_H
#define HANDVR_VIEWER_LEAPPROVIDER_H

#include <functional>
#include <Leap.h>

class LeapProvider {
protected:
    LeapProvider();

    void dispatchUpdateFrameEvent(const Leap::Frame &frame);

    using callback_function = std::function<void(const Leap::Frame &)>;
public:
    virtual ~LeapProvider();
    void addListener(callback_function);

private:
    std::vector<callback_function> listeners;
};


#endif //HANDVR_VIEWER_LEAPPROVIDER_H
