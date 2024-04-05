#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second

using namespace std;
map<char, char>M;

void reverKey(string key){
	int d = 0;
	for(char i = 'A'; i <= 'Z'; i++) M[i] = key[d++];
}

string monoalphabeticEncyption(string input, string key){
	reverKey(key);
	string output = "";
    for(int i = 0; i < input.length(); i++) output += M[input[i]];
	return output;
}

bool checkKey(string key){
	if(key.length() != 26) return false;
	map<char, bool> M;
	for(int i = 0; i < key.length(); i++){
		if(M[key[i]] == false){
			M[key[i]] = true;
		}
		else if(M[key[i]] == true){
			return false;
		}
	}
	return true;
}

int main()
{
	string input, key, output="";
	cin >> input; 
	cin >> key; 
	if(checkKey(key) == false){
		cout << "Key khong hop le";
		return 0;
	}
	
    cout << "Input: " << input << "\nKey: " << key << endl;
	output = monoalphabeticEncyption(input, key);
	cout<<"Ma hoa chu don: "<<output<<endl;
}
