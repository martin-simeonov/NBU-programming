#include "windows.h"

#include <GL\glew.h>

#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include <gl\GLU.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#include "Camera.h"
#include "Model.h"

#include "GeometryNode.h"
#include "GroupNode.h"
#include "TransformNode.h"

#include "Piston.h"


bool init();
bool initGL();
void render();
void close();

void CreateScene();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//OpenGL context
SDL_GLContext gContext;

Shader gShader;
Model gModel;
Model gModel2;

GroupNode* gRoot;

TransformNode* trBlock;

std::vector<Piston*> pistons;

bool pause = false;

GLuint gVAO, gVBO, gEBO;

// camera
Camera camera(glm::vec3(0.0f, -3.0f, 2.0f));
float lastX = -1;
float lastY = -1;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

//statics
unsigned int Node::genID;
glm::mat4 TransformNode::transformMatrix = glm::mat4(1.0f);

//event handlers
void HandleKeyDown(const SDL_KeyboardEvent& key);
void HandleMouseMotion(const SDL_MouseMotionEvent& motion);
void HandleMouseWheel(const SDL_MouseWheelEvent& wheel);

int main(int argc, char* args[])
{
	init();

	CreateScene();

	SDL_Event e;
	//While application is running
	bool quit = false;
	while (!quit)
	{
		// per-frame time logic
		// --------------------
		float currentFrame = SDL_GetTicks() / 1000.0f;
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
				else
				{
					HandleKeyDown(e.key);
				}
				break;
			case SDL_MOUSEMOTION:
				HandleMouseMotion(e.motion);
				break;
			case SDL_MOUSEWHEEL:
				HandleMouseWheel(e.wheel);
				break;
			}
		}
		
		//Render
		render();

		//Update screen
		SDL_GL_SwapWindow(gWindow);
	}

	close();

	return 0;
}

void HandleKeyDown(const SDL_KeyboardEvent& key)
{
	switch (key.keysym.sym)
	{
	case SDLK_w:
		camera.ProcessKeyboard(FORWARD, deltaTime);
		break;
	case SDLK_s:
		camera.ProcessKeyboard(BACKWARD, deltaTime);
		break;
	case SDLK_a:
		camera.ProcessKeyboard(LEFT, deltaTime);
		break;
	case SDLK_d:
		camera.ProcessKeyboard(RIGHT, deltaTime);
		break;
	case SDLK_SPACE:
		pause = !pause;
		break;
	}
}

void HandleMouseMotion(const SDL_MouseMotionEvent& motion)
{
	if (firstMouse)
	{
		lastX = motion.x;
		lastY = motion.y;
		firstMouse = false;
	}
	else
	{
		camera.ProcessMouseMovement(motion.x - lastX, lastY - motion.y);
		lastX = motion.x;
		lastY = motion.y;
	}
}

void HandleMouseWheel(const SDL_MouseWheelEvent& wheel)
{
	camera.ProcessMouseScroll(wheel.y);
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Use OpenGL 3.3
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);


		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create context
			gContext = SDL_GL_CreateContext(gWindow);
			if (gContext == NULL)
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Use Vsync
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}

				//Initialize OpenGL
				if (!initGL())
				{
					printf("Unable to initialize OpenGL!\n");
					success = false;
				}
			}
		}
	}

	return success;
}

bool initGL()
{
	bool success = true;
	GLenum error = GL_NO_ERROR;

	glewInit();

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		success = false;
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
	}

	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	gShader.Load("./shaders/vertex.vert", "./shaders/fragment.frag");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //other modes GL_FILL, GL_POINT

	return success;
}

void CreateScene()
{
	gRoot = new GroupNode("root");
	trBlock = new TransformNode("Engine block transform");
	trBlock->SetTranslation(glm::vec3(0.0f, -3.0f, -7.0f));
	trBlock->SetScale(glm::vec3(0.1f, 0.1f, 0.1f));
	trBlock->SetRotation(glm::radians(270.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	trBlock->SetRotation(glm::radians(360.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	GeometryNode *engineBlock = new GeometryNode("engine block");
	engineBlock->LoadFromFile("models/13475_V8_Engine_Block_v1_l1.obj");
	engineBlock->SetShader(&gShader);

	trBlock->AddChild(engineBlock);

	glm::vec3 leftTDC(-5.0f, -14.5f, -6.5f);
	glm::vec3 posLeft(-5.0f, -14.5f, -6.5f);
	// left bank
	// Piston 1 TDC
	pistons.push_back(new Piston(posLeft, leftTDC, &gShader, false, true, "Piston 1"));
	posLeft.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	// Piston 2 Fire
	posLeft.z = -7.5f;
	posLeft.x = -4.0f;
	pistons.push_back(new Piston(posLeft, leftTDC, &gShader, false, true, "Piston 2"));
	posLeft.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	// Piston 3 Compression
	posLeft.z = -8.5f;
	posLeft.x = -3.0;
	pistons.push_back(new Piston(posLeft, leftTDC, &gShader, true, true, "Piston 3"));
	posLeft.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	// Piston 4 BDC
	posLeft.z = -10.4f;
	posLeft.x = -1.1f;
	pistons.push_back(new Piston(posLeft, leftTDC, &gShader, true, true, "Piston 4"));
	posLeft.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	glm::vec3 rightTDC(5.0f, -14.5f, -6.5f);
	glm::vec3 posRight(5.0f, -14.5f, -6.5f);
	// right bank
	// Piston 5 Intake
	posRight.z = -7.5f;
	posRight.x = 4.0f;
	pistons.push_back(new Piston(posRight, rightTDC, &gShader, true, false, "Piston 5"));
	posRight.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	// Piston 6 BDC
	posRight.z = -10.4f;
	posRight.x = 1.1f;
	pistons.push_back(new Piston(posRight, rightTDC, &gShader, true, false, "Piston 6"));
	posRight.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	// Piston 7 TDC
	posRight.z = -6.5f;
	posRight.x = 5.0f;
	pistons.push_back(new Piston(posRight, rightTDC, &gShader, false, false, "Piston 7"));
	posRight.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	// Piston 8 TDC
	posRight.z = -8.5f;
	posRight.x = 3.0f;
	pistons.push_back(new Piston(posRight, rightTDC, &gShader, false, false, "Piston 8"));
	posRight.y += 9.8f;
	trBlock->AddChild(pistons.back()->get());

	gRoot->AddChild(trBlock);
}

void close()
{
	//delete GL programs, buffers and objects
	glDeleteProgram(gShader.ID);
	glDeleteVertexArrays(1, &gVAO);
	glDeleteBuffers(1, &gVBO);

	//Delete OGL context
	SDL_GL_DeleteContext(gContext);
	//Destroy window	
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void render()
{
	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 view = camera.GetViewMatrix();
	glm::mat4 proj = glm::perspective(glm::radians(camera.Zoom), 4.0f / 3.0f, 0.1f, 100.0f);

	glUseProgram(gShader.ID);
	gShader.setMat4("view", view);
	gShader.setMat4("proj", proj);

	//lighting
	gShader.setVec3("light.diffuse", 1.0f, 1.0f, 1.0f);
	gShader.setVec3("light.position", lightPos);
	gShader.setVec3("viewPos", camera.Position);

	if (!pause) {
		for (std::vector<Piston*>::iterator it = pistons.begin(); it != pistons.end(); ++it)
			(*it)->move();
	}

	gRoot->Traverse();
}
