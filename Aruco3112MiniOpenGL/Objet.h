#pragma once
#include <iostream>
#include <Windows.h>
#include <GL/gl.h>

#include "Geometry.h"
#include <vector>
using namespace std;
class Objet
{
protected :
	vector<Vertex> vertices;
	vector<Face> faces;
	vector<Tex> textureCoord;
	GLuint textureID;
public :
	void LoadOBJ(const char* filename);
	void LoadTexture(const char* path);
	void drawObjet();
	GLuint getTextureID();
};

