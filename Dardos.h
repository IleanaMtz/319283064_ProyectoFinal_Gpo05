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

void dardos(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosDardos, Texture &tierra, std::vector<Mesh*> meshList);
void renderStand4(glm::mat4 model, GLuint uniformModel, Model stand, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista);