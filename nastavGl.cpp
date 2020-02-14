#include "nastavGl.h"

nastavGl::nastavGl(float* extremes, int sirka, int vyska)
{
	glMatrixMode(GL_PROJECTION);                  
	glLoadIdentity();
	glOrtho(-200, sirka, -200, vyska, -300, 300);
	glTranslatef(-100,-100,0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialShine);
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShineFactor);
	glLightfv(GL_LIGHT0, GL_POSITION, poziceSvetla);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	windowSettings();
	glViewport(0, 0, 800,800);
	glScalef(1, 1, 1);
}

void nastavGl::zmen(int sirka_okna, int vyska_okna,int sirka, int vyska)  {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200, sirka, -200, vyska, -300, 300);
	glScalef(1, 1, 1);
	glTranslatef(-100, -100, 0);
	glViewport(0, 0, sirka_okna, vyska_okna);
	glTranslatef(-sirka/3, -vyska/3, 0);

	
}
void nastavGl::obnov(int sirka_okna, int vyska_okna, int sirka, int vyska )
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200, sirka, -200, vyska, -300, 300);
	glTranslatef(-sirka / 3, -vyska / 3, 0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialShine);
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShineFactor);
	glLightfv(GL_LIGHT0, GL_POSITION, poziceSvetla);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	windowSettings();
	glViewport(0, 0, sirka_okna, vyska_okna);
	glScalef(1, 1, 1);

}

void nastavGl::windowSettings() {
	windowSet.depthBits = 24;
	windowSet.stencilBits = 8;
	windowSet.antialiasingLevel = 2;
}
