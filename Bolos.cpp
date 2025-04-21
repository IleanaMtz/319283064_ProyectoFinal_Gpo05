#include "Bolos.h"

void bolos(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosBolos, Texture &tierra, std::vector<Mesh*> meshList) {
	GLfloat alturaPin = 0.1f;
	GLfloat alturaBola = 1.2f;

	renderStand5(model, uniformModel, objetosBolos[0], glm::vec3(-80.0f, -1.0f, 140.0f), tierra, meshList);
	
	renderPines(model, uniformModel, objetosBolos[1], glm::vec3(-69.0f, alturaPin,180.0f));
	renderPines(model, uniformModel, objetosBolos[1], glm::vec3(-79.0f, alturaPin,180.0f));
	renderPines(model, uniformModel, objetosBolos[1], glm::vec3(-89.0f, alturaPin,180.0f));
	
	renderBola(model, uniformModel, objetosBolos[2], glm::vec3(-69.0f, alturaBola , 150.0f));
	renderBola(model, uniformModel, objetosBolos[2], glm::vec3(-79.0f, alturaBola, 150.0f));
	renderBola(model, uniformModel, objetosBolos[2], glm::vec3(-89.0f, alturaBola, 150.0f));

	renderCartelBoliche(model, uniformModel, objetosBolos[3], glm::vec3(-69.0f, 8.0f, 189.0f));

	renderEstante(model, uniformModel, objetosBolos[4], glm::vec3(-100.0f, 6.0f, 120.0f),90.0f);
	renderEstante(model, uniformModel, objetosBolos[4], glm::vec3(-58.0f, 6.0f, 120.0f),270.0f);
}


void renderStand5(glm::mat4 model, GLuint uniformModel, Model stand, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista) {
	glm::mat4 modelaux(1.0);
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	modelaux = model;
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 130.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	modelaux = glm::translate(modelaux, glm::vec3(0.0f, -0.42f, 0.0f));
	modelaux = glm::rotate(modelaux, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	modelaux = glm::scale(modelaux, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelaux));
	stand.RenderModel();
}

void renderPines(glm::mat4 model, GLuint uniformModel, Model& pin, glm::vec3 posInicial) {

	//1
	model = glm::mat4(1.0);
	model = glm::translate(model, posInicial);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//2,1
	model = glm::translate(model, glm::vec3(0.5f,0.0f,1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//2,2
	
	model = glm::translate(model, glm::vec3(-1.0f,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//3,1
	model = glm::translate(model, glm::vec3(-0.5, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//3,2
	model = glm::translate(model, glm::vec3(1.0,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//3,3
	model = glm::translate(model, glm::vec3(1.0, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,1
	model = glm::translate(model, glm::vec3(0.5f ,0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,2
	model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,3
	model = glm::translate(model, glm::vec3(-1.0f,0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,4
	model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();
}


void renderBola(glm::mat4 model, GLuint uniformModel, Model& bola,glm::vec3 posInicial) {
	model = glm::mat4(1.0);
	model = glm::translate(model,posInicial);
	model = glm::scale(model, glm::vec3(9.5f, 9.5f, 9.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bola.RenderModel();

}

void renderMesa(glm::mat4 model, GLuint uniformModel, Model& table, glm::vec3 position) {
	model = glm::mat4(1.0);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(25.5f, 25.5f, 50.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	table.RenderModel();
}

void renderCartelBoliche(glm::mat4 model, GLuint uniformModel, Model& cartel, glm::vec3 position) {
	model = glm::mat4(1.0);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cartel.RenderModel();
}

void renderEstante(glm::mat4 model, GLuint uniformModel, Model& estante, glm::vec3 position,GLfloat rotacion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(12.5f, 12.0f, 12.0f));
	model = glm::rotate(model, glm::radians(rotacion), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	estante.RenderModel();
}
