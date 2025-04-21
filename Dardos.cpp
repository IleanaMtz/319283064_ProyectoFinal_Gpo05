#include "Dardos.h"

void dardos(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosDardos, Texture &tierra, std::vector<Mesh*> meshList) {
	renderStand4(model, uniformModel, objetosDardos[0], objetosDardos[1], objetosDardos[2], objetosDardos[3], objetosDardos[4], glm::vec3(50.0f, -1.0f, -140.0f), tierra, meshList);
}

void renderStand4(glm::mat4 model, GLuint uniformModel, Model stand, Model base, Model globo, Model tabla, Model dardo, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista) {
	glm::mat4 modelaux(1.0);
	glm::mat4 modelaux2(1.0);
	//Piso
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	modelaux = model;
	model = glm::scale(model, glm::vec3(80.0f, 0.05f, 130.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	lista[4]->RenderMesh();

	//Casa
	modelaux = glm::translate(modelaux, glm::vec3(0.0f, -0.42f, 0.0f));
	model = modelaux;
	modelaux = glm::scale(modelaux, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelaux));
	stand.RenderModel();

	//Tabla
	model = glm::translate(model, glm::vec3(-1.0f, 5.0f, 15.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(2.1f, 2.0f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tabla.RenderModel();

	//Dardos
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.7f, 0.0f));
	modelaux = model;
	modelaux2 = model;
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -15.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();

	//Base1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-10.0f, 3.0f, -35.0f));
	modelaux = model;
	modelaux2 = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	base.RenderModel();
	//Globo1.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-2.5f, 5.5f, -1.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();

	//Base2
	model = modelaux2;
	model = glm::translate(model, glm::vec3(20.0f, 0.0f, 0.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	base.RenderModel();
	//Globo1.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-2.5f, 5.5f, -1.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
}