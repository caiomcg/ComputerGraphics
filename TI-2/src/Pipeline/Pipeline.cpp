//
// Created by caiomcg on 10/04/17.
//

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
    B[0] = glm::vec4(Xc, 1.0f);
    B[1] = glm::vec4(Yc, 1.0f);
    B[2] = glm::vec4(Zc, 1.0f);

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

glm::mat4 Pipeline::createMatrixScreen(const int width, const int height) {
    glm::mat4 inverse = glm::mat4(1.0f);
    inverse[1].y = -1;

    glm::mat4 transition = glm::mat4(1.0f);
    transition[3] = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);

    glm::mat4 scale = glm::mat4(1.0f);
    scale[0].x = (width-1) * 0.5f;
    scale[1].y = (height-1) * 0.5f;

    return scale * transition * inverse;
}

void Pipeline::setObjData(const std::string path) {
    loader = new objLoader();
    loader->load((char *) path.c_str());
}

void Pipeline::addRotation(float angle, int x, int y, int z){

    glm::mat4 rot_mat;

    float sin_angle = sin(angle * M_PI / 180.0f);
    float cos_angle = cos(angle * M_PI / 180.0f);

    if(x){
        rot_mat[1].y = cos_angle;
        rot_mat[1].z = sin_angle;
        rot_mat[2].y = -sin_angle;
        rot_mat[2].z = cos_angle;
    }
    else if(y){
        rot_mat[0].x = cos_angle;
        rot_mat[0].z = -sin_angle;
        rot_mat[2].x = sin_angle;
        rot_mat[2].z = cos_angle;
    }
    else if(z){
        rot_mat[0].x = cos_angle;
        rot_mat[0].y = sin_angle;
        rot_mat[1].x = -sin_angle;
        rot_mat[1].y = cos_angle;
    }

    matrixModel = rot_mat * matrixModel;

}

// Adiciona (multiplica) uma matriz de translação à matriz model
void Pipeline::addTransl(float x, float y, float z){

    glm::mat4 trans_mat;
    trans_mat[3] = glm::vec4(glm::vec3(x, y, z), 1.0f);
    matrixModel = trans_mat * matrixModel;
}

// Aplica uma escala à matriz model
void Pipeline::addScale(float x, float y, float z){

    glm::mat4 scale_mat;

    scale_mat[0].x = x;
    scale_mat[1].y = y;
    scale_mat[2].z = z;

    matrixModel = scale_mat * matrixModel;
}


void Pipeline::init(const float zDistance, const float viewPlaneDistance, const int width, const int height) {
    glm::mat4 matrixView       = createMatrixView(zDistance);
    glm::mat4 matrixProjection = createMatrixProjection(viewPlaneDistance);
    glm::mat4 matrixScreen     = createMatrixScreen(width, height);




    this->show(matrixModel, matrixView, matrixProjection, matrixScreen);
}

void Pipeline::show(glm::mat4 model, glm::mat4 view, glm::mat4 projection, glm::mat4 screen) {
    glm::mat4 matrixModelViewProjection = projection * view * model;

    for (int i = 0; i < loader->faceCount; i++) {
        obj_face* face = loader->faceList[i];


        glm::vec4 pnt1 = glm::vec4(loader->vertexList[face->vertex_index[0]]->e[0],loader->vertexList[face->vertex_index[0]]->e[1],loader->vertexList[face->vertex_index[0]]->e[2], 1.0f);
        glm::vec4 pnt2 = glm::vec4(loader->vertexList[face->vertex_index[1]]->e[0],loader->vertexList[face->vertex_index[1]]->e[1],loader->vertexList[face->vertex_index[1]]->e[2], 1.0f);
        glm::vec4 pnt3 = glm::vec4(loader->vertexList[face->vertex_index[2]]->e[0],loader->vertexList[face->vertex_index[2]]->e[1],loader->vertexList[face->vertex_index[2]]->e[2], 1.0f);

        drawTriangle(Pixel(pnt1.x, pnt1.y), Pixel(pnt2.x, pnt2.y), Pixel(pnt3.x, pnt3.y));
    }

    std::cout << glm::to_string(projection) << std::endl;

    matrixModel = glm::mat4();
}

void Pipeline::release() {
    if (loader != nullptr) {
        delete loader;
    }
}