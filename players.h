#ifndef PLAYERS
#define PLAYERS

class Player
{
public:
     Player(int xCoord, int yCoord);     
     virtual void draw() = 0;
     bool isOn() { return m_on; }   
     void turnOn() { m_on = true; }     
     int xCoord() { return m_xCoord; }
     int yCoord() { return m_yCoord; }
     
private:    
     bool m_on;
     int m_xCoord;
     int m_yCoord;
     
};

////////////////////////////////////////////////////////////

class PlayerOne : public Player
{
public:
     PlayerOne(int xCoord, int yCoord);
     void draw();
      
private:    

};

////////////////////////////////////////////////////////////  

class PlayerTwo : public Player
{
public:
     PlayerTwo(int xCoord, int yCoord);
     void draw();
      
private:    

};

 #endif 
