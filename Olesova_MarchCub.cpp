// Cviceni4udalosti.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>
#include "nastavGl.h"
#include "kresliObjekt.h"
#include "Folder_viewer.h"
#include "Marching_cubes.h"
#include "Mouse.h"

using namespace std;
//using namespace sf;


int main()
{
	

	bool jeFull = false;

	kresliObjekt kresli;
	Folder_viewer folder;
	Marching_cubes MarchingCubes;
	Mouse m;
	vector<float>xvert;
	vector<float>yvert;
	vector<float>zvert;

	vector<float>xnorm;
	vector<float>ynorm;
	vector<float>znorm;

	vector<string>folder_list;
	sf::Image Vrstva1;
	sf::Image Vrstva2;
	sf::Vector2u velikost;


	int NewVertexCount=0;
	int Cube_Index = 0;
	//sf::Color barva;

	float NewVertexList[15][3] = { 0 };
	float(*pnt_vertex)[15][3] = &NewVertexList;

	float NewNormalList[15][3] = { 0 };
	float(*pnt_normal)[15][3] = &NewNormalList;

	int count = 1;
	float extremes[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 };
	vector<int> body = { 0,0,0,0,0,0,0,0 };

	int CubeIndex = 0;
	int prah = 120;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	folder.read_directory("D:\\ProjektData\\", folder_list);
	Vrstva1.loadFromFile("D:\\ProjektData\\" + folder_list[2]);
	velikost = Vrstva1.getSize();
	int treti_rozmer = folder_list.size();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int k = 3; k < treti_rozmer; k++)
	{
		Vrstva2.loadFromFile("D:\\ProjektData\\" + folder_list[k]);
		for (int i = 0; i < velikost.x - 2; i++)
		{
			for (int j = 0; j < velikost.y - 2; j++)
			{
				body = { 0,0,0,0,0,0,0,0 };
				body[0] = (float)Vrstva1.getPixel(i, j).r;
				body[1] = (float)Vrstva1.getPixel(i + 1, j).r;
				body[2] = (float)Vrstva1.getPixel(i, j + 1).r;
				body[3] = (float)Vrstva1.getPixel(i + 1, j + 1).r;
				body[4] = (float)Vrstva2.getPixel(i, j).r;
				body[5] = (float)Vrstva2.getPixel(i + 1, j).r;
				body[6] = (float)Vrstva2.getPixel(i, j + 1).r;
				body[7] = (float)Vrstva2.getPixel(i + 1, j + 1).r;
				///////////////////////////////////////////////////
				
				if (body[0] < prah) CubeIndex |= 1;
				if (body[1] < prah) CubeIndex |= 2;
				if (body[2] < prah) CubeIndex |= 4;
				if (body[3] < prah) CubeIndex |= 8;
				if (body[4] < prah) CubeIndex |= 16;
				if (body[5] < prah) CubeIndex |= 32;
				if (body[6] < prah) CubeIndex |= 64;
				if (body[7] < prah) CubeIndex |= 128;

				//////////////////////////////
				NewVertexCount = MarchingCubes.Stanovenie_vrcholov_Interpolaciou(CubeIndex, body, pnt_vertex, pnt_normal, i, j, count);
				MarchingCubes.Add_vertices_to_vector(NewVertexCount, xvert, yvert, zvert, pnt_vertex);
				MarchingCubes.Add_vertices_to_vector(NewVertexCount, xnorm, ynorm, znorm, pnt_normal);
				CubeIndex = 0;
			}
		}
		Vrstva1 = {};
		Vrstva1 = Vrstva2;
		Vrstva2 = {};
		count++; 
	}
	std::cout << "Pri kliknuti na lave tlacidlo mysi sa model posunie o 30 pixelov" << endl;
	std::cout << "Pri kliknuti na prave tlacidlo mysi sa model otoci o 45 stupnov" << endl;

	sf::Window Aplikace(sf::VideoMode(800,800), "CT-sken hlavy Olesova");
	nastavGl nastaveniGL(extremes,velikost.x, velikost.y);

	while (Aplikace.isOpen())
	{

		sf::Event Udalosti;

		while (Aplikace.pollEvent(Udalosti))
		{
			if (Udalosti.type == sf::Event::Closed)
				Aplikace.close();
			if (Udalosti.type == sf::Event::Resized) {
				nastaveniGL.zmen(Udalosti.size.width, Udalosti.size.height, velikost.x, velikost.y);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				Aplikace.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				sf::VideoMode v(sf::VideoMode::getFullscreenModes()[0]);
				if (!jeFull) {
					Aplikace.create(sf::VideoMode(v), "CT-sken hlavy Olesova", sf::Style::Fullscreen);
					nastaveniGL.obnov(v.width, v.height, velikost.x, velikost.y);
					jeFull = true;
					break;
				}
				else {
					Aplikace.create(sf::VideoMode(800, 800), "CT-sken hlavy Olesova");
					nastaveniGL.obnov(800, 800, velikost.x, velikost.y);
					jeFull = false;
					break;
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (Udalosti.type == sf::Event::MouseButtonPressed) {
					m.setState(Mouse::State::Left);
					m.setXx(sf::Mouse::getPosition(Aplikace).x);
					m.setYy(sf::Mouse::getPosition(Aplikace).y);
				}
				m.onLeftButton(sf::Mouse::getPosition(Aplikace).x, sf::Mouse::getPosition(Aplikace).y);
		
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (Udalosti.type == sf::Event::MouseButtonPressed) {
					m.setState(Mouse::State::Right);
					m.setZz();
				}
				m.onRightButton(sf::Mouse::getPosition(Aplikace).x, sf::Mouse::getPosition(Aplikace).y);
		
			}

			if (Udalosti.type == sf::Event::MouseButtonReleased) {
	
					m.setXold(m.getXnew());
					m.setYold(m.getYnew());
					m.setZold(m.getZnew());
				m.setState(Mouse::State::None);
				break;
			}

		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		kresli.TransformujObjekt(m.getXnew(), m.getYnew(), m.getZnew());

		glBegin(GL_TRIANGLES);
		int delka = xvert.size();
		for (int i = 0; i < delka; i++)
		{
			glNormal3f(xnorm[i], ynorm[i], znorm[i]);
			glVertex3f(xvert[i], yvert[i], zvert[i]);
		}
		glEnd();



		glFlush();

		Aplikace.display();

	}

}
