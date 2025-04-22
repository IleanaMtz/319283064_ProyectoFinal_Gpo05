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

void bolos(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosBolos, Texture &tierra, std::vector<Mesh*> meshList);
void renderStand5(glm::mat4 model, GLuint uniformModel, Model stand, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista);


void renderPines(glm::mat4 model, GLuint uniformModel, Model& pines, glm::vec3 posInicial);
void renderBola(glm::mat4 model, GLuint uniformModel, Model& bola, glm::vec3 posInicial);
void renderMesa(glm::mat4 model, GLuint uniformModel, Model& mesa, glm::vec3 position);
void renderCartelBoliche(glm::mat4 model, GLuint uniformModel, Model& cartel, glm::vec3 position);
void renderEstante(glm::mat4 model, GLuint uniformModel, Model& estante, glm::vec3 position, GLfloat rotacion);
