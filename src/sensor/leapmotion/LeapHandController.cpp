//
// Created by David Komorowicz on 2018. 04. 07..
//

#include "../../ui/mainwindow.h"
#include "LeapHandController.h"
#include "LeapServiceProvider.h"
#include <memory>

using namespace Leap;

LeapHandController::LeapHandController(std::shared_ptr<LeapProvider> provider) {
    this->provider = provider;

    // or std::bind
//    using namespace std::placeholders;
//    std::function<void(const Leap::Frame &f)> f = std::bind(&LeapHandController::OnUpdateFrame, this, _1);
    provider->addListener([=](const Leap::Frame &frame) { this->OnUpdateFrame(frame); });
}

LeapHandController::~LeapHandController() {

}

void LeapHandController::OnUpdateFrame(const Leap::Frame &frame) {
//    this->frame = frame;
/*

    std::cout << "Frame id: " << frame.id()
              << ", timestamp: " << frame.timestamp()
              << ", hands: " << frame.hands().count()
              << ", fingers: " << frame.fingers().count()
              << std::endl;
*/

    updateHandRepresentations(graphicsHandReps, frame);

}

void LeapHandController::updateHandRepresentations(std::map<int, std::shared_ptr<HandRepresentation>> &all_hand_reps,
                                                   const Leap::Frame &frame) {


    for (auto &hand : frame.hands()) {
        std::cout << "LeapHandController::updateHandRepresentations " << hand.id() << std::endl;

        std::shared_ptr<Leap::Hand> curHand = std::make_shared<Leap::Hand>(hand);
        std::shared_ptr<HandRepresentation> rep;

        auto it = all_hand_reps.find(curHand->id());
        rep = it->second;
        if (it == all_hand_reps.end()) { // no hand representation, create new
            rep = pool.MakeHandRepresentation(curHand);
            if (rep != nullptr)
                all_hand_reps.insert(std::pair(curHand->id(), rep));
        }
        if (rep != nullptr) {
            rep->IsMarked = true;
            rep->UpdateRepresentation(curHand);
            rep->LastUpdatedTime = (int) frame.timestamp();
        }

    }

    /** Mark-and-sweep to finish unused HandRepresentations */
    std::shared_ptr<HandRepresentation> toBeDeleted;
    for (auto r : all_hand_reps) {
        if (r.second->IsMarked) {
            r.second->IsMarked = false;
        } else {
            /** Initialize toBeDeleted with a value to be deleted */
            //Debug.Log("Finishing");
            toBeDeleted = r.second;
        }
    }
    /**Inform the representation that we will no longer be giving it any hand updates
     * because the corresponding hand has gone away */
    if (toBeDeleted != nullptr) {
        all_hand_reps.erase(toBeDeleted->getHandID());
        toBeDeleted->Finish();
    }
}


