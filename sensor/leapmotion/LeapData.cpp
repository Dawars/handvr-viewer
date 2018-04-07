//
// Created by David Komorowicz on 2018. 04. 07..
//

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
    const Frame frame = controller.frame();
    std::cout << "Frame id: " << frame.id()
              << ", timestamp: " << frame.timestamp()
              << ", hands: " << frame.hands().count()
              << ", fingers: " << frame.fingers().count()
              << ", tools: " << frame.tools().count()
              << ", gestures: " << frame.gestures().count() << std::endl;
}

void LeapData::onConnect(const Controller &controller) {
    std::cout << "Connected" << std::endl;
    controller.enableGesture(Gesture::TYPE_SWIPE);
}