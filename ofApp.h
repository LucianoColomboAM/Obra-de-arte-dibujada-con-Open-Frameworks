#pragma once

#include "ofMain.h"
#include "interaccion.h"




class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();
  void keyPressed( int key );
  void keyReleased( int key );
  void mousePressed(int x, int y, int button);
  void Figura1();
  Mover circulo;


 ///////////////////////////////////////
  int ylinea11 = 140;
  int ylinea21 = 116;
  int yrect11 = 103;
  int yrect21 = 149;
  int direccion = 1;
  int direccion1 = 1;
  int direccion2 = 1;
  int direccion3 = 1;
///////////////////////////////////////
  int x1 = 240;
  int x2 = 210;
  int y1 = 113;
  int y2 = 130;
  ///////////////////////////////////////
  int ya = 369;
  int yb = 375;

///////////////////////////////////////
  int mouseX;
  int mouseY;

  ///////////////////////////////////////
  ofSoundPlayer Sound;



};