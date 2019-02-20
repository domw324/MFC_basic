#pragma once

struct Point
{
public:
	int nX, nY;

	Point() {
		this->nX = this->nY = 0;
	}

	Point(int nX, int nY)
	{
		this->nX = nX;
		this->nY = nY;
	}
};