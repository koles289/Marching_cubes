#include "kresliObjekt.h"

kresliObjekt::kresliObjekt()
{

}


void kresliObjekt::kresliHrany(std::vector<float>& xvert, std::vector<float>& yvert, std::vector<float>& zvert, std::vector<float>& xnorm, std::vector<float>& ynorm, std::vector<float>& znorm)
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < xvert.size(); i++)
	{
		glNormal3f(xnorm[i], ynorm[i], znorm[i]);
		glVertex3f(xvert[i], yvert[i], zvert[i]);
	}
	glEnd();
}



void kresliObjekt::TransformujObjekt(int xnew, int ynew, int znew)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glScalef(1, 2, 1);
	glTranslatef(0, znew, znew);
	glRotatef(znew, 1.0, 0.0, 0.0);
	glTranslatef(0, -znew, -znew);

	glTranslatef(ynew, xnew, 0);
}
