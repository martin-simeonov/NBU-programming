#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "GroupNode.h"

class TransformNode : public GroupNode
{
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
	float rotationDegree;

	static glm::mat4 transformMatrix;

public:
	TransformNode(const std::string& name) : GroupNode(name)
	{
		type = nt_TransformNode;
		translation = glm::vec3(0.0f);
		rotation = glm::vec3(1.0f);
		rotationDegree = 0.0;
		scale = glm::vec3(1.0f);
	}

	void SetTranslation(const glm::vec3& tr)
	{
		translation = tr;
	}

	void SetScale(const glm::vec3& sc)
	{
		scale = sc;
	}

	void SetRotation(float degree, const glm::vec3& rt)
	{
		rotationDegree = degree;
		rotation = rt;
	}

	void Traverse()
	{
		//push
		glm::mat4 matCopy = transformMatrix;

		transformMatrix = glm::translate(transformMatrix, translation);
		transformMatrix = glm::scale(transformMatrix, scale);
		transformMatrix = glm::rotate(transformMatrix, rotationDegree, rotation);
		for (int i = 0; i < children.size(); i++)
		{
			children[i]->Traverse();
		}

		//pop
		transformMatrix = matCopy;
	}

	static const glm::mat4 GetTransformMatrix()
	{
		return transformMatrix;
	}

};