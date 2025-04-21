#include "Comida.h"

void comida(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosComida, Texture& tierra, std::vector<Mesh*> meshList) {
	renderStandsComida(model, uniformModel, objetosComida, glm::vec3(-80.0f, -1.0f, -140.0f), tierra, meshList);
}

void renderStandsComida(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosComida, glm::vec3 posicion, Texture& tierra, std::vector<Mesh*> lista){
	glm::mat4 modelaux(1.0);

	//Área de comida
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-210.0f, -1.0f, 0.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 220.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();
	//Comida1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-210.0f, -1.0f, 0.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 220.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosComida[0].RenderModel();
	//Comida2
	model = modelaux;
	model = glm::translate(model, glm::vec3(-210.0f, -1.0f, 0.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 220.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosComida[1].RenderModel();
	//Comida3
	model = modelaux;
	model = glm::translate(model, glm::vec3(-210.0f, -1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 220.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosComida[2].RenderModel();
}