#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>
#include "windows.h"

class nastavGl
{
public:
	nastavGl(float* extremes, int sirka, int vyska);
	void zmen(int sirka_okna, int vyska_okna, int sirka, int vyska);
	void obnov(int sirka_okna, int vyska_okna, int sirka, int vyska);
	void windowSettings();
	const sf::ContextSettings& getWindowSet() const
	{
		return windowSet;
	}

private:
	GLfloat materialAmbient[4] = { 0.5f, 0.5f, 0.5f, 0.0f };
	GLfloat materialDiffuse[4] = { 0.8f, 0.4f, 0.4f, 0.0f };
	GLfloat materialShine[4] = { 0.8f, 0.4f, 0.4f, 0.0f };
	GLfloat materialShineFactor[1] = { 30.0f };
	GLfloat poziceSvetla[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
	sf::ContextSettings windowSet;
};

