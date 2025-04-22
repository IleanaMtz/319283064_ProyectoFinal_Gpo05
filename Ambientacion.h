#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

#include "Mesh.h"
#include "Texture.h"
#include"Model.h"

void ambientacion(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosAmbientacion);
void renderBanca(glm::mat4 model,GLuint uniformModel, Model banca, glm::vec3 posicion, int grados);
void renderLuminaria1(glm::mat4 model, GLuint uniformModel, Model luminaria1, glm::vec3 posicion, int grados);
void renderLuminaria2(glm::mat4 model, GLuint uniformModel, Model luminaria2, glm::vec3 posicion);
void renderLuminaria3(glm::mat4 model, GLuint uniformModel, Model luminaria3, glm::vec3 posicion);
void renderArbol1(glm::mat4 model, GLuint uniformModel, Model arbol1, glm::vec3 posicion);
void renderArbol2(glm::mat4 model, GLuint uniformModel, Model arbol2, glm::vec3 posicion);
void renderArbol3(glm::mat4 model, GLuint uniformModel, Model arbol3, glm::vec3 posicion);
void renderBote1(glm::mat4 model, GLuint uniformModel, Model bote1, glm::vec3 posicion, int grados);
void renderBote2(glm::mat4 model, GLuint uniformModel, Model bote2, glm::vec3 posicion, int grados);


