//
// Created by caiomcg on 10/04/17.
//

#include "Pipeline.h"


Pipeline::Pipeline() {
    model      = new Matrix(4,4);
    view       = new Matrix(4,4);
    projection = new Matrix(4,4);
    viewPort   = new Matrix(4,4);
}

Pipeline* Pipeline::getInstance() {
    if (instance == nullptr) {
        instance = new Pipeline();
    }
    return instance;
}

void Pipeline::init(const double pos[3], const double look[3], const double up[3]) {
    std::vector<std::vector<double> > matrix = view->getMatrix();
    //Zc = - d/|d|;
    //Xc =   Uc x Zc / |Uc x Zc|;
    //Yc =   Zc x Xc /|Zc x Xc|;
}

void Pipeline::release() {
    if (model != nullptr) {
        delete model;
        model = nullptr;
    }
    if (view != nullptr) {
        delete view;
        view = nullptr;
    }
    if (projection != nullptr) {
        delete projection;
        projection = nullptr;
    }
    if (viewPort != nullptr){
        delete viewPort;
        viewPort = nullptr;
    }

    delete instance;
    instance = nullptr;
}