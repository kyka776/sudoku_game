#include <iostream>
using namespace std;
 
class SudokuSolver 
{
private:
    int grid[81];
 
public:
    SudokuSolver(string s) 
	{
		unsigned int i;
        for (i = 0; i < s.length(); i++) 
		{
            grid[i] = (int) (s[i] - '0');
        }
    }
 
    void solve() 
	{
        try 
		{
            placeNumber(0);
            cout << "Unsolvable!" << endl;
        } 
		catch (char* ex) 
		{
            cout << ex << endl;
            cout << this->print() << endl;
        }
    }
 
    void placeNumber(int pos) 
	{
		int n;
        if (pos == 81) 
		{
            throw (char*) "Finished!";
        }
        if (grid[pos] > 0) 
		{
            placeNumber(pos + 1);
            return;
        }
        for (n = 1; n <= 9; n++) 
		{
            if (checkValidity(n, pos % 9, pos / 9)) 
			{
                grid[pos] = n;
                placeNumber(pos + 1);
                grid[pos] = 0;
            }
        }
    }
 
    bool checkValidity(int val, int x, int y) 
	{
		int i, j;
        for (i = 0; i < 9; i++) 
		{
            if (grid[y * 9 + i] == val || grid[i * 9 + x] == val)
            {
                return false;
			}
        }
        int startX = (x / 3) * 3;
        int startY = (y / 3) * 3;
        for (i = startY; i < startY + 3; i++) 
		{
            for (j = startX; j < startX + 3; j++) 
			{
                if (grid[i * 9 + j] == val)
                {
                    return false;
            	}
			}
        }
        return true;
    }
 
    string print() 
	{
        string sb;
        int i, j;
        for (i = 0; i < 9; i++) 
		{
            for (j = 0; j < 9; j++) 
			{
                char c[2];
                c[0] = grid[i * 9 + j] + '0';
                c[1] = '\0';
                sb.append(c);
                sb.append(" ");
                if (j == 2 || j == 5)
                {
                    sb.append("| ");
                }
            }
            sb.append("\n");
            if (i == 2 || i == 5)
            {
                sb.append("------+-------+------\n");
            }
        }
        return sb;
    }
 
};
 
int main() 
{
	string s1, s;
	int q;
	for(q = 1; q < 10; q++)
	{
		cout << "Enter " << q << " string " << endl;
		cin >> s1;
		if(s1.size() == 9)
		{
			s.append(s1);
		}
		else 	
		{
			q--;
		}
		s1.clear();
	}
    SudokuSolver ss(s);
    ss.solve();
}
