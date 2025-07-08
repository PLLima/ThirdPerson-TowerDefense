#version 330 core

// Atributos de fragmentos recebidos como entrada ("in") pelo Fragment Shader.
// Neste exemplo, este atributo foi gerado pelo rasterizador como a
// interpolação da posição global e a normal de cada vértice, definidas em
// "shader_vertex.glsl" e "main.cpp".
in vec4 position_world;
in vec4 normal;
in vec4 color_v;

// Posição do vértice atual no sistema de coordenadas local do modelo.
in vec4 position_model;

// Coordenadas de textura obtidas do arquivo OBJ (se existirem!)
in vec2 texcoords;

// Matrizes computadas no código C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Identificador que define qual objeto está sendo desenhado no momento
#define FACE_0 0 // base
#define FACE_1 1 // topo
#define FACE_2 2
#define FACE_3 3
#define FACE_4 4
#define FACE_5 5
#define ROAD   6

#define TANK_0 7
#define TANK_1 8
#define TANK_2 9

#define DARTLING_TOWER 10

#define BALLON_RED 11
#define BALLON_BIRTHDAY 12
#define BALLON_HEART 13

#define SPHERE 14

uniform int object_id;

// Parâmetros da axis-aligned bounding box (AABB) do modelo
uniform vec4 bbox_min;
uniform vec4 bbox_max;

// Variáveis para acesso das imagens de textura
uniform sampler2D TextureImage0;
uniform sampler2D TextureImage1;
uniform sampler2D TextureImage2;
uniform sampler2D TextureImage3;
uniform sampler2D TextureImage4;
uniform sampler2D TextureImage5;
uniform sampler2D TextureImage6;
uniform sampler2D TextureImage7;
uniform sampler2D TextureImage8;
uniform sampler2D TextureImage9;
uniform sampler2D TextureImage10;
uniform sampler2D TextureImage11;
uniform sampler2D TextureImage12;
uniform sampler2D TextureImage13;

// O valor de saída ("out") de um Fragment Shader é a cor final do fragmento.
out vec4 color;

// Constantes
#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

