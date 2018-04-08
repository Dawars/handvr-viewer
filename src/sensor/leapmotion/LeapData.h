//
// Created by David Komorowicz on 2018. 04. 07..
//

#ifndef HANDVR_LEAPDATA_H
#define HANDVR_LEAPDATA_H

#include <Leap.h>

// Model??
class LeapData : public Leap::Listener {
public:
    LeapData(QMainWindow *window);

    ~LeapData();

    virtual void onConnect(const Leap::Controller &);

    virtual void onFrame(const Leap::Controller &);

private:
    Leap::Frame frame;

    int getNumHands() const;

//    QMainWindow *window;
};


#endif //HANDVR_LEAPDATA_H
