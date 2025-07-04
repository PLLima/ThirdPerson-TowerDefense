#include <math.h>
#include <glm/vec4.hpp>

// Função utilizada para gerar um ponto de uma curva cúbica de Bezier a partir de quatro pontos de controle e um parâmetro t em [0,1].:
//
//     c(t) = (1-t)^3*p1 + 3t(1-t)^2*p2 + 3t^2(1-t)*p3 + t^3*p4.
//
glm::vec4 bezier(float t, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3, glm::vec4 p4)
{
    float b03 = pow(1-t, 3);
    float b13 = 3*t*pow(1-t, 2);
    float b23 = 3*t*t*(1-t);
    float b33 = pow(t, 3);

    return b03*p1 + b13*p2 + b23*p3 + b33*p4;
}