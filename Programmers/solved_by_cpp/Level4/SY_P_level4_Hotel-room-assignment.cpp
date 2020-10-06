#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
long long find(map<long long , long long> &hotel, long long v) {		// 최상위 부모 찾기
	if (hotel[v] == v) {
		return v;
	}
	return hotel[v] = find(hotel,hotel[v]);
	// 더 좋은 거 return p[v] = find(p[v]);	// 최상위 부모로 p[v] 값들이 정리가 됨
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
	map<long long, long long> hotel;
	for (long long num : room_number) {
		if (hotel.count(num) == 0) { hotel.insert(make_pair(num, num)); answer.push_back(num); }
		else { 
			long long loc = find(hotel, num);
			long long tmp = loc+1;
			while (true) {
				if (hotel.count(tmp) == 0) { hotel.insert(make_pair(tmp, tmp)); answer.push_back(tmp); break; }
				tmp++;
			}
			for (long long i = loc; i < tmp; i++) {
				hotel[i] = tmp;
			}
		}
	}
    return answer;
}

int main() {
	long long k = 10; 
	vector<long long> room_number = { 1,3,4,1,3,1 };
	vector<long long> answer = solution(k, room_number);
	for (long long num : answer) {
		cout << num << "\n";
	}
	return 0;
}