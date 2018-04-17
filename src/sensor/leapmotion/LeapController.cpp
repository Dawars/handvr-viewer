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

    updateHandRepresentations(graphicsHandReps, frame);

}

void LeapController::updateHandRepresentations(std::map<int, HandRepresentation> &all_hand_reps, Leap::Frame frame) {
    for (int i = 0; i < frame.hands().count(); i++) {
        auto curHand = frame.hands()[i];

        auto it = all_hand_reps.find(curHand.id());
        if (it != all_hand_reps.end()) {
            HandRepresentation rep = pool.MakeHandRepresentation(curHand);
            all_hand_reps.insert(std::pair(curHand.id(), rep));
            rep.IsMarked = true;
            rep.UpdateRepresentation(curHand);
            rep.LastUpdatedTime = (int) frame.timestamp();

        }

    }

    /** Mark-and-sweep to finish unused HandRepresentations */
    /* HandRepresentation toBeDeleted = null;
     for (auto it = all_hand_reps.GetEnumerator(); it.MoveNext();) {
         var r = it.Current;
         if (r.Value != null) {
             if (r.Value.IsMarked) {
                 r.Value.IsMarked = false;
             } else {
                 *//** Initialize toBeDeleted with a value to be deleted *//*
                //Debug.Log("Finishing");
                toBeDeleted = r.Value;
            }
        }
    }
    *//**Inform the representation that we will no longer be giving it any hand updates
     * because the corresponding hand has gone away *//*
    if (toBeDeleted != null) {
        all_hand_reps.Remove(toBeDeleted.getHandID());
        toBeDeleted.Finish();
    }*/
}


