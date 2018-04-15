//
// Created by David Komorowicz on 2018. 04. 07..
//

#include "../../ui/mainwindow.h"
#include "LeapData.h"

using namespace Leap;
Controller controller;

LeapData::LeapData() {
    controller.addListener(*this);
}

LeapData::~LeapData() {
    controller.removeListener(*this);

}


void LeapData::onFrame(const Controller &controller) {
    handList = frame.hands();

    frame = controller.frame();
    std::cout << "Frame id: " << frame.id()
              << ", timestamp: " << frame.timestamp()
              << ", hands: " << frame.hands().count()
              << ", fingers: " << frame.fingers().count()
              << ", tools: " << frame.tools().count()
              << ", gestures: " << frame.gestures().count() << std::endl;

//    window->updatedHandData(); // todo signal
}

const HandList &LeapData::getHandList() const {
    return handList;
}

void LeapData::onConnect(const Controller &controller) {
    std::cout << "Connected" << std::endl;
    controller.enableGesture(Gesture::TYPE_SWIPE);
}

int LeapData::getNumHands() const {
    return frame.hands().count();
}
