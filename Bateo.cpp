#include "Bateo.h"

void bateo(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosBateo, Texture &tierra, std::vector<Mesh*> meshList) {

	renderStand2(model, uniformModel, objetosBateo[0], glm::vec3(-80.0f, -1.0f, -140.0f), tierra, meshList);
}

void renderStand2(glm::mat4 model, GLuint uniformModel, Model stand, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista) {
	glm::mat4 modelaux(1.0);
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	modelaux = model;
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 130.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	modelaux = glm::translate(modelaux, glm::vec3(0.0f, -0.42f, 0.0f));
	modelaux = glm::scale(modelaux, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelaux));
	stand.RenderModel();
}