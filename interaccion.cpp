#include "interaccion.h"

///////////////////////////////////////////////////////////////////////////
void Mover::setup()
{
	// Inicializamos la masa y el radio.
	masa = 1;
	radio = masa * 5;
	
	posicion.set(133, 104);
	velocidad.set(0, 0);
	aceleracion.set(0, 0);
}

///////////////////////////////////////////////////////////////////////////
void Mover::update()
{
	velocidad += aceleracion;

	// En este caso no hace falta limitar la velocidad porque el objeto va a
	// estar acelerándose y desacelerándose contínuamente al estar siempre
	// rebotando con los bordes. Por lo que nunca el objeto va a estar
	// aumentado la velocidad continuamente de manera indefinida.
	/** velocidad.limit(10); */
	posicion += velocidad;

	// Reseteamos la aceleración para que no se acumulen las fuerzas.
	aceleracion *= 0;
}

///////////////////////////////////////////////////////////////////////////
void Mover::draw()
{
	ofSetColor(0);
	ofDrawCircle(posicion, radio);
}

///////////////////////////////////////////////////////////////////////////
// Hacemos que el objeto rebote con los bordes invirtiendo la velocidad.
// Si bien no es conveniente manipular la velocidad, en este caso lo
// haremos por una cuestión de simplicidad.
void Mover::colisionBordes()
{

	if (posicion.y > ofGetHeight() - radio)
	{
		// En la colisión con los bordes el objeto suele pasarse del borde por
		// más de un píxel. Esto hace que el objeto comienze a reducir su
		// trayectoria restando esos píxeles hasta que con el tiempo se queda
		// rebotando infinitamente en el borde. Para que esto no pase tenemos
		// que posicionar el objeto justo en el borde luego de la colisión.
		posicion.y = ofGetHeight() - radio; // Probar comentando esta línea.

		velocidad.y *= -1;                  // Hacemos el cambio de dirección
	}
	else if (posicion.y < 0 + radio)
	{
		posicion.y = radio;
		velocidad.y *= -1;
	}

	if (posicion.x > ofGetWidth() - radio)
	{
		posicion.x = ofGetWidth() - radio;
		velocidad.x *= -1;
	}
	else if (posicion.x < 0 + radio)
	{
		posicion.x = radio;
		velocidad.x *= -1;
	}
}

///////////////////////////////////////////////////////////////////////////
// Implementamos el método aplicarFuerza.
void Mover::aplicarFuerza(ofVec2f fuerza)
{
	ofVec2f a = fuerza / masa; // Segunda ley de Newton
	aceleracion += a;
}