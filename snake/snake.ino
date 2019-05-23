#include <MeggyJrSimple.h>

int xapple = random(8);
int yapple = random(8);
int direction = 3;
int marker = 1;
int ApplesEaten;

boolean gotApple = false;

struct Point
{
  int x;
  int y;
  int color;
};

Point s1 = {3, 4, 1};

Point SnakeArray[64] = {s1};


void setup() 
{
  MeggyJrSimpleSetup();
}


void loop()
{
  Spawn();
  DrawSnake();
  UpdateSnake();
  MovePlayer();
  EatApple();
  Die();
  DisplaySlate();
  delay(150);
  ClearSlate();
}

void DrawSnake() //creates snake
{
  for(int i = 0; i < marker; i++)
  {
    DrawPx(SnakeArray[i].x, SnakeArray[i].y, SnakeArray[i].color);
  }
}

void MovePlayer() //allows player to move using direction buttons
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


void Spawn() //creates original apple
{
    DrawPx(xapple, yapple, Green);
}


void EatApple() //creates new apple when apple is eaten
{
  if(gotApple == true)
  {
    xapple = random(8);
    yapple = random(8);
    marker++;
    gotApple = false;
  }
  if(SnakeArray[0].x == xapple && SnakeArray[0].y == yapple)
  {
    Tone_Start(1900, 100);
    gotApple = true;
  }
}


void UpdateSnake() //runs loop backwards
{
  for (int i = marker-1; i > 0; i--)
  {
    SnakeArray[i] = SnakeArray[i-1];
  }
  if(direction == 0)
  {
    if(SnakeArray[0].y < 7)
    {
      SnakeArray[0].y++;
    }
    else
    {
      SnakeArray[0].y = 0;
    }
  }
  if(direction == 1)
  {
    if(SnakeArray[0].x < 7)
    {
      SnakeArray[0].x++;
    }
    else
    {
      SnakeArray[0].x = 0;
    }
  }
  if(direction == 2)
  {
    if(SnakeArray[0].y > 0)
    {
      SnakeArray[0].y--;
    }
    else
    {
      SnakeArray[0].y = 7;
    }
  }
  if(direction == 3)
  {
    if(SnakeArray[0].x > 0)
    {
      SnakeArray[0].x--;
    }
    else
    {
      SnakeArray[0].x = 7;
    }
  }
}

void Die()
{
  for(int i = 1; i < marker; i++)
  {
    if(SnakeArray[0].x == SnakeArray[i].x && SnakeArray[0].y == SnakeArray[i].y)
    {
      marker = 1;
    }
  }
}
