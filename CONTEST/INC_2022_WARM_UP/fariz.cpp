#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	long long a = s.length();
	bool finish = true;
	for(long long i=1; i<a; i++)
	{
		string b = s.substr(0,i);
		string c = s.substr(i,a);
		
		bool pal = true;
		bool bbener = 0, cbener = 0;
		for(int j =0; j<i; j++)//cek subs pertama
		{
			if(b[j]==b[i-j-1])
			{
			}
			else {
				pal = 0;
				break;
			}
			if(pal)
			{
				bbener = true;
			break;
			}
		}

		long long x = c.length();
		
		for(long long j = 0; j<x; j++)
		{
			if(c[j]==c[x-j-1])
			{
			}
			else {
				pal = 0;
				break;
			}
			if(pal){
				cbener = true;
				break;
			}
		}
		if(bbener == true and cbener == true)
		{
		cout<<b<<" "<<c<<endl;
		finish = false;
		break;
		}
		
	}
	if(finish == true)cout<<"NO"<<endl;
	return 0;
}