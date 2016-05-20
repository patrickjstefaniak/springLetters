#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class springLettersApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void springLettersApp::setup()
{
}

void springLettersApp::mouseDown( MouseEvent event )
{
}

void springLettersApp::update()
{
}

void springLettersApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( springLettersApp, RendererGl )
