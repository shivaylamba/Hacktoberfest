//Age Calculator
//----------------------------------------------------------------------------------------

// Header files
#include <iostream.h>
#include <conio.h>

// main function
void main()
{
  clrscr();
  char ch;
  int d1, d2, m1, m2, y1, y2;
  do
  {
    clrscr();
    for (int i = 0; i < 40; i++)
      cout << "--";
    cout << "\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 AGE - Calculator \xB3-\xB2=\xB2=\xB2\xB3\n\n";
    for (i = 0; i < 40; i++)
      cout << "--";
    cout << "\n\tEnter Your Date of Birth <  > :-\n ";
    cout << "\tDay: ";
    cin >> d1;
    cout << "\tMonth: ";
    cin >> m1;
    cout << "\tYear: ";
    cin >> y1;
    cout << "\n\tEnter Today's Date:-\n\t";
    cout << "Day: ";
    cin >> d2;
    cout << "\tMonth: ";
    cin >> m2;
    cout << "\tYear: ";
    cin >> y2;
    if (d2 >= d1)
      d2 -= d1;
    else
    {
      m2--;
      d2 += 30;
      d2 -= d1;
    }
    if (m2 >= m1)
      m2 -= m1;
    else
    {
      y2--;
      m2 += 12;
      m2 -= m1;
    }
    y2 -= y1;
    cout << "\n\tYour Present Age :-\n";
    cout << "\t\t" << y2 << " Years \t";
    cout << m2 << " Months \t";
    cout << d2 << " Days";
    cout << "\n\n Do You Want to continue ? (y/n): ";
    cin >> ch;
  } while (ch == 'y');
  getch();
}
