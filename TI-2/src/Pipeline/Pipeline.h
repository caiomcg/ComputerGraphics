//
// Created by caiomcg on 10/04/17.
//

#ifndef PIPELINE_H
#define PIPELINE_H

#include <exception>
#include <string>
#include "glm/gtx/string_cast.hpp"
#include <iostream>
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/norm.hpp"
#include "../Obj/objLoader.h"

#include "mygl.h"

class Pipeline {
private:
    objLoader* loader;
    glm::mat4 matrixModel;
    glm::vec3 offset;
    Pipeline();

    glm::mat4 createMatrixView(const float zDistance);
    glm::mat4 createMatrixProjection(const float viewPlaneDistance);
    glm::mat4 createMatrixScreen(const int width, const int height);
public:
    static Pipeline& getInstance();

    void setObjData(const std::string path);

    void setRotation(float angle, float x, float y, float z);

    void setTranslation(float x, float y, float z);

    void setScale(float x, float y, float z);

    void init(const float zDistance, const float viewPlaneDistance, const int width, const int height);

    void show(glm::mat4 model, glm::mat4 view, glm::mat4 projection, glm::mat4 screen);

    void clean();

    void release();
};

#endif //PIPELINE_H