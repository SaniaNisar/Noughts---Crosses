#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD axis;
	axis.X = x;
	axis.Y = y;
	SetConsoleCursorPosition(handle, axis);
}
void playgame()
{
	system("cls");
	char box[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int p = 1; 
	int i;
	int choice;
    char symbol;
    char str1[20];
    char str2[20];

    system("Color 06");
    cout << "\t\t\t----------WELCOME TO TIC TAC TOE-----------" << endl;
    cout<<"Enter name of Player 1: "<<endl;
    cin>>str1;
    cout<<"Enter name of Player 2: "<<endl;
    cin>>str2;
    cout<<"\t\t\t"<< str1<< " and "<< str2 <<" welcome to game \t"<<endl;
	do
	{
		cout << "\n\nPlayer 1 (X)  -  Player 2 (O)" << endl << endl;
		cout << endl;

		cout << "\t\t\t\t      |     |     " << endl;
		cout << "\t\t\t\t   " << box[1] << "  |  " << box[2] << "  |  " << box[3] << endl;

		cout << "\t\t\t\t _______" <<"  _______"<< endl;
		cout << "\t\t\t\t      |     |     " << endl;

		cout << "\t\t\t\t   " << box[4] << "  |  " << box[5] << "  |  " << box[6] << endl;

		cout << "\t\t\t\t _______" <<"  _______"<< endl;
		cout << "\t\t\t\t      |     |     " << endl;

		cout << "\t\t\t\t   " << box[7] << "  |  " << box[8] << "  |  " << box[9] << endl;

		cout << "\t\t\t\t      |     |     " << endl << endl;


		if (p % 2) {
			p = 1;
		}
		else {
			p = 2;
		}


		if (p == 1) {
			symbol = 'X';
		}
		else {
			symbol = 'O';
		}



		cout << "Player " << p << ", enter a number:  ";
		cin >> choice;


		if (choice == 1 && box[1] == '1')

			box[1] = symbol;
		else if (choice == 2 && box[2] == '2')

			box[2] = symbol;
		else if (choice == 3 && box[3] == '3')

			box[3] = symbol;
		else if (choice == 4 && box[4] == '4')

			box[4] = symbol;
		else if (choice == 5 && box[5] == '5')

			box[5] = symbol;
		else if (choice == 6 && box[6] == '6')

			box[6] = symbol;
		else if (choice == 7 && box[7] == '7')

			box[7] = symbol;
		else if (choice == 8 && box[8] == '8')

			box[8] = symbol;
		else if (choice == 9 && box[9] == '9')

			box[9] = symbol;
		else
		{
			cout << "Already entered this number , please enter again ";
			cout<<  "Enter valid number ";
		}
		//i = checkwin();
		if (box[1] == box[2] && box[2] == box[3])

			i = 1;
		else if (box[4] == box[5] && box[5] == box[6])

			i = 1;
		else if (box[7] == box[8] && box[8] == box[9])

			i = 1;
		else if (box[1] == box[4] && box[4] == box[7])

			i = 1;
		else if (box[2] == box[5] && box[5] == box[8])

			i = 1;
		else if (box[3] == box[6] && box[6] == box[9])

			i = 1;
		else if (box[1] == box[5] && box[5] == box[9])

			i = 1;
		else if (box[3] == box[5] && box[5] == box[7])

			i = 1;
		else if (box[1] != '1' && box[2] != '2' && box[3] != '3'
			&& box[4] != '4' && box[5] != '5' && box[6] != '6'
			&& box[7] != '7' && box[8] != '8' && box[9] != '9')

			i = 0;
		else
			i = -1;

		p++;
	} while (i == -1);

	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "\t\t\t\t      |     |     " << endl;
	cout << "\t\t\t\t   " << box[1] << "  |  " << box[2] << "  |  " << box[3] << endl;

	cout << "\t\t\t\t _______"<<"_______" << endl;
	cout << "\t\t\t\t      |     |     " << endl;

	cout << "\t\t\t\t   " << box[4] << "  |  " << box[5] << "  |  " << box[6] << endl;

	cout << "\t\t\t\t ______" <<"_______"<< endl;
	cout << "\t\t\t\t      |     |     " << endl;

	cout << "\t\t\t\t   " << box[7] << "  |  " << box[8] << "  |  " << box[9] << endl;

	cout << "\t\t\t\t      |     |     " << endl << endl;

	if (i == 1)

		cout << "Player " << --p << " win " << endl;
	else
		cout << "Game draw" << endl;
}
void WelcomeMessage()
{ 
	system("Color 02");
	Sleep(40);
	char ch;
	int x = 13;
	int y = 6;
	gotoxy(x+9, y);
	cout<<" ________        _______      _______       ";
	gotoxy(x+8, y + 1);
	cout<<"   |  |  0  ___    |  |___ __   |  |  __   ___";
	gotoxy(x+8, y + 2);                            
	cout<<"   |  |  | |       |  | o |     |  | |  | |___";
	gotoxy(x+8, y + 3);
	cout<<"   |__|  | |___    |__|_|_|__   |__| |__| |___ ";
	gotoxy(x+8, y + 4);
	cout<<"      ";
	gotoxy(x+8, y + 7 );
	cout<<"              Press '1' to play game"<<endl;
	cout<<"                                Press '2' to see instructions"<<endl;
	cout<<"                                   Press '0' to exit game"<<endl;
	ch = _getch();
	if (ch=='1')
	{
	  	playgame();
	}
			  
    if (ch=='2')
    {
    	system("Color 0E");
		Sleep(40);
	  	system("cls");
	  	cout<<"           I N S T R U C T I O N S :"<<endl;
	  	cout<<endl;
	  	cout<<endl;
		
		cout<<"(1)          Player one has mark x"<<endl;
		cout<<"(2)          Player one has mark 0"<<endl;
		cout<<"(3)          Play and enjoy."<<endl;
		cout<<endl;
	  	cout<<endl;
	  	cout<<"             Press '1' to play game"<<endl;
		cout<<"             Press '0' to exit game"<<endl;
		cout<<"             Press any key to exit game"<<endl;
		ch = _getch();
		
		if(ch=='1')
		{
		    playgame();
		}
	  	if(ch=='0')
		{
			exit(0);
		}
    }
	if (ch=='0')
	{
	exit(0);
	}
}

int main()
{
	WelcomeMessage();
}

