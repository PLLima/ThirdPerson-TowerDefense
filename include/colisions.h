#ifndef COLISIONS_H
#define COLISIONS_H

#include <vector>
#include <map>

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

extern const glm::vec4 floor_plane;
extern const glm::vec4 wall_0_plane;
extern const glm::vec4 wall_1_plane;
extern const glm::vec4 wall_2_plane;
extern const glm::vec4 wall_3_plane;

extern const glm::vec3 tank_bbox_min;
extern const glm::vec3 tank_bbox_max;
extern const glm::vec3 ballon_red_bbox_min;
extern const glm::vec3 ballon_red_bbox_max;
extern const glm::vec3 birthday_ballon_bbox_min;
extern const glm::vec3 birthday_ballon_bbox_max;
extern const glm::vec3 heart_ballon_bbox_min;
extern const glm::vec3 heart_ballon_bbox_max;
extern const glm::vec3 tower_bbox_min;
extern const glm::vec3 tower_bbox_max;

extern std::map<int, std::vector<int>> tank_bbox_regions;

std::vector<glm::vec3> compute_model_bbox(const glm::vec3 &model_bbox_min, const glm::vec3 &model_bbox_max);
std::vector<glm::vec3> compute_world_bbox(const glm::mat4 &model, const std::vector<glm::vec3> model_corners);
bool bbox_intercepts_plane(const std::vector<glm::vec3> world_corners, const glm::vec4 plane);
bool bbox_intercepts_bbox(const std::vector<glm::vec3>& bbox1, const std::vector<glm::vec3>& bbox2);

#endif