#include "Bateo.h"

void bateo(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosBateo, Texture &tierra, std::vector<Mesh*> meshList) {
	renderStand2(model, uniformModel, objetosBateo[0], glm::vec3(-80.0f, -1.0f, -140.0f), tierra, meshList);
	renderBardas(model, uniformModel, objetosBateo[1], glm::vec3(-100.0f, 2.0f, -130.0f));
	renderObjetivoBateo(model, uniformModel, objetosBateo[2], glm::vec3(-90.0f, -1.0f, -175.0f));

	renderCartelBateo(model, uniformModel, objetosBateo[3], glm::vec3(-93.0f, 8.0f, -188.0f));

	renderBats(model, uniformModel, objetosBateo[4], glm::vec3(-90.0f, 0.0f, -125.0f));

}

void renderStand2(glm::mat4 model, GLuint uniformModel, Model stand, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista) {
	//Caminos
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(180.0f, -1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(20.0f, 0.05f, 150.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(225.0f, -1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(70.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(115.0f, -1.0f, -140.0f));
	model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(115.0f, -1.0f, 140.0f));
	model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-15.0f, -1.0f, -140.0f));
	model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-15.0f, -1.0f, 140.0f));
	model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-170.0f, -1.0f, -140.0f));
	model = glm::scale(model, glm::vec3(100.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-170.0f, -1.0f, 140.0f));
	model = glm::scale(model, glm::vec3(100.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-210.0f, -1.0f, -120.0f));
	model = glm::scale(model, glm::vec3(20.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-210.0f, -1.0f, 120.0f));
	model = glm::scale(model, glm::vec3(20.0f, 0.05f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();


	//Stand bateo
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
void renderBardas(glm::mat4 model, GLuint uniformModel, Model bardaBateo, glm::vec3 posInicial) {
	model = glm::mat4(1.0);
	model = glm::translate(model,posInicial);
	model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bardaBateo.RenderModel();

	model = glm::translate(model,glm::vec3(27.0f,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bardaBateo.RenderModel();

	model = glm::translate(model, glm::vec3(27.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bardaBateo.RenderModel();
}

void renderObjetivoBateo(glm::mat4 model, GLuint uniformModel, Model objetivo, glm::vec3 posicion){
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(3.8f, 3.8f, 3.8f));
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();

	model = glm::translate(model, glm::vec3(-5.0f,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();
}

void renderCartelBateo(glm::mat4 model, GLuint uniformModel, Model& cartelBateo, glm::vec3 position) {
	model = glm::mat4(1.0);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	model = glm::rotate(model, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cartelBateo.RenderModel();
}

void renderBats(glm::mat4 model, GLuint uniformModel, Model& bats, glm::vec3 position){
	model = glm::mat4(1.0);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	//model = glm::rotate(model, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bats.RenderModel();

	model = glm::translate(model, glm::vec3(3.0f,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bats.RenderModel();
}
