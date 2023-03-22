#pragma once
#include "ofMain.h"


class Mover
{
public:
	void setup();
	void update();
	void draw();
	void colisionBordes();

	// Agregamos el método para aplicar las fuerzas.
	void aplicarFuerza(ofVec2f fuerza);

	int radio;
	ofVec2f posicion;
	ofVec2f velocidad;
	ofVec2f aceleracion;

	// Agregamos la propiedad masa.
	float masa;
};