void main()
{
    // Obtemos a posição da câmera utilizando a inversa da matriz que define o
    // sistema de coordenadas da câmera.
    vec4 origin = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 camera_position = inverse(view) * origin;

    // O fragmento atual é coberto por um ponto que percente à superfície de um
    // dos objetos virtuais da cena. Este ponto, p, possui uma posição no
    // sistema de coordenadas global (World coordinates). Esta posição é obtida
    // através da interpolação, feita pelo rasterizador, da posição de cada
    // vértice.
    vec4 p = position_world;

    // Normal do fragmento atual, interpolada pelo rasterizador a partir das
    // normais de cada vértice.
    vec4 n = normalize(normal);

    // Vetor que define o sentido da fonte de luz em relação ao ponto atual.
    vec4 l = normalize(vec4(1.0,1.0,1.0,0.0));

    // Vetor que define o sentido da câmera em relação ao ponto atual.
    vec4 v = normalize(camera_position - p);

    // Vetor presente no termo de Blinn-Phong
    vec4 h = normalize(v + l);

    // Coordenadas de textura U e V
    float U = texcoords.x;
    float V = texcoords.y;

    // Implementação de GL_MIRRORED_REPEAT
    float rounded_U = floor(U);
    U = U - rounded_U;
    float rounded_V = floor(V);
    V = V - rounded_V;
    if(int(rounded_U) % 2 == 1) // Se ímpar
        U = 1 - U;
    if(int(rounded_V) % 2 == 1) // Se ímpar
        V = 1 - V;

    // Equações de iluminação
    vec3 Kd = vec3(0.0, 0.0, 0.0);
    vec3 Ka = vec3(0.075, 0.075, 0.075);
    vec3 Ks = vec3(0.0, 0.0, 0.0);
    float q = 1.0;
    float lambert = max(0,dot(n,l));
    float blinn_phong = pow(max(0,dot(n,h)), q);
    switch (object_id) {
        case FACE_0: // Grass
            Kd = texture(TextureImage0, vec2(U,V)).rgb;
            Ks = texture(TextureImage1, vec2(U,V)).rgb;
            q = 60.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case FACE_1: // Grass
            Kd = texture(TextureImage0, vec2(U,V)).rgb;
            Ks = texture(TextureImage1, vec2(U,V)).rgb;
            q = 60.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case FACE_2: // Baloon
            Kd = texture(TextureImage0, vec2(U,V)).rgb;
            Ks = texture(TextureImage1, vec2(U,V)).rgb;
            q = 60.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case FACE_3: // Grass
            Kd = texture(TextureImage0, vec2(U,V)).rgb;
            Ks = texture(TextureImage1, vec2(U,V)).rgb;
            q = 60.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case FACE_4: // Baloon
            Kd = texture(TextureImage0, vec2(U,V)).rgb;
            Ks = texture(TextureImage1, vec2(U,V)).rgb;
            q = 60.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case FACE_5: // Grass
            Kd = texture(TextureImage0, vec2(U,V)).rgb;
            Ks = texture(TextureImage1, vec2(U,V)).rgb;
            q = 60.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case ROAD:
            Kd = texture(TextureImage2, vec2(U,V)).rgb;
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case TANK_0: // Tank Barrel
            Kd = texture(TextureImage3, vec2(U,V)).rgb;
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case TANK_1: // Tank Base
            Kd = texture(TextureImage4, vec2(U,V)).rgb;
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case TANK_2: // Tank Wheels
            Kd = texture(TextureImage5, vec2(U,V)).rgb;
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case DARTLING_TOWER:
            // Aplicar as cores pixel a pixel (Phong shadding)
            color = color_v;
            break;
        case BALLON_RED:
            Kd = texture(TextureImage7, vec2(U,V)).rgb;
            Ks = vec3(1.0, 1.0, 1.0);
            q = 40.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case BALLON_BIRTHDAY:
            Kd = texture(TextureImage8, vec2(U,V)).rgb;
            Ks = vec3(1.0, 1.0, 1.0);
            q = 40.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case BALLON_HEART:
            Kd = texture(TextureImage9, vec2(U,V)).rgb;
            Ks = vec3(0.5, 0.5, 0.5);
            q = 40.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
        case SPHERE:
            Kd = vec3(0.0, 0.0, 0.0);
            Ks = vec3(0.4, 0.4, 0.4);
            q = 64.0;
            blinn_phong = pow(max(0,dot(n,h)), q);
            // Aplicar as cores pixel a pixel (Phong shadding)
            color.rgb = Kd * (lambert + Ka) + Ks * blinn_phong;
            break;
    }

    // NOTE: Se você quiser fazer o rendering de objetos transparentes, é
    // necessário:
    // 1) Habilitar a operação de "blending" de OpenGL logo antes de realizar o
    //    desenho dos objetos transparentes, com os comandos abaixo no código C++:
    //      glEnable(GL_BLEND);
    //      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // 2) Realizar o desenho de todos objetos transparentes *após* ter desenhado
    //    todos os objetos opacos; e
    // 3) Realizar o desenho de objetos transparentes ordenados de acordo com
    //    suas distâncias para a câmera (desenhando primeiro objetos
    //    transparentes que estão mais longe da câmera).
    // Alpha default = 1 = 100% opaco = 0% transparente
    color.a = 1;

    // Cor final com correção gamma, considerando monitor sRGB.
    // Veja https://en.wikipedia.org/w/index.php?title=Gamma_correction&oldid=751281772#Windows.2C_Mac.2C_sRGB_and_TV.2Fvideo_standard_gammas
    color.rgb = pow(color.rgb, vec3(1.0,1.0,1.0)/2.2);
}