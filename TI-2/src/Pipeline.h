//
// Created by caiomcg on 10/04/17.
//

#ifndef PIPELINE_H
#define PIPELINE_H

#include <memory>
#include "Matrix.h"

#include "Scale.h"
#include "Rotation.h"
#include "Translation.h"

class Pipeline {
private:
    static Pipeline();
    static Pipeline* instance = nullptr;

    Matrix* model = nullptr;
    Matrix* view = nullptr;
    Matrix* projection = nullptr;
    Matrix* viewPort = nullptr;


public:
    static Pipeline* getInstance();

    void init(const double pos[3], const double look[3], const double up[3]);

    static void release();
};

#endif //PIPELINE_H