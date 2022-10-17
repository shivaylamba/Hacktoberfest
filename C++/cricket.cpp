#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c = 0, d = 0;
    int coin;
    int x, run_player = 0;
    int run_comp = 0;
    int toss;
    int choice;
    int innings = 0;
    int count_ball1 = 0;
    int count_ball2 = 0;
    int count_over1 = 0;
    int count_over2 = 0;
    int over;
    cout << "Let's Play\n";
    cout << "Decide number of overs in match\n";
    cout << "Enter the number of overs\n";
    cin >> over;
    cout << "The Game will be of : " << over << " Overs\n";
    cout << "Toss Time\n";
    cout << "Choose Head or Tail\n";
    cout << "For Head Enter 1\n";
    cout << "For Tail Enter 2\n";
    cin >> coin;
    toss = rand() % (2 + 1 - 1) + 1;
    if (toss == coin)
    {
        cout << "You Won the Toss!!!!!!\n";
        cout << "What you Want to do first\n";
        cout << "For bating Enter 1\n";
        cout << "For bowling Enter 2\n";
        cin >> choice;
    }
    else
    {
        cout << "Computer Won the Toss!!!!!!\n";
        choice = rand() % (2 + 1 - 1) + 1;
    }
    switch (choice)
    {
    case 1:
    second_innings1:
        innings++;
        if (innings == 1)
        {
            if (toss == coin)
            {
                cout << "You choose to Bat First\n";
            }
            else
                cout << "Computer choose to Bowl First\n";
        }
        else
        {
            if (toss == coin)
            {
                cout << endl
                     << endl;
                cout << endl
                     << endl;
                cout << endl
                     << endl;
                cout << "Now You have to bat\n";
            }
            else
                cout << endl
                     << endl;
            cout << endl
                 << endl;
            cout << endl
                 << endl;
            cout << "Now Computer will bowl\n";
        }
        while (d == 0)
        {
            cout << "Decide The shot you want to play\n";
            cout << "1-Drive\n";
            cout << "2-Flick\n";
            cout << "3-Cut\n";
            cout << "4-Square_drive\n";
            cout << "5-Sweep\n";
            count_ball1++;
            cin >> a;
            system("cls");
            b = rand() % (5 + 1 - 1) + 1;
            if (a == b)
            {
                cout << "OUT!\n";
                d = 1;
                if (innings == 1)
                {
                    cout << "Target Given To Computer is : " << run_player << " Runs" << endl;
                }
                if (innings == 2)
                {
                    cout << "You Lost the Game by : " << run_comp - run_player << " Runs" << endl;
                }
            }
            if (a != b)
            {
                x = rand() % (5 + 1 - 0) + 0;
                if (x == 0)
                {
                    run_player = run_player + 0;
                    cout << "Dot Ball\n";
                    cout << "Run : " << run_player << endl;
                }
                if (x == 1)
                {
                    run_player = run_player + 1;
                    cout << "single\n";
                    cout << "Run : " << run_player << endl;
                }
                if (x == 2)
                {
                    run_player = run_player + 2;
                    cout << "Double\n";
                    cout << "Run : " << run_player << endl;
                }
                if (x == 3)
                {
                    run_player = run_player + 3;
                    cout << "Triple\n";
                    cout << "Run : " << run_player << endl;
                }
                if (x == 4)
                {
                    run_player = run_player + 4;
                    cout << "Boundary\n";
                    cout << "Run : " << run_player << endl;
                }
                if (x == 5)
                {
                    run_player = run_player + 6;
                    cout << "INTO THE CROWD\n";
                    cout << "Run : " << run_player << endl;
                }
                if (count_ball1 == 6)
                {
                    count_over1++;
                    count_ball1 = 0;
                }
                cout << "Number of balls : " << count_over1 << " over " << count_ball1 << " ball" << endl;
                if (over == count_over1)
                {
                    if (innings == 1)
                    {
                        cout << "innings ended\n";
                        goto second_innings2;
                    }
                    if (innings == 2)
                    {
                        if (run_player < run_comp)
                        {
                            cout << "You lost the game";
                            goto end;
                        }
                        if (run_player = run_comp)
                        {
                            cout << "Match Draw!!!";
                        }
                        else
                        {
                            cout << "You Won the Match!!!\n";
                            goto end;
                        }
                    }
                }

                if (innings == 2)
                {
                    if (run_player > run_comp)
                    {
                        cout << "You Won the Match!!!\n";
                        goto end;
                    }
                }
            }
        }

        if (innings == 1)
        {
            goto second_innings2;
        }
        break;
    case 2:
    second_innings2:
        innings++;
        if (innings == 1)
        {
            if (toss == coin)
            {
                cout << "You choose to Bowl First\n";
            }
            else
                cout << "Computer choose to Bat First\n";
        }
        else
        {
            if (toss == coin)
            {
                cout << endl
                     << endl;
                cout << endl
                     << endl;
                cout << endl
                     << endl;
                cout << "Now You have to bowl\n";
            }
            else
                cout << endl
                     << endl;
            cout << endl
                 << endl;
            cout << endl
                 << endl;
            cout << "Now Computer will bat\n";
        }
        while (c == 0)
        {
            count_ball2++;
            cout << "choose the ball you want to throw\n";
            cout << "1-Spin\n";
            cout << "2-Swing\n";
            cout << "3-Yorker\n";
            cout << "4-Short-pitch\n";
            cout << "5-Full-length\n";
            cin >> a;
            system("cls");
            b = rand() % (5 + 1 - 1) + 1;
            if (a == b)
            {
                cout << "OUT!\n";
                c = 1;
                if (innings == 1)
                {
                    cout << "Target Given By Computer is : " << run_comp << " Runs" << endl;
                }
                if (innings == 2)
                {
                    cout << "Computer Loses the Game by : " << run_player - run_comp << " Runs" << endl;
                }
            }
            if (a != b)
            {
                x = rand() % (5 + 1 - 0) + 0;
                if (x == 0)
                {
                    run_comp = run_comp + 0;
                    cout << "Dot Ball\n";
                    cout << "Run : " << run_comp << endl;
                }
                if (x == 1)
                {
                    run_comp = run_comp + 1;
                    cout << "single\n";
                    cout << "Run : " << run_comp << endl;
                }
                if (x == 2)
                {
                    run_comp = run_comp + 2;
                    cout << "Double\n";
                    cout << "Run : " << run_comp << endl;
                }
                if (x == 3)
                {
                    run_comp = run_comp + 3;
                    cout << "Triple\n";
                    cout << "Run : " << run_comp << endl;
                }
                if (x == 4)
                {
                    run_comp = run_comp + 4;
                    cout << "Boundary\n";
                    cout << "Run : " << run_comp << endl;
                }
                if (x == 5)
                {
                    run_comp = run_comp + 6;
                    cout << "INTO THE CROWD\n";
                    cout << "Run : " << run_comp << endl;
                }
                if (count_ball2 == 6)
                {
                    count_over2++;
                    count_ball2 = 0;
                }
                cout << "Number of balls : " << count_over2 << " over " << count_ball2 << " ball" << endl;
                if (over == count_over2)
                {
                    if (innings == 1)
                    {
                        cout << "innings ended\n";
                        goto second_innings1;
                    }
                    if (innings == 2)
                    {
                        if (run_player > run_comp)
                        {
                            cout << "Computer loses the game\n";
                            goto end;
                        }
                        if (run_player = run_comp)
                        {
                            cout << "Match Draw!!!";
                        }
                        else
                        {
                            cout << "Computer Wins the Match!!!\n";
                            goto end;
                        }
                    }
                }
                if (innings == 2)
                {
                    if (run_comp > run_player)
                    {
                        cout << "Computer Wins the Match!!!\n";
                        goto end;
                    }
                }
            }
        }
        if (innings == 1)
        {
            goto second_innings1;
        }
        break;
    default:
        break;
    }
end:
    cout << "GAME OVER!!!";
    return 0;
}
