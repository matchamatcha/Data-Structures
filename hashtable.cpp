#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

const int max_size_arr = 512;	

class hashTable {
private:
	int size;
	int w;
	int items[max_size_arr];
	double inf;
public:
	hashTable();
	int hash(int);
	int insert(int);
	int search(int);
};

hashTable::hashTable() {
	size = 0;
	w = 16;
	inf = std::numeric_limits<int>::infinity();
	for (int i = 0; i < max_size_arr; i++) {
		items[i] = inf;
	}
}

int hashTable::hash(int x) { 
	int z = 60147, d = 9;
	int theMod = 1 << w, thediv = 2 << (w - d); 
	return ((z * x) % theMod) >> w - d;
}

int hashTable::insert(int x) {
	if (size > max_size_arr && (hash(x) > pow(2, 16) - 1)) {
		return 0;
	}
	else {
		int index = hash(x);
		int cnt = 0;
		while (items[index] != inf) {
			if (items[index] != inf) {
				index = (index + 1) % max_size_arr;
				cnt++;
			} 
			
		}
		items[index] = x;
		size++;
		return cnt;	
	}
}

int hashTable::search(int x) {
	if (size > max_size_arr && (hash(x) > pow(2, 16) - 1)) {
		return 0;
	}
	else {
		int index = hash(x);
		int cnt = 0;
		
		while (items[index] != x) {
			if (items[index] == inf){
				return 0;
			}
			if (cnt == max_size_arr) {
				return -2;
			}
			index = (index + 1) % max_size_arr;
			cnt++;
		}
		return cnt;
	}
}

int main() {
	int tcases;
	cin>>tcases;
	while (tcases != 0) {
		hashTable h;
		int n;
		cin>>n;
		while (n != 0) {
			int x;
			cin>>x;
			int z = h.insert(x);

			cout<<z<<" ";
			
			n--;
		}
        cout<<endl;	
		
		int y;
		cin>>y;
		int res = h.search(y);
		if (res == -1 || res == -2) {
			cout<<"NOT FOUND" << " ";
		}
		else {
		cout<<res<<endl;

		}
	
		tcases--;
	}
}
