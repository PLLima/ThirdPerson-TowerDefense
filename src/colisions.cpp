// Headers locais, definidos na pasta "include/"
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

// gera os 8 vertices da bounding box em coordenadas do modelo,
// a partir dos mínimos e máximos da bounding box do modelo
std::vector<glm::vec3> Compute_Model_BBox(const glm::vec3 &model_bbox_min, const glm::vec3 &model_bbox_max)
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

// gera os 8 vertices da bounding box em coordenadas do mundo,
// a partir da matriz model e dos 8 vertices da bounding box em coordenadas do modelo
std::vector<glm::vec3> Compute_World_BBox(const glm::mat4 &model, const std::vector<glm::vec3> model_corners)
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
// o plano definido por plane e devolve true caso ocorra interceptação
bool BBox_Intercepts_Plane(const std::vector<glm::vec3> world_corners, const glm::vec4 plane)
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

// dado duas bounding boxes em coordenadas do mundo, devolve true caso ocorra colisão
bool BBox_Intercepts_BBox(const std::vector<glm::vec3>& bbox1, const std::vector<glm::vec3>& bbox2)
{
    // limites extremos para bbox1
    float min1_x = std::numeric_limits<float>::max();
    float max1_x = std::numeric_limits<float>::lowest();
    float min1_z = std::numeric_limits<float>::max();
    float max1_z = std::numeric_limits<float>::lowest();

    // limites extremos para bbox2
    float min2_x = std::numeric_limits<float>::max();
    float max2_x = std::numeric_limits<float>::lowest();
    float min2_z = std::numeric_limits<float>::max();
    float max2_z = std::numeric_limits<float>::lowest();    

    // min/max em XZ para bbox1
    for (const glm::vec3 v : bbox1) {
        min1_x = std::min(min1_x, v.x);
        max1_x = std::max(max1_x, v.x);
        min1_z = std::min(min1_z, v.z);
        max1_z = std::max(max1_z, v.z);
    }

    // min/max em XZ para bbox2
    for (const glm::vec3 v : bbox2) {
        min2_x = std::min(min2_x, v.x);
        max2_x = std::max(max2_x, v.x);
        min2_z = std::min(min2_z, v.z);
        max2_z = std::max(max2_z, v.z);
    }

    // verifica sobreposição nos eixos X e Z
    bool x_overlap = (max1_x >= min2_x) && (min1_x <= max2_x);
    bool z_overlap = (max1_z >= min2_z) && (min1_z <= max2_z);

    return x_overlap && z_overlap;
}
