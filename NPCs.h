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

void NPCs(glm::mat4 model, GLuint uniformModel, std::vector<Model> personajesNPCs);

//Personajes de Snoopy
void renderWoodstock(glm::mat4 model, GLuint uniformModel, Model woodstock, glm::vec3 posicion);
void renderPeppermint(glm::mat4 model, GLuint uniformModel, Model peppermint, glm::vec3 posicion);
void renderCharlie(glm::mat4 model, GLuint uniformModel, Model charlie, glm::vec3 posicion);

//Personajes de Gumball
void renderCarrie(glm::mat4 model, GLuint uniformModel, Model carrie, glm::vec3 posicion);
void renderTeri(glm::mat4 model, GLuint uniformModel, Model teri, glm::vec3 posicion);

//Personajes de Mario
void renderBowser(glm::mat4 model, GLuint uniformModel, Model bowser, glm::vec3 posicion);
void renderKingBoo(glm::mat4 model, GLuint uniformModel, Model kingBoo, glm::vec3 posicion);
void renderDonkeyKong(glm::mat4 model, GLuint uniformModel, Model donkeyKong, glm::vec3 posicion);
void renderWario(glm::mat4 model, GLuint uniformModel, Model wario, glm::vec3 posicion);