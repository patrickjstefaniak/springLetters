#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "particleController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class springLettersApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
    void mouseMove( MouseEvent event ) override;
    void keyDown  ( KeyEvent   event ) override;
	void update() override;
	void draw() override;
    
    particleController  pc;
    float                 glp;
};

void springLettersApp::setup()
{
    setWindowSize(800, 600);
    Font arial( "Bodoni 72", 400 );
    glp = 4 ;
    Shape2d sha = arial.getGlyphShape(glp);
    pc = particleController(sha);
}

void springLettersApp::mouseDown( MouseEvent event )
{
    pc.mouseClick(event.getPos());
}

void springLettersApp::mouseDrag(MouseEvent event)
{
    pc.mouseDrag(event.getPos());
}

void springLettersApp::mouseMove(MouseEvent event)
{
    mouseDrag(event);
}

void springLettersApp::keyDown(KeyEvent event){
    glp++;
    Font arial( "Bodoni 72", 400 );
    Shape2d sha = arial.getGlyphShape(glp);
    pc = particleController(sha);
}

void springLettersApp::update()
{
    pc.update();
}



void springLettersApp::draw()
{
	gl::clear( Color( .4, .4, .4 ) );
    
    pc.draw();
}

CINDER_APP( springLettersApp, RendererGl )
