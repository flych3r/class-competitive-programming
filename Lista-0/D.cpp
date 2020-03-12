#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comparator(char c)
{
  if (isalpha(c)) return false;
  return true;
}

bool isNotAlnum(char c) {
    return isalnum(c) == 0;
}

int main()
{
  map<char, int> histogram;
  
  string line;
  string::iterator it;
  for(int i = 0; i < 4; i++)
  {
    getline(cin, line);
    line.erase(remove_if(line.begin(), line.end(), comparator), line.end());
    for (it = line.begin(); it != line.end(); it++) 
      ++histogram[*it];
  }

  vector<int> counts(26);
  for(int i = 0; i < 26; i++)
    counts[i] = histogram[char('A' + i)];

  int c = *max_element(counts.begin(), counts.end());

  vector<vector<char>> matrix(c + 1);
  for(int i = 0; i < c + 1; i++)
    matrix[i] = vector<char>(52);
  
  for(int j = 0; j < 52; j++)
  {
    int k = j / 2;
    if(j % 2 == 0)
    {
      matrix[c][j] = char('A' + k);
      for(int i = c - 1; i >= 0; i--)
        if(c - counts[k] > i)
        {
          matrix[i][j] = ' ';
        }
        else
        {
          matrix[i][j] = '*';
        }
        
    }
    else
    {
      matrix[c][j] = ' ';
      for(int i = c - 1; i >= 0; i--)
        matrix[i][j] = ' ';
    }
    
  }

  for(int i = 0; i <= c; i++)
  {  
    for(int j = 0; j < 52; j++)
      cout << matrix[i][j];
    cout << endl;
  }  

  return 0;
}
