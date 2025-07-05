// Headers locais, definidos na pasta "include/"
#include "colisions.h"
#include <map>
#include <vector>
#include <set>
#include <algorithm>

// equações dos planos que compõe cenário (cubo)
const glm::vec4 floor_plane = glm::vec4(0.0f, 1.0f, 0.0f, 4900.f); // face_0
const glm::vec4 wall_0_plane = glm::vec4(1.0f, 0.0f, 0.0f, -4000.f); // face_2
const glm::vec4 wall_1_plane = glm::vec4(1.0f, 0.0f, 0.0f, -16000.f); // face_3
const glm::vec4 wall_2_plane = glm::vec4(0.0f, 0.0f, 1.0f, -9000.f); // face_4
const glm::vec4 wall_3_plane = glm::vec4(0.0f, 0.0f, 1.0f, 3000.f); // face_5

// vértices máximos e mínimos coletados do .obj do tanque
const glm::vec3 tank_bbox_min = glm::vec3(-0.447274f, -0.552903f, -1.25f);
const glm::vec3 tank_bbox_max = glm::vec3(0.447274f, 0.552190f, 1.25f);

// gera os 8 vertices da bounding box em coordenadas do modelo
std::vector<glm::vec3> compute_model_bbox(const glm::vec3 &model_bbox_min, const glm::vec3 &model_bbox_max)
{
    std::vector<glm::vec3> model_corners(8);

    model_corners[0] = glm::vec3(model_bbox_min.x, model_bbox_min.y, model_bbox_min.z);
    model_corners[1] = glm::vec3(model_bbox_max.x, model_bbox_min.y, model_bbox_min.z);
    model_corners[2] = glm::vec3(model_bbox_min.x, model_bbox_max.y, model_bbox_min.z);
    model_corners[3] = glm::vec3(model_bbox_max.x, model_bbox_max.y, model_bbox_min.z);
    model_corners[4] = glm::vec3(model_bbox_min.x, model_bbox_min.y, model_bbox_max.z);
    model_corners[5] = glm::vec3(model_bbox_max.x, model_bbox_min.y, model_bbox_max.z);
    model_corners[6] = glm::vec3(model_bbox_min.x, model_bbox_max.y, model_bbox_max.z);
    model_corners[7] = glm::vec3(model_bbox_max.x, model_bbox_max.y, model_bbox_max.z);

    return model_corners;
}

// mapeamos as 8 coordenadas da bbox para o sistema de coordenadas do mundo
std::vector<glm::vec3> compute_world_bbox(const glm::mat4 &model, const std::vector<glm::vec3> model_corners)
{
    std::vector<glm::vec3> world_corners(8);

    for (int i = 0; i < 8; i++)
        world_corners[i] = glm::vec3(model * glm::vec4(
            model_corners[i].x,
            model_corners[i].y,
            model_corners[i].z,
            1.0f));

    return world_corners;
}

// verifica se bbox definida pelos 8 vértices de world_corners intersecta
// o plano definido por plane e devolve um par contendo um bool e os vertices
// cruzados, casos existam
bool intercepts_plane(const std::vector<glm::vec3> world_corners, const glm::vec4 plane)
{
    int num_front_vertices = 0;
    int num_back_vertices = 0;

    for (int i = 0; i < 8; i++)
    {
        // define a normal n do plano
        glm::vec4 plane_n = glm::vec4(plane.x, plane.y, plane.z, 0.0f);
        // define o vetor posição p do ponto
        glm::vec4 point_p = glm::vec4(world_corners[i].x, world_corners[i].y, world_corners[i].z, 0.0f);

        // calcula distancia di entre o ponto da bbox e o plano,
        // conforme a eq. di = (n⋅p) ​​+ d
        float d = glm::dot(plane_n, point_p) + plane.w;

        if (d > 0.0f) 
            num_front_vertices++;
        else if (d < 0.0f) 
            num_back_vertices++;

        if (num_front_vertices > 0 && num_back_vertices > 0)
            return true;
    }

    return false;
}


