/*
프로그래머스 - level1 간단 문제 모음 1
by SY
DATE : 2020.10.08
*/

--최솟값 구하기
SELECT MIN(DATETIME) -- 답하나만 나옴
from ANIMAL_INS

-- 동물 아이디와 이름
SELECT ANIMAL_ID, NAME
from ANIMAL_INS

-- 여러기준으로 정렬하기
SELECT ANIMAL_ID, NAME, DATETIME
from ANIMAL_INS
order by NAME, DATETIME desc -- NAME으로 오름차순 먼저, DATETIME으로 내림차순

-- 이름이 없는 동물의 아이디
SELECT ANIMAL_ID
from ANIMAL_INS
where name is null

-- 동물 수 구하기
SELECT count(*)
from ANIMAL_INS

-- 상위 n개 레코드 내 답
SELECT name
from ANIMAL_INS
where datetime = (select min(datetime) from ANIMAL_INS)

-- 상위 n개 레코드 답 2
SELECT NAME
FROM ANIMAL_INS
ORDER BY DATETIME
LIMIT 1

-- 이름이 있는 동물 아이디
SELECT ANIMAL_ID
from ANIMAL_INS
where name is not null

-- 고양이와 개는 몇 마리 있을
/*
order by 부분의 실행 원리가 이해가 안됨...
order by 는 마지막에 서브 그룹에 적용된다.
*/
SELECT ANIMAL_TYPE, count(*) count
from ANIMAL_INS
group by ANIMAL_TYPE
having ANIMAL_TYPE = "Cat" or ANIMAL_TYPE = "Dog"
order by ANIMAL_TYPE