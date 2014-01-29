#include "headers.h"

Block::Block(int xCoord, int yCoord)
     : m_xCoord(xCoord), m_yCoord(yCoord), 
       m_x(xCoord * (BLOCKDIM + LINEWIDTH)), 
       m_y(yCoord * (BLOCKDIM+LINEWIDTH)), m_dim(BLOCKDIM), m_on(true), 
       m_r(0), m_g(0), m_b(0)
{}

void Block::draw()
{ 
     if ( m_on )
     {
	  //set color based on variables
	  glColor4ub(m_r, m_g, m_b, 255);

	  //draw square
	  glBegin(GL_QUADS);
	  glVertex2f(m_x,             m_y);
	  glVertex2f(m_x + m_dim - 1, m_y);
	  glVertex2f(m_x + m_dim - 1, m_y + m_dim - 1);
	  glVertex2f(m_x,             m_y + m_dim - 1);
	  glEnd();
     }
}
