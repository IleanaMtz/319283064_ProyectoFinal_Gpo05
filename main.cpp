
#define STB_IMAGE_IMPLEMENTATION


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
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"

//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"

//Modelos ambientación
#include "Ambientacion.h"

//Modelos NPCs
#include "NPCs.h"

//Juegos
#include "Dados.h"
#include "Bateo.h"
#include "Bolos.h"
#include "Dardos.h"
#include "Hacha.h"
#include "Topos.h"

const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
std::vector<Model> objetosAmbientacion;
std::vector<Model> objetosDados;
std::vector<Model> objetosBateo;
std::vector<Model> objetosBolos;
std::vector<Model> objetosDardos;
std::vector<Model> objetosHacha;
std::vector<Model> objetosTopos;
std::vector<Model> personajesNPCs;

//Camaras realizadas 
Camera camera;

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture tierraTexture;

//Modelo puestos
Model Stand;
Model Stand2;
Model Stand3;
Model Stand4;
Model Stand5;
Model Stand6;

//modelos de personajes 
Model gumball;
Model yoshi;
Model snoopy;

//Modelos ambientación
Model banca;
Model luminaria1;
Model luminaria2;
Model luminaria3;
Model arbol1;
Model arbol2;
Model arbol3;
Model bote1;
Model bote2;

//Modelos NPCs
Model woodstock;
Model peppermint;
Model charlie;
Model carrie;
Model teri;
Model bowser;
Model kingBoo;
Model donkeyKong;
Model wario;

Skybox skybox;

//materiales
Material Material_brillante;
Material Material_opaco;

//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

// luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight

PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";


//función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}

void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,


	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj4);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);
}

void CrearDado()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,

		// back
		8, 9, 10,
		10, 11, 8,

		// left
		12, 13, 14,
		14, 15, 12,
		// bottom
		16, 17, 18,
		18, 19, 16,
		// top
		20, 21, 22,
		22, 23, 20,

		// right
		4, 5, 6,
		6, 7, 4,

	};

	GLfloat cubo_vertices[] = {
		// front
		//x		y		z		S		T			NX		NY		NZ
		-0.5f, -0.5f,  0.5f,	0.26f,  0.34f,		0.0f,	0.0f,	-1.0f,	//0
		0.5f, -0.5f,  0.5f,		0.49f,	0.34f,		0.0f,	0.0f,	-1.0f,	//1
		0.5f,  0.5f,  0.5f,		0.49f,	0.66f,		0.0f,	0.0f,	-1.0f,	//2
		-0.5f,  0.5f,  0.5f,	0.26f,	0.66f,		0.0f,	0.0f,	-1.0f,	//3
		// right
		//x		y		z		S		T
		0.5f, -0.5f,  0.5f,	    0.0f,  0.0f,		-1.0f,	0.0f,	0.0f,
		0.5f, -0.5f,  -0.5f,	1.0f,	0.0f,		-1.0f,	0.0f,	0.0f,
		0.5f,  0.5f,  -0.5f,	1.0f,	1.0f,		-1.0f,	0.0f,	0.0f,
		0.5f,  0.5f,  0.5f,	    0.0f,	1.0f,		-1.0f,	0.0f,	0.0f,
		// back
		-0.5f, -0.5f, -0.5f,	0.0f,  0.0f,		0.0f,	0.0f,	1.0f,
		0.5f, -0.5f, -0.5f,		1.0f,	0.0f,		0.0f,	0.0f,	1.0f,
		0.5f,  0.5f, -0.5f,		1.0f,	1.0f,		0.0f,	0.0f,	1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f,	1.0f,		0.0f,	0.0f,	1.0f,

		// left
		//x		y		z		S		T
		-0.5f, -0.5f,  -0.5f,	0.0f,  0.0f,		1.0f,	0.0f,	0.0f,
		-0.5f, -0.5f,  0.5f,	1.0f,	0.0f,		1.0f,	0.0f,	0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f,	1.0f,		1.0f,	0.0f,	0.0f,
		-0.5f,  0.5f,  -0.5f,	0.0f,	1.0f,		1.0f,	0.0f,	0.0f,

		// bottom
		//x		y		z		S		T
		-0.5f, -0.5f,  0.5f,	0.0f,  0.0f,		0.0f,	1.0f,	0.0f,
		0.5f,  -0.5f,  0.5f,	1.0f,	0.0f,		0.0f,	1.0f,	0.0f,
		 0.5f,  -0.5f,  -0.5f,	1.0f,	1.0f,		0.0f,	1.0f,	0.0f,
		-0.5f, -0.5f,  -0.5f,	0.0f,	1.0f,		0.0f,	1.0f,	0.0f,

		//UP
		 //x		y		z		S		T
		 -0.5f, 0.5f,  0.5f,	0.0f,  0.0f,		0.0f,	-1.0f,	0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f,	0.0f,		0.0f,	-1.0f,	0.0f,
		  0.5f, 0.5f,  -0.5f,	1.0f,	1.0f,		0.0f,	-1.0f,	0.0f,
		 -0.5f, 0.5f,  -0.5f,	0.0f,	1.0f,		0.0f,	-1.0f,	0.0f,

	};

	Mesh* dado = new Mesh();
	dado->CreateMesh(cubo_vertices, cubo_indices, 192, 36);
	meshList.push_back(dado);
}

