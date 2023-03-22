#include "ofApp.h"


///////////////////////////////////////////////////////////////////////
void ofApp::setup()
{
  ofSetWindowShape(272, 700);
  ofSetBackgroundColor(0);
  ofSetFrameRate(60);
  Sound.load("bottleopen.mp3");
	  
  circulo.setup();
  
}

///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
void ofApp::update()

{
	ofSoundUpdate();
	// Creamos las fuerzas para nuestro sistema.
	ofVec2f viento(0.01, 0);
	ofVec2f gravedad(0, 0.1);

	// Aplicamos las fuerzas al objeto.
	circulo.aplicarFuerza(viento);
	circulo.aplicarFuerza(gravedad);

	circulo.update();
	circulo.colisionBordes();

	ylinea11 = ylinea11+ direccion;
	ylinea21 = ylinea21 - direccion1;
	yrect11 = yrect11 - direccion2;
	yrect21 = yrect21 + direccion3;

	if (ylinea11 >= 185) {direccion = direccion*-1;}

	if (ylinea11 <= 70){ direccion = direccion * -1; }

	if (ylinea21 >= 185) { direccion1 = direccion * -1; }

	if (ylinea21 <= 75) { direccion1 = direccion * -1; }

	if (yrect11 >= 185) { direccion2 = direccion * -1; }

	if (yrect11 <= 70) { direccion2 = direccion * -1; }

	if (yrect21 >= 185) { direccion3 = direccion * -1; }

	if (yrect21 <= 70) { direccion3 = direccion * -1; }


	
	
	
	y1 = y1 + 1;
	y2 = y2 + 1;

	if (y2 >= 236) {
		 y1 = 113;
		 y2 = 130;
	}

	 ya = ya + 1;
	 yb = yb + 1;


	 if (yb >= 603) {

		  ya = 369;
		  yb = 375;

	 }



}

///////////////////////////////////////////////////////////////////////
void ofApp::draw()
{
	ofSetColor(30,38,60);
	for (int i = 0; i < 622; i++) {
		
		ofDrawLine(0, i, 272, i + 78);
	}
	ofSetColor(0, 0, 0);
	ofBeginShape();
	ofVertex(40, 56);
	ofVertex(240, 114);
	ofVertex(240, 658);
	ofVertex(40, 597);
	ofEndShape();

	
	Figura1();

	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(255, 10);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofEnableAlphaBlending();


	

	if (mouseX > 39 && mouseX < 86 && mouseY > 54 && mouseY < 196) 
	{
		Sound.play();
		ofSetColor(51, 55, 62);
		ofBeginShape();
		ofVertex(40, 55);
		ofVertex(85, 70);
		ofVertex(85, 195);
		ofVertex(40, 195);
		ofEndShape();
		ofSetColor(85, 67, 35);
		ofDrawLine(40, ylinea11, 85, ylinea11);
		ofDrawLine(40, ylinea21, 85, ylinea21);
		ofSetColor(30, 45, 70);
		ofDrawRectangle(40, yrect11, 45, 10);
		ofDrawRectangle(40, yrect21, 45, 10);



	}


	if (mouseY > 135 && mouseY < 266 && mouseX>121 && mouseX<142) {
		Sound.play();
		ofSetColor(51, 55, 62);
		ofBeginShape();
		ofVertex(121, 135);
		ofVertex(142, 135);
		ofVertex(142, 266);
		ofVertex(121, 266);
		ofEndShape();

		ofSetColor(85, 67, 35);
		ofDrawCircle(133, 164, 5);
		ofDrawCircle(133, 194, 5);

		circulo.draw();
	}


	if (mouseX>190 && mouseX < 240 && mouseY > 104 && mouseY < 236) {
		Sound.play();
		ofSetColor(80, 59, 16);
		ofBeginShape();
		ofVertex(210, 105);
		ofVertex(240, 113);
		ofVertex(240, 235);
		ofVertex(190, 235);
		ofEndShape();
		ofSetColor(30, 45, 70);
		ofDrawTriangle(x1, y1, x1, y2, x2, y1);

	}



	if (mouseX > 39 && mouseX < 62 && mouseY > 369 && mouseY < 603) 
	{
		Sound.play();
		ofSetColor(100, 95, 13);
		ofBeginShape();
		ofVertex(40, 369);
		ofVertex(62, 375);
		ofVertex(62, 603);
		ofVertex(40, 597);
		ofEndShape();
		ofSetColor(30, 45, 70);
	
		ofDrawLine(40, ya, 62, yb);
	

	}




}

