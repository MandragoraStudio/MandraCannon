#pragma once

class Physics
{
protected:
	int x, y;				// Coordeanadas del objeto
	double mass;			// Masa del objeto
	double velocity;		// Velocidad del objeto
	double angle;			// Angulo 
	double velocityWind;
	//double strengthWind;
	double gravity;
public:
	Physics(void);
	~Physics(void);
};