void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CrearDado();
	CreateShaders();

	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.5f);

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/pasto.png");
	pisoTexture.LoadTextureA();
	tierraTexture = Texture("Textures/tierra.jpg");
	tierraTexture.LoadTextureA();
  
  //Modelos puestos
	Stand = Model();
	Stand.LoadModel("Models/StandHacha.obj");
	Stand2 = Model();
	Stand2.LoadModel("Models/StandBateo.obj");
	Stand3 = Model();
	Stand3.LoadModel("Models/StandDados.obj");
	Stand4 = Model();
	Stand4.LoadModel("Models/StandDardos.obj");
	Stand5 = Model();
	Stand5.LoadModel("Models/StandBolos.obj");
	Stand6 = Model();
	Stand6.LoadModel("Models/StandTopos.obj");

	objetosHacha.push_back(Stand);
	objetosBateo.push_back(Stand2);
	objetosDados.push_back(Stand3);
	objetosDardos.push_back(Stand4);
	objetosBolos.push_back(Stand5);
	objetosTopos.push_back(Stand6);

	//Modelos ambientación
	banca = Model();
	banca.LoadModel("Models/banca.obj");
	luminaria1 = Model();
	luminaria1.LoadModel("Models/luminaria1.obj");
	luminaria2 = Model();
	luminaria2.LoadModel("Models/luminaria2.obj");
	luminaria3 = Model();
	luminaria3.LoadModel("Models/luminaria3.obj");
	arbol1 = Model();
	arbol1.LoadModel("Models/arbol1.obj");
	arbol2 = Model();
	arbol2.LoadModel("Models/arbol2.obj");
	arbol3 = Model();
	arbol3.LoadModel("Models/arbol3.obj");
	bote1 = Model();
	bote1.LoadModel("Models/bote1.obj");
	bote2 = Model();
	bote2.LoadModel("Models/bote2.obj");

	//Modelos de personajes
	objetosAmbientacion.push_back(banca);
	objetosAmbientacion.push_back(luminaria1);
	objetosAmbientacion.push_back(luminaria2);
	objetosAmbientacion.push_back(luminaria3);
	objetosAmbientacion.push_back(arbol1);
	objetosAmbientacion.push_back(arbol2);
	objetosAmbientacion.push_back(arbol3);
	objetosAmbientacion.push_back(bote1);
	objetosAmbientacion.push_back(bote2);

	////Modelos comida
	//StandComida1 = Model();
	//StandComida1.LoadModel("Models/banca.obj");
	//StandComida2 = Model();
	//StandComida2.LoadModel("Models/luminaria1.obj");
	//StandComida3 = Model();
	//StandComida3.LoadModel("Models/luminaria2.obj");

	//objetosComida.push_back(StandComida1);
	//objetosComida.push_back(StandComida2);
	//objetosComida.push_back(StandComida3);

	//Modelos NPCs
	woodstock = Model();
	woodstock.LoadModel("Models/Woodstock.obj");
	peppermint = Model();
	peppermint.LoadModel("Models/Peppermint.obj");
	charlie = Model();
	charlie.LoadModel("Models/Charlie.obj");

	////Gumball
	//carrie = Model();
	//carrie.LoadModel("Models/Woodstock.obj");
	//teri = Model();
	//teri.LoadModel("Models/Peppermint.obj");

	////Mario
	//bowser = Model();
	//bowser.LoadModel("Models/Charlie.obj");
	//kingBoo = Model();
	//kingBoo.LoadModel("Models/Charlie.obj");
	//donkeyKong = Model();
	//donkeyKong.LoadModel("Models/Charlie.obj");
	//wario = Model();
	//wario.LoadModel("Models/Charlie.obj");

	personajesNPCs.push_back(woodstock);
	personajesNPCs.push_back(peppermint);
	personajesNPCs.push_back(charlie);
	personajesNPCs.push_back(carrie);
	personajesNPCs.push_back(teri);
	personajesNPCs.push_back(bowser);
	personajesNPCs.push_back(kingBoo);
	personajesNPCs.push_back(donkeyKong);
	personajesNPCs.push_back(wario);

	std::vector<std::string> skyboxFaces;

	skyboxFaces.push_back("Textures/Skybox/right.tga");
	skyboxFaces.push_back("Textures/Skybox/left.tga");
	skyboxFaces.push_back("Textures/Skybox/down.tga");
	skyboxFaces.push_back("Textures/Skybox/up.tga");
	skyboxFaces.push_back("Textures/Skybox/front.tga");
	skyboxFaces.push_back("Textures/Skybox/back.tga");

	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);

	//luz direccional, sólo 1 y siempre debe de existir 
	// Para la luz del sol
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		0.3f, 0.3f,
		0.0f, 0.0f, -1.0f);
	//contador de luces puntuales
	unsigned int pointLightCount = 0;

	//Declaración de primer luz puntual
	pointLights[0] = PointLight(1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,
		5.0f, 3.0f, -4.0f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	unsigned int spotLightCount = 0;

	spotLights[0] = SpotLight(1.0f, 0.0f, 1.0f,
		1.0f, 2.0f,
		0.0f, -1.0f, -6.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.1f, 0.0f,
		20.0f);
	spotLightCount++;

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);

	glm::mat4 model(1.0);
	glm::mat4 modelaux(1.0);
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		//Recibir eventos del usuario
		glfwPollEvents();

		//variables para control de camara y personajes
		glm::vec3 cameraPos = camera.getCameraPosition();
		glm::vec3 cameraDir = camera.getCameraDirection();
		float angulo = atan2(terceraPersonaCamera.getCameraDirection().x, terceraPersonaCamera.getCameraDirection().z);
		Camera* activeCamera;

		//Switch que controla la camara activa 
		switch (mainWindow.getCamaraActiva()) {
		case 0:
			activeCamera = &camera;
			break;
		case 1:
			activeCamera = &aerialCamera;
			break;

		case 2: {
			// Dirección que apunta la cámara (sin componente Y)
			glm::vec3 forward = glm::normalize(glm::vec3(terceraPersonaCamera.getCameraDirection().x, 0.0f, terceraPersonaCamera.getCameraDirection().z));

			// Offset detrás y arriba del modelo
			glm::vec3 camOffset = -forward * 7.0f + glm::vec3(0.0f, 2.5f, 0.0f);

			// Posición de la cámara = posición del modelo + offset
			glm::vec3 camPos = posicionModelo + camOffset;

			terceraPersonaCamera.setPosition(camPos);
			activeCamera = &terceraPersonaCamera;
			break;
		}
		case 3:
			activeCamera = &camaraPuestos;
			break;
		default:
			activeCamera = &camera; // Fallback a cámara libre
			break;
		}

		GLfloat xChange = mainWindow.getXChange();
		GLfloat yChange = mainWindow.getYChange();

		//Switch para control de mouse en la camara activa
		switch (mainWindow.getCamaraActiva()) {
		case 0: camera.mouseControl(xChange, yChange); camera.keyControl(mainWindow.getsKeys(), deltaTime); break;
		case 1: aerialCamera.mouseControl(xChange, yChange); break;
		case 2:
			terceraPersonaCamera.mouseControl(xChange, yChange);
			glm::vec3 forward = glm::normalize(glm::vec3(terceraPersonaCamera.getCameraDirection().x, 0.0f, terceraPersonaCamera.getCameraDirection().z));
			glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));

				if (mainWindow.getsKeys()[GLFW_KEY_W])
					posicionModelo += forward * deltaTime * 1.5f;
				if (mainWindow.getsKeys()[GLFW_KEY_S])
					posicionModelo -= forward * deltaTime * 1.5f;
				if (mainWindow.getsKeys()[GLFW_KEY_A])
					posicionModelo -= right * deltaTime * 1.5f;
				if (mainWindow.getsKeys()[GLFW_KEY_D])
					posicionModelo += right * deltaTime * 1.5f;
			break;
		case 3: camaraPuestos.mouseControl(xChange, yChange); break;
		}

		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());


		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();

		//información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		// luz ligada a la cámara de tipo flash
		//sirve para que en tiempo de ejecución (dentro del while) se cambien propiedades de la luz
		//glm::vec3 lowerLight = camera.getCameraPosition();
		//lowerLight.y -= 0.3f;
		//spotLights1[0].SetFlash(lowerLight, camera.getCameraDirection());

		//Luces al shader 
		// shaderList[0].SetSpotLights(spotLights, spotLightCount);
		// shaderList[0].SetPointLights(pointLights1, pointLightCount1);

		shaderList[0].SetDirectionalLight(&mainLight);

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[2]->RenderMesh();

		//Modelos ambientación
		ambientacion(model, uniformModel, objetosAmbientacion);

		//Personajes  (Para utilizar un personaje distinto comenta el personaje actual y descomenta el que quieras usar)
		
		////gumball
		//model = glm::mat4(1.0);
		//model = glm::translate(model, posicionModelo);
		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		//model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//gumball.RenderModel();
		
		/*
		//yoshi

		model = glm::mat4(1.0);
		model = glm::translate(model, posicionModelo);
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		yoshi.RenderModel();
		*/
		
		//snoopy
		model = glm::mat4(1.0);
		model = glm::translate(model, posicionModelo);
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		snoopy.RenderModel();
		
		//Modelos NPCs
		NPCs(model, uniformModel, personajesNPCs);
  
		//Dados
		model = glm::mat4(1.0);
		dados(model, uniformModel, objetosDados, tierraTexture, meshList);

		//Lanzamiento de hacha
		model = glm::mat4(1.0);
		hacha(model, uniformModel, objetosHacha, tierraTexture, meshList);

		//Dardos
		model = glm::mat4(1.0);
		dardos(model, uniformModel, objetosDardos, tierraTexture, meshList);

		//Golpea al topo
		model = glm::mat4(1.0);
		topos(model, uniformModel, objetosTopos, tierraTexture, meshList);

		//Jaula de bateo
		model = glm::mat4(1.0);
		bateo(model, uniformModel, objetosBateo, tierraTexture, meshList);

		//Línea de boliche
		model = glm::mat4(1.0);
		bolos(model, uniformModel, objetosBolos, tierraTexture, meshList);

		//Área de comida
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-210.0f, -0.8f, 0.0f));
		model = glm::scale(model, glm::vec3(80.0f, 0.05f, 220.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		//Caminos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(180.0f, -0.8f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 0.05f, 150.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(225.0f, -0.8f, 0.0f));
		model = glm::scale(model, glm::vec3(70.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(115.0f, -0.8f, -140.0f));
		model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(115.0f, -0.8f, 140.0f));
		model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-15.0f, -0.8f, -140.0f));
		model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-15.0f, -0.8f, 140.0f));
		model = glm::scale(model, glm::vec3(50.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -0.8f, -140.0f));
		model = glm::scale(model, glm::vec3(100.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -0.8f, 140.0f));
		model = glm::scale(model, glm::vec3(100.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-210.0f, -0.8f, -120.0f));
		model = glm::scale(model, glm::vec3(20.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-210.0f, -0.8f, 120.0f));
		model = glm::scale(model, glm::vec3(20.0f, 0.05f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tierraTexture.UseTexture();
		meshList[4]->RenderMesh();

		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}