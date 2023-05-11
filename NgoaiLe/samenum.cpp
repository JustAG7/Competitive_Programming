#include <bits/stdc++.h>
#include <string>
using namespace std;

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void permute(string s , string answer)
{
	if(s.length() == 0)
	{
		cout<<answer<<"\n";
		return;
	}
	for(int i=0 ; i<s.length() ; i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0,i);
		string right_substr = s.substr(i+1);
		string rest = left_substr + right_substr;
		permute(rest , answer+ch);
	}

}

int main()
{
	indef();
	string s;
	string answer="";

	//cout<<"Enter the string : ";
	cin>>s;

	cout<<"\nAll possible strings are : ";
	permute(s , answer);
	return 0;
}
