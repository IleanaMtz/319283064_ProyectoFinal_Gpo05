#include "NPCs.h"

const float toRadians = 3.14159265f / 180.0f;

void NPCs(glm::mat4 model, GLuint uniformModel, std::vector<Model> personajesNPCs) {
	//Cambiar las ubicaciones y si es necesario añadir rotaciones como en el archivo de Ambientacion.cpp
	//renderWoodstock(model, uniformModel, personajesNPCs[0], glm::vec3(0.0f, -1.0f, 0.0f)); //Visitante
	renderPeppermint(model, uniformModel, personajesNPCs[1], glm::vec3(-65.0f, -1.0f, -90.0f));
	renderCharlie(model, uniformModel, personajesNPCs[2], glm::vec3(195.0f, -1.0f, -90.0f));
	//renderCarrie(model, uniformModel, personajesNPCs[3], glm::vec3(0.0f, -1.0f, 0.0f));
	//renderTeri(model, uniformModel, personajesNPCs[4], glm::vec3(0.0f, -1.0f, 0.0f));
	////renderBowser(model, uniformModel, personajesNPCs[5], glm::vec3(0.0f, -1.0f, 0.0f)); //Visitante
	////renderKingBoo(model, uniformModel, personajesNPCs[6], glm::vec3(0.0f, -1.0f, 0.0f)); //Visitante
	//renderDonkeyKong(model, uniformModel, personajesNPCs[7], glm::vec3(0.0f, -1.0f, 0.0f));
	//renderWario(model, uniformModel, personajesNPCs[8], glm::vec3(0.0f, -1.0f, 0.0f));
}

void renderWoodstock(glm::mat4 model, GLuint uniformModel, Model woodstock, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(50.0f, 50.0f, 50.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	woodstock.RenderModel();
}

void renderPeppermint(glm::mat4 model, GLuint uniformModel, Model peppermint, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	peppermint.RenderModel();
}

void renderCharlie(glm::mat4 model, GLuint uniformModel, Model charlie, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	charlie.RenderModel();
}

void renderCarrie(glm::mat4 model, GLuint uniformModel, Model carrie, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	carrie.RenderModel();
}

void renderTeri(glm::mat4 model, GLuint uniformModel, Model Teri, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	Teri.RenderModel();
}

void renderBowser(glm::mat4 model, GLuint uniformModel, Model bowser, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bowser.RenderModel();
}

void renderKingBoo(glm::mat4 model, GLuint uniformModel, Model kingBoo, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	kingBoo.RenderModel();
}

void renderDonkeyKong(glm::mat4 model, GLuint uniformModel, Model donkeyKong, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	donkeyKong.RenderModel();
}

void renderWario(glm::mat4 model, GLuint uniformModel, Model wario, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	wario.RenderModel();
}