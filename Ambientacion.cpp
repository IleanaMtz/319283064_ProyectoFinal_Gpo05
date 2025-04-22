#include "Ambientacion.h"

const float toRadians = 3.14159265f / 180.0f;

void ambientacion(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosAmbientacion) {
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(150.0f, -1.0f, -140.0f), 0);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(152.0f, -1.0f, 140.0f), 0);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(20.0f, -1.0f, -140.0f), 0);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(22.0f, -1.0f, 140.0f), 0);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(-110.0f, -1.0f, -140.0f), 0);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(-108.0f, -1.0f, 140.0f), 0);

	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(208.0f, -1.0f, -140.0f), 180);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(210.0f, -1.0f, 140.0f), 180);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(78.0f, -1.0f, -140.0f), 180);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(80.0f, -1.0f, 140.0f), 180);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(-52.0f, -1.0f, -140.0f), 180);
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(-50.0f, -1.0f, 140.0f), 180);

	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(115.0f, -1.0f, -77.0f), -90);
	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(115.0f, -1.0f, 77.0f), 90);
	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(-15.0f, -1.0f, -77.0f), -90);
	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(-15.0f, -1.0f, 77.0f), 90);
	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(-145.0f, -1.0f, -77.0f), -90);
	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(-145.0f, -1.0f, 77.0f), 90);

	//renderLuminaria2(model, uniformModel, objetosAmbientacion[2], glm::vec3(20.0f, -1.02f, 0.0f));
	//renderLuminaria3(model, uniformModel, objetosAmbientacion[3], glm::vec3(30.0f, -1.02f, 0.0f));
	
	renderArbol1(model, uniformModel, objetosAmbientacion[4], glm::vec3(250.0f, -1.0f, -140.0f));
	renderArbol3(model, uniformModel, objetosAmbientacion[6], glm::vec3(250.0f, -1.0f, 140.0f));

	renderArbol1(model, uniformModel, objetosAmbientacion[4], glm::vec3(-200.0f, -1.0f, 220.0f));
	renderArbol3(model, uniformModel, objetosAmbientacion[6], glm::vec3(-200.0f, -1.0f, -220.0f));

	renderBote1(model, uniformModel, objetosAmbientacion[7], glm::vec3(-160.0f, -1.0f, 90.0f), 90);
	renderBote2(model, uniformModel, objetosAmbientacion[8], glm::vec3(-160.0f, -1.0f, 98.0f), 90);
	renderBote1(model, uniformModel, objetosAmbientacion[7], glm::vec3(-160.0f, -1.0f, -90.0f), 90);
	renderBote2(model, uniformModel, objetosAmbientacion[8], glm::vec3(-160.0f, -1.0f, -98.0f), 90);
}

void renderBanca(glm::mat4 model, GLuint uniformModel, Model banca, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	banca.RenderModel();
}

void renderLuminaria1(glm::mat4 model, GLuint uniformModel, Model luminaria1, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	luminaria1.RenderModel();
}

void renderLuminaria2(glm::mat4 model, GLuint uniformModel, Model luminaria2, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	luminaria2.RenderModel();
}

void renderLuminaria3(glm::mat4 model, GLuint uniformModel, Model luminaria3, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	luminaria3.RenderModel();
}

void renderArbol1(glm::mat4 model, GLuint uniformModel, Model arbol1, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	arbol1.RenderModel();
}

void renderArbol2(glm::mat4 model, GLuint uniformModel, Model arbol2, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	arbol2.RenderModel();
}

void renderArbol3(glm::mat4 model, GLuint uniformModel, Model arbol3, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(9.0f, 9.0f, 9.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	arbol3.RenderModel();
}

void renderBote1(glm::mat4 model, GLuint uniformModel, Model bote1, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(15.0f, 15.0f, 15.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bote1.RenderModel();
}

void renderBote2(glm::mat4 model, GLuint uniformModel, Model bote2, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(15.0f, 15.0f, 15.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bote2.RenderModel();
}

