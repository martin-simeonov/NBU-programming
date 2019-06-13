#pragma once
#include <math.h>
#include "GeometryNode.h"
#include "GroupNode.h"
#include "TransformNode.h"
#include "Shader.h"


#define SPEED 0.2
#define EPSILON 0.1

bool compareFloat(float a, float b)
{
	return fabs(a - b) < EPSILON;
}

class Piston {
	TransformNode* transform;
	GeometryNode *model;
	glm::vec3 initialPosition;
	glm::vec3 currentPosition;
	
	bool leftBank;
	bool bdc;

public:
	Piston(const glm::vec3& position, const glm::vec3& tdcPosition, Shader* gShader, bool bdc, bool leftBank, string name)
	{
		initialPosition = tdcPosition;
		currentPosition = position;
		this->bdc = bdc;

		transform = new TransformNode(name + " transform");
		transform->SetTranslation(position);
		transform->SetScale(glm::vec3(1.25f, 1.25f, 1.25f));

		this->leftBank = leftBank;
		if (leftBank)
			transform->SetRotation(glm::radians(45.0f), glm::vec3(0.0, -1.0, 0.0f));
		else
			transform->SetRotation(glm::radians(45.0f), glm::vec3(0.0, 1.0, 0.0f));

		model = new GeometryNode(name);
		model->LoadFromFile("models/13476_Engine_Piston_v1_l1.obj");
		model->SetShader(gShader);

		transform->AddChild(model);
	}

	TransformNode* get()
	{
		return transform;
	}


	void move()
	{
		if (leftBank) {
			if (!bdc) {
				currentPosition.x += SPEED;
				currentPosition.z -= SPEED;
			}
			else {
				currentPosition.x -= SPEED;
				currentPosition.z += SPEED;
			}

			if (compareFloat(currentPosition.x, initialPosition.x)) {
				bdc = false;
			}

			if (compareFloat(currentPosition.x, -1.0f)) {
				bdc = true;
			}
		}
		else {
			if (!bdc) {
				currentPosition.x -= SPEED;
				currentPosition.z -= SPEED;
			}
			else {
				currentPosition.x += SPEED;
				currentPosition.z += SPEED;
			}

			if (compareFloat(currentPosition.z, initialPosition.z)) {
				bdc = false;
			}

			if (compareFloat(currentPosition.x, 1.0f)) {
				bdc = true;
			}
		}

		transform->SetTranslation(currentPosition);
	}

	bool isBdc() {
		return bdc;
	}
};