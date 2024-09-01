#include<iostream>
using namespace std;
char table[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;
	void disp_table()
	{
		system("cls");
	
	cout<< "Tick-Tack-Toe GAME"<<endl;
	cout<<"\t player1 [X] \n\t player2 [O]\n\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t "<<table[0][0]<<"   |  "<<table[0][1]<<"  |   "<<table[0][2]<<"    \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t "<<table[1][0]<<"   |  "<<table[1][1]<<"  |   "<<table[1][2]<<"    \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t "<<table[2][0]<<"   |  "<<table[2][1]<<"  |   "<<table[2][2]<<"    \n";
	cout<<"\t\t     |     |     \n";
}
void player_turn()
{
	int choice;
	
	if(turn=='X')
cout<<"\n\t player1 [X] turn:";
	if(turn=='O')
cout<<"\n\t player2 [O] turn:";
	cin>>choice;
	switch(choice)
	{
		case 1: row=0; column=0; break;
		case 2: row=0; column=1; break;
		case 3: row=0; column=2; break;
		case 4: row=1; column=0; break;
		case 5: row=1; column=1; break;
		case 6: row=1; column=2; break;
		case 7: row=2; column=0; break;
		case 8: row=2; column=1; break;
		case 9: row=2; column=2; break;
	    
	    default:
	    	cout<<"invalid choice\n";
	    	break;
			
	}
	if(turn=='X' && table[row][column]!='X'&& table[row][column]!='O')
	{
		table[row][column]='X';
		turn='O';
	}
    else if(turn=='O' && table[row][column]!='X'&& table[row][column]!='O')
	{
		table[row][column]='O';
		turn='X';
	}
	else
	{
		cout<<"BOX already filled!\n Please Try Again !";
		player_turn();
	}
	disp_table();
}
bool gameover()
{
	for(int i=0;i<3;i++)
	if(table[i][0]==table[i][1] && table[i][0]==table[i][2] || table[0][i]==table[1][i] && table[0][i]==table[2][i] )
	return false;
	
	if (table[0][0]==table[1][1] && table[0][0]==table[2][2] ||  table[0][2]==table[1][1] && table[0][2]==table[2][0])
	return false;
	
	
	
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(table[i][j]!='X' && table[i][j]!='O')
	return true;
	
	draw= true;
	return false;
}
int main()
{
	int choice;
	while(gameover())   //for keep on the program
	{
	
	disp_table();
	player_turn();
	gameover();
}

if(turn=='X' && draw==false)
cout<<"Player2 [O] Wins!! Congratulation \n";

 else if(turn=='O' && draw==false)
cout<<"Player1 [X] Wins!! Congratulation \n";
else
cout<<"Game Draw !!"<<endl;
	
}
