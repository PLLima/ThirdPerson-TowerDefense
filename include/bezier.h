#include <math.h>
#include <glm/vec4.hpp>

#include "matrices.h"

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

// Função que calcula a posição final de um ponto ao unir duas curvas de Bezier espelhadas. O valor de t deve estar em [0,2].
glm::vec4 bezier_mirrored(float t, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3, glm::vec4 p4)
{
    glm::vec4 p5 = 2.0f*p4 - p3;
    glm::vec4 p6 = p5 + p3 - p2;
    glm::vec4 p7 = p6 + p2 - p1;

    if(t <= 1.0f)
        return bezier(t, p1, p2, p3, p4);
    else
        return bezier(t - 1.0f, p4, p5, p6, p7);
}

// Função que gera uma posição em uma curva de Bezier baseada no tempo decorrido e em uma velocidade. Tempo entre 0 e 2s.
glm::vec4 bezier_position(float t, float speed, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3, glm::vec4 p4)
{
    float position = t * speed;
    return bezier_mirrored(position, p1, p2, p3, p4);
}

// Função que retorna uma matriz de translação para uma posição em uma curva de Bezier baseada no tempo decorrido e em uma velocidade. Tempo entre 0 e 2s.
glm::mat4 Bezier_Translate(float t, float speed, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3, glm::vec4 p4)
{
    glm::vec4 position = bezier_position(t, speed, p1, p2, p3, p4);
    return Matrix_Translate(position.x, position.y, position.z);
}

// Em bezier.h ou similar

// Retorna o vetor de direção (tangente) da curva em um ponto 't' [0, 1]
glm::vec3 get_bezier_tangent(float t, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3, glm::vec4 p4) {
    float one_minus_t = 1.0f - t;
    glm::vec3 tangent = 3.0f * one_minus_t * one_minus_t * glm::vec3(p2 - p1) +
                        6.0f * one_minus_t * t * glm::vec3(p3 - p2) +
                        3.0f * t * t * glm::vec3(p4 - p3);
    // Retorna o vetor normalizado para termos apenas a direção
    return glm::normalize(tangent);
}