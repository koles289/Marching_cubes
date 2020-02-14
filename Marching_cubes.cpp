#pragma once

#include "Marching_cubes.h"
using namespace std;

Marching_cubes::Marching_cubes()
{
}


Marching_cubes::~Marching_cubes()
{
}


float Marching_cubes::Interpolacia(int p1, int p2, float valp1, float valp2)
{
	float diff = (prah - valp1) / (valp2 - valp1);
	return(p1 +diff);
}

vector<float> Marching_cubes::Calculate_Normals(int x1, int x2, int y1, int y2, int z1, int z2)
{
	vector<float> normals;
	normals.push_back(y1 * z2 - y2 * z1);
	normals.push_back(z1 * x2 - x1 * z2);
	normals.push_back(x1 * y2 - y1 * x2);
	normals.push_back(sqrt(normals[0] * normals[0] + normals[1] * normals[1] + normals[2] * normals[2]));
	return (normals);

}

int Marching_cubes::Stanovenie_vrcholov_Interpolaciou(int CubeIndex, vector< int >& body, float(*NewVertexList)[15][3], float(*NewNormalList)[15][3], int i, int j, int count)
{
	float VertexList[12][3] = { 0 };
	float NormalList[12][3] = { 0 };
	//int NewVertexList[12][3] = {};
	vector<float> Normals;

	//Cube is entirely in/out of the surface
	if (edgeTable[CubeIndex] == 0)
		return(0);
	//Find the vertices where the surface intersects the cube
	if (edgeTable[CubeIndex] & 1)
	{
		Normals = Calculate_Normals(i, i + 1, j, j, count, count);

		VertexList[0][0] = Interpolacia(i, i + 1, body[0], body[1]);
		VertexList[0][1] = Interpolacia(j, j, body[0], body[1]);
		VertexList[0][2] = Interpolacia(count, count, body[0], body[1]);

		NormalList[0][0] = Normals[0]/Normals[3];
		NormalList[0][1] = Normals[1]/Normals[3];
		NormalList[0][2] = Normals[2]/Normals[3];
	}
	if (edgeTable[CubeIndex] & 2)
	{
		Normals = Calculate_Normals(i+1, i+1,j, j+1, count, count);

		VertexList[1][0] = Interpolacia(i+1, i+1, body[1], body[2]);
		VertexList[1][1] = Interpolacia(j, j + 1, body[1], body[2]);
		VertexList[1][2] = Interpolacia(count, count, body[1], body[2]);

		NormalList[1][0] = Normals[0] / Normals[3];
		NormalList[1][1] = Normals[1] / Normals[3];
		NormalList[1][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 4)
	{
		Normals = Calculate_Normals(i+1,i ,j+1, j+1, count, count);

		VertexList[2][0] = Interpolacia(i+1, i, body[2], body[3]);
		VertexList[2][1] = Interpolacia(j + 1, j + 1, body[2], body[3]);
		VertexList[2][2] = Interpolacia(count, count, body[2], body[3]);

		NormalList[2][0] = Normals[0] / Normals[3];
		NormalList[2][1] = Normals[1] / Normals[3];
		NormalList[2][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 8)
	{
		Normals = Calculate_Normals(i, i, j+1, j, count, count);

		VertexList[3][0] = Interpolacia(i, i, body[3], body[0]);
		VertexList[3][1] = Interpolacia(j + 1, j, body[3], body[0]);
		VertexList[3][2] = Interpolacia(count, count, body[3], body[0]);

		NormalList[3][0] = Normals[0] / Normals[3];
		NormalList[3][1] = Normals[1] / Normals[3];
		NormalList[3][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 16)
	{
		Normals = Calculate_Normals(i, i+1 , j, j, count+1, count+1);

		VertexList[4][0] = Interpolacia(i, i + 1, body[4], body[5]);
		VertexList[4][1] = Interpolacia(j, j, body[4], body[5]);
		VertexList[4][2] = Interpolacia(count + 1, count + 1, body[4], body[5]);

		NormalList[4][0] = Normals[0] / Normals[3];
		NormalList[4][1] = Normals[1] / Normals[3];
		NormalList[4][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 32)
	{
		Normals = Calculate_Normals(i+1, i+1 , j, j+1, count+1, count+1);

		VertexList[5][0] = Interpolacia(i + 1, i+1, body[5], body[6]);
		VertexList[5][1] = Interpolacia(j, j + 1, body[5], body[6]);
		VertexList[5][2] = Interpolacia(count + 1, count + 1, body[5], body[6]);

		NormalList[5][0] = Normals[0] / Normals[3];
		NormalList[5][1] = Normals[1] / Normals[3];
		NormalList[5][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 64)
	{
		Normals = Calculate_Normals(i+1, i, j+1, j+1, count+1, count+1);

		VertexList[6][0] = Interpolacia(i+1, i, body[6], body[7]);
		VertexList[6][1] = Interpolacia(j + 1, j+1 , body[6], body[7]);
		VertexList[6][2] = Interpolacia(count + 1, count + 1, body[6], body[7]);

		NormalList[6][0] = Normals[0] / Normals[3];
		NormalList[6][1] = Normals[1] / Normals[3];
		NormalList[6][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 128)
	{
		Normals = Calculate_Normals(i, i, j+1, j, count+1, count+1); //pridane count+1

		VertexList[7][0] = Interpolacia(i, i, body[7], body[4]);
		VertexList[7][1] = Interpolacia(j + 1, j, body[7], body[4]);
		VertexList[7][2] = Interpolacia(count+1, count+1, body[7], body[4]);

		NormalList[7][0] = Normals[0] / Normals[3];
		NormalList[7][1] = Normals[1] / Normals[3];
		NormalList[7][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 256)
	{
		Normals = Calculate_Normals(i, i , j, j, count+1, count);

		VertexList[8][0] = Interpolacia(i, i, body[4], body[0]);
		VertexList[8][1] = Interpolacia(j, j, body[4], body[0]);
		VertexList[8][2] = Interpolacia(count + 1, count, body[4], body[0]);

		NormalList[8][0] = Normals[0] / Normals[3];
		NormalList[8][1] = Normals[1] / Normals[3];
		NormalList[8][2] = Normals[2] / Normals[3];
	}

	if (edgeTable[CubeIndex] & 512)
	{
		Normals = Calculate_Normals(i+1, i + 1, j, j, count, count+1);

		VertexList[9][0] = Interpolacia(i + 1, i + 1, body[1], body[5]);
		VertexList[9][1] = Interpolacia(j, j, body[1], body[5]);
		VertexList[9][2] = Interpolacia(count, count + 1, body[1], body[5]);

		NormalList[9][0] = Normals[0] / Normals[3];
		NormalList[9][1] = Normals[1] / Normals[3];
		NormalList[9][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 1024)
	{
		Normals = Calculate_Normals(i+1, i+1 , j+1, j+1, count, count+1);

		VertexList[10][0] = Interpolacia(i+1, i+1, body[2], body[6]);
		VertexList[10][1] = Interpolacia(j + 1, j + 1, body[2], body[6]);
		VertexList[10][2] = Interpolacia(count, count + 1, body[2], body[6]);

		NormalList[10][0] = Normals[0] / Normals[3];
		NormalList[10][1] = Normals[1] / Normals[3];
		NormalList[10][2] = Normals[2] / Normals[3];
	}
	if (edgeTable[CubeIndex] & 2048)
	{
		Normals = Calculate_Normals(i, i, j+1, j+1, count, count+1);

		VertexList[11][0] = Interpolacia(i, i, body[3], body[7]);
		VertexList[11][1] = Interpolacia(j+1, j+1, body[3], body[7]);
		VertexList[11][2] = Interpolacia(count, count + 1, body[3], body[7]);

		NormalList[11][0] = Normals[0] / Normals[3];
		NormalList[11][1] = Normals[1] / Normals[3];
		NormalList[11][2] = Normals[2] / Normals[3];
	}

	int NewVertexCount = 0;

	for (UINT i = 0; triTable[CubeIndex][i] != -1; i++)
	{
			(*NewVertexList)[NewVertexCount][0] = VertexList[triTable[CubeIndex][i]][0];
			(*NewVertexList)[NewVertexCount][1] = VertexList[triTable[CubeIndex][i]][1];
			(*NewVertexList)[NewVertexCount][2] = VertexList[triTable[CubeIndex][i]][2];
			//LocalRemap[triTable[CubeIndex][i]] = NewVertexCount;

			(*NewNormalList)[NewVertexCount][0] = NormalList[triTable[CubeIndex][i]][0];
			(*NewNormalList)[NewVertexCount][1] = NormalList[triTable[CubeIndex][i]][1];
			(*NewNormalList)[NewVertexCount][2] = NormalList[triTable[CubeIndex][i]][2];

			NewVertexCount++;
		//}
	}


	return(NewVertexCount);

}


void Marching_cubes::Add_vertices_to_vector(int NewVertexCount, vector<float>& xvert, vector<float>& yvert, vector<float>& zvert, float(*NewVertexList)[15][3])
{
	for (int i = 0; i < NewVertexCount; i++) {
		xvert.push_back((*NewVertexList)[i][0]);
		yvert.push_back((*NewVertexList)[i][1]);
		zvert.push_back((*NewVertexList)[i][2]);
	}
	return;
}

void Marching_cubes::Add_Normal_to_vector(int NewVertexCount, vector<float>& xnorm, vector<float>& ynorm, vector<float>& znorm, float(*NewNormalList)[15][3])
{
	for (int i = 0; i < NewVertexCount; i++) {
		xnorm.push_back((*NewNormalList)[i][0]);
		ynorm.push_back((*NewNormalList)[i][1]);
		znorm.push_back((*NewNormalList)[i][2]);
	}
	return;
}



