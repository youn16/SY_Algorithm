# 코딩 팁

### 1. cin과 cout 사용 tip
- 빠른 입출력 동기화를 위해 사용해 주면 좋은 코드 입니다
```
ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
```
위 코드를 쓰면 printf, scanf를 쓰는 건 조심해야 합니다.<br>

### 2. 비주얼스튜디오 파일 제외 하는 법
```
프로젝트에서 제외 : 오른쪽에 소스코드 우클릭하고 j
다시추가할때 : alt shift a
새파일 추가할때 : ctrl shift a
```

### 3. 알고리즘 작성 시 주의 할 것
```
<< endl;	// 되게 느림 \n 사용해라
.length() 특히 strlen() // 사용 주의 느림
.size()	//사용해도 괜찮음. 
```

### 4. 문제풀이 스킬
1. 전역변수를 사용할 것
2. 데이터영역이 스택영역보다 훨씬 큼
3. 전역변수는 데이터영역
4. 지역변수는 스택영역
5. 웬만하면 전역변수 사용
6. 자동으로 0으로 초기화됨

### 5. 정의문을 사용할 것
`#define MOD 1000000007`

### 6. 오버라이딩 사용법
```
struct time {
	int st;
	int et;
};

bool cmp(time a, time b) {
	if (a.et == b.et) {
		return a.st < b.st;
	}
	return a.et < b.et;
}

sort(meeting, meeting + n, cmp);
```

=>위의 코드를 더 짧게 사용하는 법
```
struct time {
	int st;
	int et;

	bool operator<(time a) const{
		if (et == a.et) {
		return st < a.st;
	}
		return et < a.et;
}
};
```

### 7. ❗좌표 탐색 
그래프 탐색에서 대부분 사용<br>
```
dx = {1, 0, -1, 0};
dy = {0, 1, 0, -1};
for (i) {
x+dx[i];
y+dy[i];
}
```
