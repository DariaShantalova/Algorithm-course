#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void swap(char& c1, char& c2){
	char tmp = c1;
	c1 = c2;
	c2 = tmp;
}

void selection_sort(string& s){
	char tmp;
	for(int i = 0; i < s.size(); i++){
		int min_j = i;
		for(int j = i + 1; j < s.size(); j++){
			if(s[j] < s[min_j]){
				min_j = j;
			}
		}
		swap(s[i], s[min_j]);
	}
}

void bubble_sort(string& s){
	bool flag = false;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size() - 1; j++){
			if(s[j+1] < s[j]){
				swap(s[j+1], s[j]);
				flag = true;
			}
		}
		if(!flag){
			break;
		}
		flag = false;
	}
}

void insertions_sort(string& s){
	// .5 4 3 2 1 i = 0
	// 5 .4 3 2 1
	//// 5 .4 3 2 1
	// 4 5 .3 2 1 // i = 2
	// 3 4 5 .2 1 // i = 3
	// 2 3 4 5 .1 // i = 4
	// 1 2 3 4 5
	// 1 2 3 5 .4

	for(int i = 1; i < s.size(); i++){
		for(int j = i; j > 0; j--){
			if(s[j-1] > s[j]){
				swap(s[j-1], s[j]);
			}else{
				break;
			}
		}

	}
}

string merge(const string& s1, const string & s2){
	string s;
	s.resize(s1.size() + s2.size());
	int i,j;
	i = 0;
	j = 0;
	while(i < s1.size() && j < s2.size()){
		if(s1[i] < s2[j]){
			s[i + j] = s1[i];
			i++;
		}else{
			s[i + j] = s2[j];
			j++;
		}
	}

	return s;
}

void set(string substr, string& s, int first, int last){
	for(int i = first; i < last; i++){
		s[i] = substr[i - first];
	}
}

int min(int a, int b){
	return a < b ? a : b;
}

void merge_sort(string& s){
	for(int k = 2; k < 2 * s.size(); k *= 2){
		for(int i = 0; i < s.size(); i += k){
			set(merge(s.substr(i, i + k/2), s.substr(i + k/2, min(s.size()-1, i + k))),
					s, i, min(s.size()-1, i + k));
		}
	}
}

int main(void) {
  string s = "hello world";
  merge_sort(s);
  cout << s << endl;
  return 0;
}


