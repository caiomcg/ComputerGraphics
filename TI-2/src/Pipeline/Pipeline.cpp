//
// Created by caiomcg on 10/04/17.
//

#include <cstring>
#include "Pipeline.h"

Pipeline::Pipeline() {
    matrixModel = glm::mat4(1.0f);
}

Pipeline& Pipeline::getInstance() {
    static Pipeline instance;
    return instance;
}

glm::mat4 Pipeline::createMatrixView(const float zDistance) {
    glm::vec3 cameraPosition(0.0f, 0.0f, zDistance);
    glm::vec3 viewDirection(0.0f, 0.0f, 0.0f);
    glm::vec3 upVector(0.0f, 1.0f, 0.0f);

    glm::vec3 Zc = glm::normalize(cameraPosition - viewDirection);
    glm::vec3 Xc = glm::normalize(glm::cross(upVector, Zc));
    glm::vec3 Yc = glm::normalize(glm::cross(Zc, Xc));

    glm::mat4 B = glm::mat4(1.0f);
    B[0] = glm::vec4(Xc, 0.0f);
    B[1] = glm::vec4(Yc, 0.0f);
    B[2] = glm::vec4(Zc, 0.0f);

    glm::mat4 T = glm::mat4(1.0f);
    T[3] = glm::vec4(-cameraPosition, 1.0f);

    return glm::transpose(B) * T;
}

glm::mat4 Pipeline::createMatrixProjection(const float viewPlaneDistance) {
    glm::mat4 matrixProjection = glm::mat4(1.0f);
    matrixProjection[2].w = -1 / viewPlaneDistance;
    matrixProjection[3].z = viewPlaneDistance;
    return matrixProjection;
}

void Pipeline::setObjData(const std::string path) {
    loader = new objLoader();
    loader->load((char *) path.c_str());
}

void Pipeline::setRotation(float angle, float x, float y, float z) {
    matrixModel = glm::rotate(matrixModel, angle, glm::vec3(x, y, z));
}

void Pipeline::setTranslation(float x, float y, float z) {
    matrixModel =  glm::translate(matrixModel, glm::vec3(x, y, z));
}

void Pipeline::setScale(float x, float y, float z) {
    matrixModel = glm::scale(matrixModel,glm::vec3(x, y, z));
}

void Pipeline::toScreenSpace(glm::mat4& modelViewProjection, glm::vec4& firstVertex, glm::vec4& secondVertex, glm::vec4& thirdVertex) {
    glm::mat4 invert;
    invert[1].y = -1;

    glm::mat4 translate(1.0f);
    translate[3] = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);

    glm::mat4 scale(1.0f);
    scale[0].x = (IMAGE_WIDTH-1) * 0.5f;
    scale[1].y = (IMAGE_HEIGHT-1) * 0.5f;

    glm::mat4 screenMatrix = scale * translate * invert;

    firstVertex = modelViewProjection * firstVertex;
    secondVertex = modelViewProjection * secondVertex;
    thirdVertex = modelViewProjection * thirdVertex;

    firstVertex = screenMatrix * firstVertex / firstVertex.w;
    secondVertex = screenMatrix * secondVertex / secondVertex.w;
    thirdVertex = screenMatrix * thirdVertex / thirdVertex.w;
}

void Pipeline::init(const float zDistance, const float viewPlaneDistance) {
    glm::mat4 matrixView       = createMatrixView(zDistance);
    glm::mat4 matrixProjection = createMatrixProjection(viewPlaneDistance);

    this->show(matrixModel, matrixView, matrixProjection);
}

void Pipeline::show(glm::mat4 model, glm::mat4 view, glm::mat4 projection) {
    glm::mat4 matrixModelViewProjection = projection * view * model;

    for (int i = 0; i < loader->faceCount; i++) {
        obj_face* face = loader->faceList[i];

        glm::vec4 firstVertex(loader->vertexList[face->vertex_index[0]]->e[0],
                  loader->vertexList[face->vertex_index[0]]->e[1],
                  loader->vertexList[face->vertex_index[0]]->e[2],
                  1.0f);
        glm::vec4 secondVertex(loader->vertexList[face->vertex_index[1]]->e[0],
                  loader->vertexList[face->vertex_index[1]]->e[1],
                  loader->vertexList[face->vertex_index[1]]->e[2],
                  1.0f);
        glm::vec4 thirdVertex(loader->vertexList[face->vertex_index[2]]->e[0],
                  loader->vertexList[face->vertex_index[2]]->e[1],
                  loader->vertexList[face->vertex_index[2]]->e[2],
                  1.0f);

        this->toScreenSpace(matrixModelViewProjection, firstVertex, secondVertex, thirdVertex);

        DrawTriangle(Vertex(firstVertex.x, firstVertex.y), Vertex(secondVertex.x, secondVertex.y), Vertex(thirdVertex.x, thirdVertex.y));
    }

    matrixModel = glm::mat4(1.0f);
}

void Pipeline::clean() {
    memset(FBptr, 0, IMAGE_WIDTH * IMAGE_HEIGHT * 4);
}