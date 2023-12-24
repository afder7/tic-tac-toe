#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//in this vector 1 means x = player, -1 means o = computer, 0 = empty
vector<int> field = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void print_field() {
	vector<char> pr_field;
	for (int i = 0; i < 9; i++) {
		if (field[i] == 1)
			pr_field.push_back('x');
		else if (field[i] == -1)
			pr_field.push_back('o');
		else
			pr_field.push_back(' ');
	}

	for (int i = 0; i < 3; i++)
		cout << pr_field[i * 3] << '|' << pr_field[i * 3 + 1] << '|' << pr_field[i * 3 + 2] << "\n";
}

//setup the field
void setup()
{
	cout << "Hello! It's time to play tic-tac-toe. Make your moves by inputing the number of your move\n";
	cout << "The positions are\n";
	cout << "1|2|3\n";
	cout << "4|5|6\n";
	cout << "7|8|9\n";
	cout << "You play as x, I play as o. You are the first to make a move. Good luck!\n";
	
	print_field();
}

bool check_win()
{
	int r1 = abs(field[0] + field[1] + field[2]) == 3;
	int r2 = abs(field[3] + field[4] + field[5]) == 3;
	int r3 = abs(field[6] + field[7] + field[8]) == 3;

	int s1 = abs(field[0] + field[3] + field[6]) == 3;
	int s2 = abs(field[1] + field[4] + field[7]) == 3;
	int s3 = abs(field[2] + field[5] + field[8]) == 3;

	int d1 = abs(field[0] + field[4] + field[8]) == 3;
	int d2 = abs(field[2] + field[4] + field[6]) == 3;

	if ((r1 + r2 + r3 + s1 + s2 + s3 + d1 + d2) >= 1)
		return 1;
	else
		return 0;
}

void player_move(int player)
{
	int pos = 1;
	if (player == 1)
		cout << "Your next move, player x: ";
	else
		cout << "Your next move, player o: ";
	cin >> pos;
	while (field[pos - 1] != 0) {
		cout << "You can't make this move. Your next move: ";
		cin >> pos;
	}
	field[pos - 1] = player;
}

//pos - позиция от 1 до 9
//1 2 3
//4 5 6
//7 8 9
//function to compute all the game outcomes and determine the best possible move

/*int minimax(vector<int> new_field)
{
	return 0;
}

void computer_move()
{
	int move = minimax(field);
	field[move] = -1;
}*/

int main()
{
	setup();

	int cur_player = 1;
	while (!check_win())
	{
		player_move(cur_player);
		print_field();
		cur_player *= -1;
	}

	cur_player *= -1;
	cout << "Thank you for the game!\n";
	if (cur_player == 1)
		cout << "Player x wins!";
	else
		cout << "Player o wins!";

	return 0;
}

