#include <bits/stdc++.h>
using namespace std;

tuple<int, int> solve(vector<int> v) {
	int ans1 = 0;
	int ans2 = 0;

	for(auto it1 = v.begin(); it1 != v.end(); it1++) {
		for(auto it2 = v.begin(); it2 != v.end(); it2++) {
			auto a1 = *it1 + *it2;

			if(a1 == 2020) ans1 = *it1 * *it2;
			if(a1 > 2020) break;
			for(auto it3 = it2 + 1; it3 != v.end(); it3++) {
				auto a2 = a1 + *it3;
				if(a2 == 2020) ans2 = *it1 * *it2 * *it3;
				if(a2 > 2020) break;
			}
		}
	}

	return {ans1, ans2};
}

int main() {
	freopen("p01/input.txt", "r", stdin);

	vector<int> input;

	for(int i = 0; i < 200; i++) {
		int a; cin >> a;
		input.push_back(a);
	}

	sort(input.begin(), input.end());
	tuple<int, int> ret = solve(input);

	cout << get<0>(ret) << endl;
	cout << get<1>(ret) << endl;
}
