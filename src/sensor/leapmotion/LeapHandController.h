//
// Created by David Komorowicz on 2018. 04. 07..
//

#ifndef HANDVR_LEAPDATA_H
#define HANDVR_LEAPDATA_H

#include <Leap.h>
#include <map>
#include "LeapProvider.h"
#include "HandRepresentation.h"
#include "HandPool.h"

// Hand Controller
class LeapHandController {
public:
    LeapHandController(std::shared_ptr<LeapProvider>);

    ~LeapHandController();


    std::vector<std::shared_ptr<HandRepresentation>> getHandRepresentation() const;
protected:
    virtual void OnUpdateFrame(const Leap::Frame &);

    std::shared_ptr<LeapProvider> provider;

    /**
   * Updates HandRepresentations based in the specified HandRepresentation Dictionary.
   * Active HandRepresentation instances are updated if the hand they represent is still
   * present in the Provider's CurrentFrame; otherwise, the HandRepresentation is removed. If new
   * Leap Hand objects are present in the Leap HandRepresentation Dictionary, new HandRepresentations are
   * created and added to the dictionary.
   * @param all_hand_reps = A dictionary of Leap Hand ID's with a paired HandRepresentation
   * @param frame The Leap Frame containing Leap Hand data for each currently tracked hand
   */
    void updateHandRepresentations(std::map<int, std::shared_ptr<HandRepresentation>>&, const Leap::Frame&);

    std::map<int, std::shared_ptr<HandRepresentation>> graphicsHandReps;
    HandPool pool;


};


#endif //HANDVR_LEAPDATA_H
