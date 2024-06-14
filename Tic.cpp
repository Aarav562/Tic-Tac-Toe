#include<iostream>
using namespace std;
const int S = 3;
char board[S][S];

void initialize_board() {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			board[i][j] = ' ';
		}
	}
}

void display_board() {
	cout << "  0   1   2 " << endl;
	for (int i = 0; i < S; i++) {
		cout << i << " ";
		for (int j = 0; j < S; j++) {
			cout << board[i][j];
			if (j < S - 1) {
				cout << " |";
			}
		}
		cout << endl;
		if (i < S - 1) {
			cout << " ----------" << endl;
		}
	}
}
bool placeMarker(int r, int c, char marker) {
	if (r >= 0 && r < S && c >= 0 && c < S && board[r][c] == ' '){
		board[r][c] = marker;
		return true;
	}
	return false;
}

bool checkWin(char marker) {
	for (int i = 0; i < S; i++) {
		if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) {
			return true;
		}
	}

	for (int i = 0; i < S; i++) {
		if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker) {
			return true;
		}
	}

	if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) {
			return true;
	}
	if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) {
		return true;
	}
	return false;
}

bool checkDraw() {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}


int main() {
	initialize_board();
	char currentMark = 'X';
	bool gameWon = false;
	while (true) {
		display_board();
		int r, c;
		cout << "Player " << currentMark << " Pick Your move from the given index: ";
		cin >> r >> c;
		if (placeMarker(r, c, currentMark)) {
			if (checkWin(currentMark)){
				display_board();
				cout<<"Player "<<currentMark<<" has won the game.";
				gameWon = true;
				break;
			}
			if (checkDraw()) {
				display_board();
				cout << "It was a draw ";
				break;
			}
			if (currentMark == 'X') {
				currentMark = 'O';
			}
			else {
				currentMark = 'X';
			}
		}
		else {
			cout << "Invalid Move! Please Try again. ";
		}

	}
	return 0;
}