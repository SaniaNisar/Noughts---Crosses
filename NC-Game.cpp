#include<iostream>
#include<conio.h>  // getch() 
#include<fstream>
#include<Windows.h>  // getch() clrscr()
#include<string>
#include<vector>
#include<time.h>  
#include<cstring>


using namespace std;
void HideCursor()
{
    HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO idk;
    idk.dwSize = 1;
    idk.bVisible = FALSE;
    SetConsoleCursorInfo(cursor, &idk);
}
int live = 8;
int lost = 1;

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD axis;
    axis.X = x;
    axis.Y = y;
    SetConsoleCursorPosition(handle, axis);
}
void Lives()
{
    gotoxy(21, 2);
    cout << live-- << endl;
}

void Output(string text)
{
    bool flag = true;
    for (int i = text.length(); i < 33; i++) // returns the length of string similar to size()
    {
        if (flag)
        {
            text = " " + text;
        }
        else
        {
            text = text + " ";
        }
        flag = !flag;
    }
    cout << text.c_str() << endl; // Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.

    //same sequence of characters that make up the value of the string plus an additional  ('\0') at the end.

}
string GetInput(string demofile)
{
    vector<string> check;
    string word = "";
    int line;

    ifstream fin("demo.txt");
    if (fin.is_open())
    {
        while (std::getline(fin, word))
            check.push_back(word); //to add new thing at the end

        line = rand() % check.size();
        word = check.at(line);

        fin.close();
    }
    Lives();
    return word;
}
bool Print(string word, string user_guess)
{
    bool victory = true;
    string star;
    int chck = word.length();
    int count = 0;

    for (int i = 0; i < word.length(); i++)
    {

        if (user_guess.find(word[i]) == string::npos) //value for a length parameter in the strings member functions.
        {
            victory = false;
            star += "_ ";
        }
        else
        {
            star += word[i];
            star += " ";
            count++;
        }
    }
    if (count == 0)
    {
        lost++;
    }

    Lives();

    Output(star);

    return victory;
}

void WelcomeMessage()
{
    char ch;
    int x = 30;
    int y = 10;
    gotoxy(x, y);
    system("Color 0E");
    cout << "      ___                                       ";
    gotoxy(x + 6, y + 1);
    cout << "| |____   ___  ___  ___     ___  ___  _____   _ __ ";
    gotoxy(x + 6, y + 2);
    cout << "|  __  | | o | |  ||  __   |  |_|  | |  o  | | |--|";
    gotoxy(x + 6, y + 3);
    cout << "|__| |_| |_|_| |  ||____|  |       | |_| |_| |_|  |   ";
    gotoxy(x + 6, y + 4);
    cout << "      ";
    gotoxy(x, y + 6);
    cout << "                 Press '1' to play game" << endl;
    cout << "                                             Press '2' to see instructions" << endl;
    cout << "                                               Press '0' to exit game" << endl;
    ch = _getch();
    if (ch == '1')
    {
       /* Lives();*/
    }

    if (ch == '2')
    {
        system("cls");
        system("Color 06");
        gotoxy(45, 8);
        cout << " I N S T R U C T I O N S :" << endl;
        cout << endl;
        cout << endl;

        cout << "                                   (1)  The word to be guessed is in demo file" << endl;
        cout << "                                   (2)  You have 7 turns in order to reach the word" << endl;
        cout << "                                   (3)  Play and enjoy." << endl;
        cout << endl;
        cout << endl;
        cout << "                                           Press '1' to play game" << endl;
        cout << "                                           Press '0' or any key to exit game" << endl;
        ch = _getch();

        if (ch == '1')
        {
            /*Lives();*/
        }
        if (ch == '0')
        {
            exit(0);
        }
    }
    if (ch == '0')
    {
        exit(0);
    }
}

int main()
{
    HideCursor();
    WelcomeMessage();

    srand(time(0));   // initialize the random number generator
    Sleep(40);


    string guessing;
    string Guess;
    Guess = GetInput("demo.txt");
    bool won = false;
    int ch = 8;


    do
    {
        system("cls");
        system("Color 4");
        Output("   Welcome to Hangman...");
        Output("   LIVES AVAILABLE:");
        cout << endl;

        won = Print(Guess, guessing);

        if (won)
            break;

        char alpha;
        cout << endl;
        cout << "Enter your GUESS : ";
        cin >> alpha;
        ch--;
        guessing += alpha;
    } while (ch != 0);

    if (won)
        Output("Congratulations Buddy YOU WONNNNN!");
    else
        Output("GAME OVER......");
    Output("You are on your way out.....");

    return 0;
}
