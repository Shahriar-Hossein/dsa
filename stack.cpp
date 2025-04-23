#include"bits/stdc++.h"
using namespace std;

/* 
 * given a string with combination
 * alphabets and stars
 * in each operation you can
 * choose a star and remove the next closest
 * aplhabet and the star itself
 * return the string without any stars in it
 */
void solve(string s) {
	stack<char> st;
	for(char c: s) {
		if(c!= '*'){
			st.push(c);
		} else {
			if(st.size() > 0) {
				st.pop();
			}
		}
	}
	stack<char> ans;
	while(!st.empty()){
		ans.push(st.top());
		st.pop();
	}
	while(!ans.empty()){
		cout<< ans.top();
		ans.pop();
	}
	cout<< '\n';

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin>> s;
	solve(s);

	return 0;
}
