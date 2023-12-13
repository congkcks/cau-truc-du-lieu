#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
   string line="Vuong Duc Hung;0383268699";
   string a;
   string b;
   istringstream get(line);
   getline(get,a);
   getline(get,b);
   cout<<a<<" \n"<<b<<endl;
   if(b==""){
   	cout<<"chuoi dang rong"<<endl;
   }
   return 0;
   
   
	
	
	
}