///////////////////////////////////////////////////////////////////////
void ofApp::keyPressed(int key)
{
 
}

///////////////////////////////////////////////////////////////////////
void ofApp::keyReleased(int key)
{
}

///////////////////////////////////////////////////////////////////////
void ofApp::mousePressed(int x, int y, int button)
{
	mouseX = x;
	mouseY = y;
}


///////////////////////////////////////////////////////////////////////
void ofApp::Figura1()
{
	ofSetColor(51,55,62);
	ofBeginShape();
	ofVertex(40, 55);
	ofVertex(85, 70);
	ofVertex(85, 195);
	ofVertex(40, 195);
	ofEndShape();


	ofSetColor(30, 45, 70);
	ofDrawRectangle(40,103,45,10);
	ofSetColor(85, 67, 35);
	ofDrawLine(40,116,85,116);
	ofSetColor(30, 45, 70);
	ofDrawRectangle(40, 119, 45, 10);
	ofSetColor(85, 67, 35);
	ofDrawLine(40, 140, 85, 140);
	ofSetColor(30, 45, 70);
	ofDrawRectangle(40, 149, 45, 10);



	ofSetColor(71, 32, 17);
	ofBeginShape();
	ofVertex(94, 72);
	ofVertex(163, 92);
	ofVertex(163, 128);
	ofVertex(94, 128);
	ofEndShape();

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(171, 94);
	ofVertex(202, 103);
	ofVertex(197, 141);
	ofVertex(171, 151);
	ofEndShape();

	ofSetColor(80, 59, 16);
	ofBeginShape();
	ofVertex(210, 105);
	ofVertex(240, 113);
	ofVertex(240, 235);
	ofVertex(190, 235);
	ofEndShape();

	ofSetColor(30, 45, 70);
	int c1 = 113;
	int c2 = 130;
	int c3 = 0;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5 ; i++)
		{
			ofDrawTriangle(240, c1, 240, c2, 210-c3, c1);

		}
		c1 = c1 + 25;
		c2 = c2 + 25;
		c3 = c3 + 4;
	}
	
	


	

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(94, 135);
	ofVertex(114, 135);
	ofVertex(114, 195);
	ofVertex(94, 195);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(121, 135);
	ofVertex(142, 135);
	ofVertex(142, 266);
	ofVertex(121, 266);
	ofEndShape();

	ofSetColor(85,67,35);
	ofDrawCircle(133, 164,5);
	ofDrawCircle(133, 194, 5);
	ofDrawCircle(133, 224, 5);


	ofSetColor(100, 95, 13);
	ofBeginShape();
	ofVertex(148, 135);
	ofVertex(163, 135);
	ofVertex(163, 153);
	ofVertex(148, 159);
	ofEndShape();

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(148, 168);
	ofVertex(199, 152);
	ofVertex(182, 236);
	ofVertex(148, 236);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(40, 202);
	ofVertex(59, 202);
	ofVertex(80, 322);
	ofVertex(40, 335);
	ofEndShape();

	ofSetColor(85, 67, 35);
	int c4 = 210;
	int c5 = 223;
	int c6 = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++)
		{
			ofDrawTriangle(40, c4, 40, c5, 61+c6,c4 );

		}
		c4 = c4 + 56;
		c5 = c5 + 56;
		c6 = c6 + 9;
	}

	ofSetColor(100, 95, 13);
	ofBeginShape();
	ofVertex(68, 202);
	ofVertex(113, 202);
	ofVertex(113, 265);
	ofVertex(78, 265);
	ofEndShape();

	ofSetColor(100, 95, 13);
	ofBeginShape();
	ofVertex(68, 202);
	ofVertex(113, 202);
	ofVertex(113, 265);
	ofVertex(78, 265);
	ofEndShape();

	ofSetColor(71, 32, 17);
	ofBeginShape();
	ofVertex(80, 273);
	ofVertex(126, 273);
	ofVertex(126, 308);
	ofVertex(89, 320);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(133, 273);
	ofVertex(167, 273);
	ofVertex(176, 354);
	ofVertex(133, 354);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(149, 243);
	ofVertex(165, 243);
	ofVertex(167, 267);
	ofVertex(149, 267);
	ofEndShape();
	
	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(172, 243);
	ofVertex(202, 243);
	ofVertex(202, 354);
	ofVertex(184, 354);
	ofEndShape();

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(208, 243);
	ofVertex(240, 243);
	ofVertex(240, 436);
	ofVertex(208, 436);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(104, 363);
	ofVertex(145, 363);
	ofVertex(145, 394);
	ofVertex(100, 379);
	ofEndShape();

	ofSetColor(100, 95, 13);
	ofBeginShape();
	ofVertex(153, 363);
	ofVertex(199, 363);
	ofVertex(199, 436);
	ofVertex(153, 436);
	ofEndShape();



	ofSetColor(100, 95, 13);
	ofBeginShape();
	ofVertex(153, 363);
	ofVertex(199, 363);
	ofVertex(199, 436);
	ofVertex(153, 436);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofDrawCircle(175, 385, 5);
	ofDrawCircle(175, 405, 10);



	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(40, 343);
	ofVertex(107, 323);
	ofVertex(91, 377);
	ofVertex(40, 361);
	ofEndShape();

	
	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(119, 329);
	ofVertex(129, 316);
	ofVertex(129, 353);
	ofVertex(110, 353);
	ofEndShape();

	ofSetColor(100, 95, 13);
	ofBeginShape();
	ofVertex(40, 369);
	ofVertex(62, 375);
	ofVertex(62, 603);
	ofVertex(40, 597);
	ofEndShape();

	ofSetColor(30, 45, 70);
	int c = 385;

	for (int j = 0; j < 7; j++){

		
		for (int i = 0; i < 8; i++) {
			ofDrawLine(40,c+i,62,c+7+i);
		}
		c = c + 30;
	}



	ofSetColor(80, 59, 16);
	ofBeginShape();
	ofVertex(70, 376);
	ofVertex(129, 396);
	ofVertex(120, 461);
	ofVertex(70, 461);
	ofEndShape();

	ofSetColor(71, 32, 17);
	ofBeginShape();
	ofVertex(134, 400);
	ofVertex(145, 403);
	ofVertex(145, 436);
	ofVertex(129, 436);
	ofEndShape();

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(177, 453);
	ofVertex(240, 453);
	ofVertex(240, 523);
	ofVertex(177, 523);
	ofEndShape();

	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(131, 453);
	ofVertex(168, 453);
	ofVertex(168, 564);
	ofVertex(118, 547);
	ofEndShape();

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(70, 479);
	ofVertex(84, 479);
	ofVertex(94, 579);
	ofVertex(70, 583);
	ofEndShape();

	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(92, 479);
	ofVertex(119, 479);
	ofVertex(110, 544);
	ofVertex(99, 540);
	ofEndShape();

	ofSetColor(85.5, 67.8, 35.7);
	ofBeginShape();
	ofVertex(99, 549);
	ofVertex(131, 559);
	ofVertex(131, 575);
	ofVertex(103, 578);
	ofEndShape();

	ofSetColor(71, 32, 17);
	ofBeginShape();
	ofVertex(176, 530);
	ofVertex(218, 530);
	ofVertex(210, 577);
	ofVertex(176, 566);
	ofEndShape();

	ofSetColor(71, 32, 17);
	ofBeginShape();
	ofVertex(70, 590);
	ofVertex(131, 584);
	ofVertex(131, 625);
	ofVertex(70, 607);
	ofEndShape();
		
	ofSetColor(30, 45, 70);
	ofBeginShape();
	ofVertex(139, 561);
	ofVertex(210, 586);
	ofVertex(200, 647);
	ofVertex(139, 628);
	ofEndShape();


	ofSetColor(51, 55, 62);
	ofBeginShape();
	ofVertex(226, 530);
	ofVertex(240, 530);
	ofVertex(240, 658);
	ofVertex(209, 649);
	ofEndShape();

}
