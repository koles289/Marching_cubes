#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>

class kresliObjekt
{
public:
	kresliObjekt();
	void kresliHrany(std::vector<float>& xvert, std::vector<float>& yvert, std::vector<float>& zvert, std::vector<float>& xnorm, std::vector<float>& ynorm, std::vector<float>& znorm);
	void TransformujObjekt(int xnew, int ynew, int znew);

};

