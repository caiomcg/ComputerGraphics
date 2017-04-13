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
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "../Obj/objLoader.h"

#include "mygl.h"

class Pipeline {
private:
    objLoader* loader;
    glm::mat4 matrixModel;
    Pipeline();

    glm::mat4 createMatrixView(const float zDistance);
    glm::mat4 createMatrixProjection(const float viewPlaneDistance);
    void show(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
    void toScreenSpace(glm::mat4& modelViewProjection, glm::vec4& firstVertex, glm::vec4& secondVertex, glm::vec4& thirdVertex);
public:
    static Pipeline& getInstance();

    void setObjData(const std::string path);

    void setRotation(float angle, float x, float y, float z);

    void setTranslation(float x, float y, float z);

    void setScale(float x, float y, float z);

    void init(const float zDistance, const float viewPlaneDistance);



    void clean();

    void release();
};

#endif //PIPELINE_H