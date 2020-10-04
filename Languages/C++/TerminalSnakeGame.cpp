#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fx, fy;
int tx[100], ty[100];
int nTail;
int score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a' : dir = LEFT; break;
            case 'd' : dir = RIGHT; break;
            case 'w' : dir = UP; break;
            case 's' : dir = DOWN; break;
            case 'x' : gameOver = true; break;
        }
    }

}

void Draw()
{
    system("cls");
    for(int i = 0; i < width+2; i++)
        cout<<"#";
    cout<<endl;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0)
                cout<< "#";
            if(i == y && j == x)
                cout<<"O";
            else if(i == fy && j == fx)
                cout<<"@";
            else
            {
                bool print = false;
                for(int k = 0; k < nTail; k++)
                {
                    if(tx[k] == j && ty[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                    cout<<" ";
            }


            if(j == width - 1)
                cout<< "#";
        }
        cout<<endl;
    }

    for(int i = 0; i < width; i++)
        cout<<"#";
    cout<<endl;
    cout<<"Score: "<<score<<endl;

}

void Logic()
{
    int prevX = tx[0];
    int prevY = ty[0];
    int prev2X,prev2Y;
    tx[0] = x;
    ty[0] = y;
    for(int i = 1; i < nTail; i++)
    {
        prev2X = tx[i];
        prev2Y = ty[i];
        tx[i] = prevX;
        ty[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
        case LEFT : x--; break;
        case RIGHT : x++; break;
        case UP : y--; break;
        case DOWN : y++; break;
        default : break;
    }
    //if(x > width || x < 0 || y > height || y < 0)
        //gameOver = true;

    if(x >= width) x = 0; else if(x < 0) x = width - 1;
    if(y >= height) y = 0; else if(y < 0) y = height - 1;

    for(int i = 0; i < nTail; i++)
        if(tx[i] == x && ty[i] == y)
        gameOver = true;

    if(x == fx && y == fy)
    {
        score += 10;
        fx = rand() % width;
        fy = rand() % height;
        nTail++;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
}
