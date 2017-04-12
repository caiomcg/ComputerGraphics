//
// Created by caiomcg on 10/04/17.
//

#include "Pipeline.h"

Pipeline::Pipeline() {}

Pipeline& Pipeline::getInstance() {
    static Pipeline instance;
    return instance;
}

void Pipeline::init() {
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f/3.0f, 0.1f, 100.0f);
    glm::mat4 view       = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2));
}

void Pipeline::release() {

}