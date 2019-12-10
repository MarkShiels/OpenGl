#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{

}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{

	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		glScalef(1.0f, 1.0f, 1.0005f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::E))
	{
		glScalef(1.0f, 1.0f, 0.9995f);
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		glTranslatef(-0.002f, 0.0f, 0.0f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		glTranslatef(0.002f, 0.0f, 0.0f);
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		glTranslatef(0.0f, 0.002f, 0.0f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		glTranslatef(0.0f, -0.002f, 0.0f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		glRotatef(0.02, 0.0f, 0.0f, 0.02f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::X))
	{
		glRotatef(-0.02, 0.0f, 0.0f, -0.02f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		glLoadIdentity();
	}

	//glRotatef(0.02, 0.0f, 0.0f , 0.02f);
	//glTranslatef(-0.00002f, 0.0f, 0.0f);
	//glScalef(1.0f, 1.0f, 1.0f);
}

void Game::draw()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	/*glBegin(GL_TRIANGLES); 
	{	glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0); 
	}	
	glEnd(); */


	glBegin(GL_TRIANGLES);
	{	glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();

	window.display(); 



}

void Game::unload()
{

}

