//
// Created by caiomcg on 10/04/17.
//

#include "Pipeline.h"

Pipeline::Pipeline() {

}

Pipeline& Pipeline::getInstance() {
    static Pipeline instance;
    return instance;
}

void Pipeline::init() {
}

void Pipeline::release() {

}