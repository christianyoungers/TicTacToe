#ifndef TTT_WORLD
#define TTT_WORLD

#include "headers.h"

class TTTWorld
{
public:
     TTTWorld();
     ~TTTWorld();
     void whiteOut();
     void explode();
     void events();
     void logic();
     void render();
     bool threeInARow(int& xs, int& ys, int& xf, int& yf);
     void drawWinLine(int xs, int ys, int xf, int yf);
     bool isRunning() { return m_isRunning; }   
      
private:     
     bool       m_isRunning;
     SDL_Event  m_event;
     Block*     m_blocks[XDIM][YDIM];
     PlayerOne* m_playersOne[XDIM][YDIM];
     PlayerTwo* m_playersTwo[XDIM][YDIM];
     bool       m_leftClick;
     int        m_xClick;
     int        m_yClick;
     bool       m_p1Turn;
     bool       m_p2Turn;
     
};

#endif
