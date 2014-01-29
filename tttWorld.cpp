#include "headers.h"   

TTTWorld::TTTWorld()
     : m_isRunning(true), m_leftClick(false), m_p1Turn(true), m_p2Turn(false)
{
     //create 2D array of blocks
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	  {
	       m_blocks[i][j] = new Block(i, j);
	       m_playersOne[i][j] = new PlayerOne(i, j);
	       m_playersTwo[i][j] = new PlayerTwo(i, j);
	  }
}

TTTWorld::~TTTWorld()
{
     //delete all blocks
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	  { 
	       delete m_blocks[i][j];
	       delete m_playersOne[i][j];
	       delete m_playersTwo[i][j];
	  }
}

void TTTWorld::whiteOut()
{
     //make all blocks white
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	       m_blocks[i][j]->white();
}

void TTTWorld::explode()
{
     //turn off all blocks
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	       m_blocks[i][j]->turnOff();
}

void TTTWorld::events()
{
     //EVENTS
     while ( SDL_PollEvent(&m_event) )
     {
	  //exit button at top of window
	  if ( m_event.type == SDL_QUIT )
	       m_isRunning = false;

	  if ( m_event.type == SDL_KEYUP )
	  {
	       switch ( m_event.key.keysym.sym )
	       {
	       case SDLK_ESCAPE:
		    m_isRunning = false;
		    break;

	       }
	  } 

	  //if mouse left clicked, record data
 	  if ( m_event.type == SDL_MOUSEBUTTONDOWN && 
	       m_event.button.button == SDL_BUTTON_LEFT )
	  {
	       m_leftClick = true;
	       m_xClick = m_event.button.x / BLOCKDIM;
	       m_yClick = m_event.button.y / BLOCKDIM;
	  }
     }
}

void TTTWorld::logic()
{
     if ( m_leftClick )
     {
	  if ( ! m_playersOne[m_xClick][m_yClick]->isOn() &&
	       ! m_playersTwo[m_xClick][m_yClick]->isOn() ) 
	  {
	       if ( m_p1Turn )
	       {
		    m_playersOne[m_xClick][m_yClick]->turnOn();

		    //change turns
		    m_p1Turn = false;
		    m_p2Turn = true;
		    m_leftClick = false;
	       }
	       else if ( m_p2Turn )
	       {
		    m_playersTwo[m_xClick][m_yClick]->turnOn();

		    //change turns
		    m_p1Turn = true;
		    m_p2Turn = false;
		    m_leftClick = false;
	       }
	  }
     }
}

void TTTWorld::render()
{
     //RENDERING to the screen
     glClear(GL_COLOR_BUFFER_BIT);
     glPushMatrix(); //start phase
     glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix
 
     //draw all of the blocks and players
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	  {
	       m_blocks[i][j]->draw();
	       m_playersOne[i][j]->draw();
	       m_playersTwo[i][j]->draw();
	  }

     glPopMatrix();  //end phase

     SDL_GL_SwapBuffers();
}

bool TTTWorld::threeInARow(int& xs, int& ys, int& xf, int& yf)
{
//Start here
//     for ( int i = 0; i < XDIM; i++ )
	 
	       
}
