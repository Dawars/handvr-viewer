//
// Created by David Komorowicz on 2018. 04. 07..
//

#include "../../ui/mainwindow.h"
#include "LeapController.h"
#include "LeapServiceProvider.h"

using namespace Leap;

LeapController::LeapController() {
    provider = std::make_unique<LeapServiceProvider>();

    // or std::bind
//    using namespace std::placeholders;
//    std::function<void(const Leap::Frame &f)> f = std::bind(&LeapController::OnUpdateFrame, this, _1);
    provider->addListener([=](const Leap::Frame &frame) { this->OnUpdateFrame(frame); });
}

LeapController::~LeapController() {

}

void LeapController::OnUpdateFrame(const Leap::Frame &frame) {
//    this->frame = frame;

    std::cout << "Frame id: " << frame.id()
              << ", timestamp: " << frame.timestamp()
              << ", hands: " << frame.hands().count()
              << ", fingers: " << frame.fingers().count()
              << std::endl;
}


