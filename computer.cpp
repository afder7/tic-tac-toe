#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//in this vector 1 means x = player, -1 means o = computer, 0 = empty
vector<int> field = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void print_field(vector<int> pfield) {
	vector<char> pr_field;
	for (int i = 0; i < 9; i++) {
		if (pfield[i] == 1)
			pr_field.push_back('x');
		else if (pfield[i] == -1)
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

	print_field(field);
}

int check_win(vector<int> pfield)
{
	int r1 = pfield[0] + pfield[1] + pfield[2];
	int r2 = pfield[3] + pfield[4] + pfield[5];
	int r3 = pfield[6] + pfield[7] + pfield[8];

	int s1 = pfield[0] + pfield[3] + pfield[6];
	int s2 = pfield[1] + pfield[4] + pfield[7];
	int s3 = pfield[2] + pfield[5] + pfield[8];

	int d1 = pfield[0] + pfield[4] + pfield[8];
	int d2 = pfield[2] + pfield[4] + pfield[6];

	if (r1 == 3 || r2 == 3 || r3 == 3 || s1 == 3 || s2 == 3 || s3 == 3 || d1 == 3 || d2 == 3)
		return 1;
	else if (r1 == -3 || r2 == -3 || r3 == -3 || s1 == -3 || s2 == -3 || s3 == -3 || d1 == -3 || d2 == -3)
		return -1;
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


int evaluate(vector<int> new_field)
{
	if (check_win(new_field) == 1)
		return 10;
	else if (check_win(new_field) == -1)
		return -10;
	else
		return 0;
}

int count(vector<int> pf, int n)
{
	int re = 0;
	for (int i = 0; i < pf.size(); i++)
		re += (pf[i] == n);
	return re;
}

int minimax(vector<int> new_field, int depth, int player)
{
	int score = evaluate(new_field);

	if (score)
	{
		print_field(new_field);
		cout << player << " " << score << "\n";
		return score;
	}

	if (count(new_field, 0) == 0)
		return 0;


	if (player > 0)
	{
		int best = -1000;
		for (int i = 0; i < 9; i++)
		{
			if (new_field[i] == 0)
			{
				new_field[i] = player;

				best = max(best, minimax(new_field, depth + 1, -1 * player));

				new_field[i] = 0;
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i < 9; i++)
		{
			if (new_field[i] == 0)
			{
				new_field[i] = player;

				best = min(best, minimax(new_field, depth + 1, -1 * player));

				new_field[i] = 0;
			}
		}
		return best;
	}

	return 0;
}

void computer_move()
{
	int best = -1000;
	int best_move = 1;
	for (int i = 0; i < 9; i++)
	{
		int cur = minimax(field, 0, -1);
		cout << cur << " for " << i << "\n";
		if (cur >= best)
		{
			best_move = i;
		}
	}

	field[best_move] = -1;
}

int main()
{
	setup();
	
	field = {-1, -1, 0, 0, 0, 0, 0, 0, 0};
	print_field(field);
	cout << "\n" << check_win(field);

	computer_move();

	cout << "yo\n";

	print_field(field);


	/*int cur_player = 1;
	while (!check_win(field))
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
		cout << "Player o wins!";*/

	return 0;
}
