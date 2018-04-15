//
// Created by David Komorowicz on 2018. 04. 07..
//

#ifndef HANDVR_LEAPDATA_H
#define HANDVR_LEAPDATA_H

#include <Leap.h>

// Model??
class LeapData : public Leap::Listener {
public:
    LeapData();

    ~LeapData();

    virtual void onConnect(const Leap::Controller &);

    virtual void onFrame(const Leap::Controller &);

    int getNumHands() const;

    const Leap::HandList &getHandList() const;

private:
    Leap::Frame frame;
    Leap::HandList handList;


//    QMainWindow *window;
};


#endif //HANDVR_LEAPDATA_H
