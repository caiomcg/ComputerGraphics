//
// Created by caiomcg on 10/04/17.
//

#ifndef PIPELINE_H
#define PIPELINE_H

#include <memory>
#include "../Matrix/Matrix.h"

#include "../Matrix/Scale.h"
#include "../Matrix/Rotation.h"
#include "../Matrix/Translation.h"

class Pipeline {
private:
    Pipeline();

    Matrix* model;
    Matrix* view;
    Matrix* projection;
    Matrix* viewPort;


public:
    static Pipeline& getInstance();

    void init(const double pos[3], const double look[3], const double up[3]);

    void release();
};

#endif //PIPELINE_H