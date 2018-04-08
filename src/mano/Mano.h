//
// Created by David Komorowicz on 2018. 04. 01..
//

#ifndef HANDVR_MANO_H
#define HANDVR_MANO_H

#include <array>

class Mano {
public:
    static const int n_betas = 10;
    static const int n_joints = 15;

//    const float *getThetas() const;

//    const float *getBetas() const;


protected:
    std::array<float, 3 * n_joints> thetas;
    std::array<float, n_betas> betas;

};


#endif //HANDVR_MANO_H
