## SY_Algorithm

    ❣️Member : SYLee
    🐋 2020년 10월의 문제풀이 모음

- ### 백준 : 2293번 - 동전 1
    - 날짜 : 2020-10-25
    - [링크](https://www.acmicpc.net/problem/2293)
    - 분류 : 동적 계획법
    - 주의 사항 : 그냥 배열을 사용하면 메모리 초과 발생, 더 이상 사용하지 않는 값을 버리며 공간 복잡도를 향상 시켜야 한다. 메모리 제한에 주의!

        n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.

        사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

- ### 백준 : 1712번 - 손익 분기점
    - 날짜 : 2020-10-25
    - [링크](https://www.acmicpc.net/problem/1712)
    - 분류 : 수학
    - 주의 사항 : 안되는 경우를 잘 살펴야 한다. 기울기에 대해 생각해볼수 있는 문제!
  
        월드전자는 노트북을 제조하고 판매하는 회사이다. 노트북 판매 대수에 상관없이 매년 임대료, 재산세, 보험료, 급여 등 A만원의 고정 비용이 들며, 한 대의 노트북을 생산하는 데에는 재료비와 인건비 등 총 B만원의 가변 비용이 든다고 한다.

        예를 들어 A=1,000, B=70이라고 하자. 이 경우 노트북을 한 대 생산하는 데는 총 1,070만원이 들며, 열 대 생산하는 데는 총 1,700만원이 든다.

        노트북 가격이 C만원으로 책정되었다고 한다. 일반적으로 생산 대수를 늘려 가다 보면 어느 순간 총 수입(판매비용)이 총 비용(=고정비용+가변비용)보다 많아지게 된다. 최초로 총 수입이 총 비용보다 많아져 이익이 발생하는 지점을 손익분기점(BREAK-EVEN POINT)이라고 한다.

        A, B, C가 주어졌을 때, 손익분기점을 구하는 프로그램을 작성하시오

- ### 백준 : 15649번 - N과 M(1)
    - 날짜 : 2020-10-26
    - [링크](https://www.acmicpc.net/problem/15649)
    - 분류 : 백트래킹
    - 주의 사항 : 오호라 조합과 순열을 next_permutation이 아니라 다른 방식으로도 구현하는 법을 배웠당
    - 참고 : [순열구현코드](/Algorithm%20Summary/순열구현코드.md) 
  
        자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

            1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

- ### 백준 :  B11723 - 집합
    - 날짜 : 2020-10-27
    - [링크](https://www.acmicpc.net/problem/11723)
    - 분류 : 비트마스크
    - 주의 사항 : 입력이 많은 문제라 ios::sync_with_stdio(false)를 안해주면 시간초과가 난다. 그냥 cin, cout 쓰면 언제나 사용해 주자!
    - 참고 : 비트마스크에 대해 궁금하면 이 문제를 볼 것!

        비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

        add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
        remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
        check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
        toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
        all: S를 {1, 2, ..., 20} 으로 바꾼다.
        empty: S를 공집합으로 바꾼다. 
  