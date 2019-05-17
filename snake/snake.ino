#include <MeggyJrSimple.h>

int x, y;
int xapple = random(8);
int yapple = random(8);
int direction = 0; 

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
  Direction();
  Spawn();
  EatApple();
  DisplaySlate();
  delay(150);
  ClearSlate();
}
  
void DrawPlayer()
{
  DrawPx(x, y, 1);
}

void MovePlayer()
{
  CheckButtonsPress();
  if(Button_Up)
  {
    direction = 0; 
  }
  if(Button_Right)
  {
    direction = 1;
  }
  if(Button_Down)
  {
    direction = 2;
  }
  if(Button_Left)
  {
    direction = 3;
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
  if(x == xapple && y == yapple)
  {
    Tone_Start(1900, 100);
    gotApple = true;
  }
}

void Direction()
{
  if(direction == 0)
  {
    if(y<7)
    {
      y++;
    }
    else
    {
      y=0;
    }
  }
  if(direction == 2)
  {
    if(y>0)
    {
      y--;
    }
    else
    {
      y=7;
    }
  }
  if(direction == 1)
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
  if(direction == 3)
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
}
