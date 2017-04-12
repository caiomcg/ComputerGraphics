//
// Created by caiomcg on 10/04/17.
//

#ifndef PIPELINE_H
#define PIPELINE_H

#include "../../third_party/glm-0.9.7.4/glm/vec3.hpp"
#include "../../third_party/glm-0.9.7.4/glm/mat4x4.hpp"
#include "../../third_party/glm-0.9.7.4/glm/gtc/matrix_transform.hpp"

class Pipeline {
private:
    glm::mat4 result;
    Pipeline();

public:
    static Pipeline& getInstance();

    void init();

    void release();
};

#endif //PIPELINE_H