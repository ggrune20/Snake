#include <MeggyJrSimple.h>

int x, y;
int xapple = random(8);
int yapple = random(8);

boolean gotApple = false;


void setup() 
{
  MeggyJrSimpleSetup();
  x=2;
  y=2;
}


void loop()
{
  DrawPlayer();
  MovePlayer();
  Spawn();
  EatApple();
  DisplaySlate();
  ClearSlate();
}
  
void DrawPlayer()
{
  DrawPx(x, y, 1);
}

void MovePlayer()
{
  CheckButtonsPress();
  if(Button_Left)
  {
    if(x>0)
    {
      x--;
    }
    else
    {
      x = 7;
    }
  }
  if(Button_Right)
  {
    if(x<7)
    {
      x++;
    }
    else
    {
      x = 0;
    }
  }
  if(Button_Up)
  {
    if(y<7)
    {
      y++;
    }
    else
    {
      y = 0;
    }
  }
  if(Button_Down)
  {
    if(y>0)
    {
      y--;
    }
    else
    {
      y = 7;
    }
  }
}


void Spawn()
{
    DrawPx(xapple, yapple, Green);
}


void EatApple()
{
  if(gotApple == true)
  {
    xapple = random(8);
    yapple = random(8);
    gotApple = false;
  }
  if(x == xapple and y == yapple)
  {
    Tone_Start(1900, 100);
    gotApple = true;
  }
}
