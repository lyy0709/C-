#include <iostream>
#include <cstring>
#include <new>
using namespace std;
void sort_array(char s[][31], int n);
void removing(char s[][31], int n, char ch);
int main()
{
	int i,k;
	char str1,str2[31][31]={0},ch;
	cin>>str1;
	cin.get();
	for(i=0;i<31;i++)
	{
		cin.getline(str2[i],31);
		k=i;
		if(str2[i][0]=='@')
		{
			break;
		}
	}
	removing(str2, k, str1);
	sort_array(str2, k);
	for (i = 0; i < k; i++)
	{
		cout << str2[i] << endl;
	}
	return 0;
}
void sort_array(char s[][31], int n) {
  int i, j, k, temp;
  for (j = 0; j < n - 1; ++j) {
    bool sort_flag = false;
    for (i = 0; i < n - j - 1; ++i) {
      char str_temp[31] = {0};
      temp = strcmp(s[i], s[i + 1]);
      if (temp >= 0)continue;
      if (temp < 0) {
        for (k = 0; k < 31; ++k) {
          str_temp[k] = s[i][k];
        }
        for (k = 0; k < 31; ++k) {
          s[i][k] = s[i + 1][k];
        }
        for (k = 0; k < 31; ++k) {
          s[i + 1][k] = str_temp[k];
        }
        sort_flag = true;
      }
    }
    if (!sort_flag) {
      break;
    }
  }
}
 
void removing(char s[][31], int n, char ch) {
  bool flag = false;
  int i, j, k;
  for (i = 0; i < n; ++i) {
    for (j = 0; s[i][j] != '\0'; ++j) {
      if (s[i][j] == ch) {
        flag = true;
        for (k = j; s[i][k] != '\0'; ++k) {
          s[i][k] = s[i][k + 1];
        }
      } else { flag = false; }
      if (flag) { j -= 1; }
    }
  }
}
