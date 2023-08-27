#include <string>
#include <iostream>
using namespace std;
#define nn "\n"
#define ll long long
#define loop(it,start,end) for(int it =start;it<end;++it)
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pyes cout<<"YES"
#define pno cout<<"NO"
#define fr first
#define sc second
int state;
int startStateQ0(char s) {// (st,0,4)
	if (s == '1')
		state = 1; // (1,5)
	else
		state = -1;
	return state;
}
int firstStateQ1(char s) {// (1,5)
	if (s == '0')
		state = 2; //2
	else if (s == '1')
		state = 4; //6
	else
		state = -1;
	return state;
}
int secondStateQ2(char s) { //2
	if (s == '1')
		state = 3; // (3,F)
	else
		state = -1;
	return state;
}
int thirdStateQ3(char s) { //(3,F)
	if (s == '0' || s == '1')
		state = 3; //(3,F)
	else
		state = -1;
	return state;
}
int fourthStateQ4(char s) { //6
	if (s == '0')
		state = 5; // (7,F)
	else
		state = -1;
	return state;
}
int fifthStateQ5(int s) {// (7,F)
	if (s == '0' || s == '1')
		state = 5; // (7.F)
	else
		state = -1;
	return state;
}
int isAcceptedString(string String) { //1011
	int l = String.length();
	//state = 0;
	for (int i = 0; i < l; i++) {
		if (state == 0)// st,0,4
			state = startStateQ0(String[i]);
		else if (state == 1)// 1,5
			state = firstStateQ1(String[i]);
		else if (state == 2)// 2
			state = secondStateQ2(String[i]);
		else if (state == 3)// //3,F
			state = thirdStateQ3(String[i]);
		else if (state == 4)// 6
			state = fourthStateQ4(String[i]);
		else if (state == 5)// 7,F
			state = fifthStateQ5(String[i]);
		else
			return 0;
	}
	if (state == 3 || state == 5) //7,f || 3,f
		return 1;
	else
		return 0;
}
int main() {
	string St;
	cin >> St;
	if (isAcceptedString(St))
		cout << nn << "ACCEPTED" << nn;
	else
		cout << nn << "Reject" << nn;
}
