#include <iostream>
using namespace std;

char board[8][8];

bool empty()
{
	int i, j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (board[i][j] != '.')
				return false;
	return true;
}

bool color(char a)
{
	if (a >= 97 && a <= 122 || a >= 65 && a <= 90) return true;
	return false;
}

bool within(int i, int j)
{
	if (i < 0 || i > 7 || j < 0 || j > 7)
		return false;
	return true;
}

bool check(int x, int y, int c)
{
	int b[8][2] = {{-1,-1},{-1,1},{1,1},{1,-1}},
		n[8][2] = {{-2,-1},{-1,-2},{2,-1},{1,-2},{2,1},{1,2},{-2,1},{-1,2}},
		r[4][2] = {{-1,0},{0,-1},{1,0},{0,1}},
		p[2][2], lf, bi, bj, ni, nj, ri, rj, pi, pj, k;
		
	if (c)
	{ 
		lf = 32;
		p[0][0] = -1, p[0][1] = -1, p[1][0] = -1, p[1][1] = 1;
	}
	else 
	{
		lf = 0;
		p[0][0] = 1, p[0][1] = -1, p[1][0] = 1, p[1][1] = 1;
	}

	for (k = 0; k < 8; k++)
	{
		ni = x+n[k][0], nj = y+n[k][1];
		if (board[ni][nj] == 'N'+lf && within(ni, nj))
			return true;
	}
	for (k = 0; k < 4; k++)
	{
		bi = x, bj = y;
		while (!color(board[bi][bj]) && within(bi, bj))
			bi+=b[k][0], bj+=b[k][1];
		if (board[bi][bj] == 'B'+lf || board[bi][bj] == 'Q'+lf)
			return true;
		ri = x, rj = y;
		while (!color(board[ri][rj]) && within(ri, rj))
			ri+=r[k][0], rj+=r[k][1];
		if (board[ri][rj] == 'R'+lf || board[ri][rj] == 'Q'+lf)
			return true;
	}
	for (k = 0; k < 2; k++)
	{
		pi = x+p[k][0], pj = y+p[k][1];
		if (board[pi][pj] == 'P'+lf && within(pi, pj))
			return true;
	}
	return false;
}

int main()
{
	int i, j, bi, bj, wi, wj, g = 0;
	bool b, w;
	while (true)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'k')
					bi = i, bj = j, board[i][j] = '#';
				if (board[i][j] == 'K')
					wi = i, wj = j, board[i][j] = '#';
			}
		}
		if (empty()) return 0;
		b = false, w = false;
		if (check(wi,wj,1)) w = true;
		else if (check(bi,bj,0)) b = true;

		g++;
		if (b) cout << "Game #" << g << ": black king is in check.";
		else if (w) cout << "Game #" << g << ": white king is in check.";
		else cout << "Game #" << g << ": no king is in check.";
		cout << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
