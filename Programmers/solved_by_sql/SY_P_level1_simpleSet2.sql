/*
프로그래머스 - level1 간단 문제 모음 2
by SY
DATE : 2020.10.08
*/

--중복 제거하기 , distinct
SELECT count(distinct name)
from ANIMAL_INS

-- 동명 동물 수 찾기
SELECT NAME, count(*) count
from ANIMAL_INS
where name is not null
group by name
having count(*)>1
order by name

-- NULL 처리하기, ifnull
SELECT ANIMAL_TYPE, ifnull(name, "No name") name, SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID

-- 입양 시각 구하기(1), hour
SELECT hour(datetime) HOUR, count(*) count
from ANIMAL_OUTS
where hour(datetime) >= 9 and hour(datetime) <20
group by hour(datetime)
order by hour(datetime)

-- 루시와 엘라 찾기
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
from ANIMAL_INS
where NAME in("Lucy", "Ella", "Pickle", "Rogan", "Sabrina", "Mitty")

-- 이름에 el이 들어가는 동물 찾기
SELECT ANIMAL_ID, NAME
from ANIMAL_INS
where (NAME like "%el%" or NAME like "%EL%") and ANIMAL_TYPE = "Dog"
order by name

-- 중성화 여부 확인하기
/*
CASE WHEN THEN ELSE END문
*/
SELECT ANIMAL_ID, NAME,
CASE
    WHEN SEX_UPON_INTAKE like "%Neutered%" or SEX_UPON_INTAKE like "%Spayed%"
    THEN 'O'
    ELSE 'X' END as 중성화
from ANIMAL_INS
order by ANIMAL_ID

-- 오랜 기간 보호한 동물(1)
SELECT ins.NAME, ins.DATETIME
from ANIMAL_INS as ins left join ANIMAL_OUTS as outs on ins.ANIMAL_ID = outs.ANIMAL_ID
where outs.DATETIME is null
order by ins.DATETIME
limit 3

-- 오랜 기간 보호한 동물(2) 답 1
SELECT a.ANIMAL_ID, a.name NAME
from ANIMAL_INS as a left join ANIMAL_OUTS as b on a.ANIMAL_ID = b.ANIMAL_ID
order by b.datetime - a.datetime desc
limit 2

-- 오랜 기간 보호한 동물(2) 답 2
SELECT ANIMAL_ID, a.name NAME
from ANIMAL_INS as a join ANIMAL_OUTS as b using (ANIMAL_ID)
order by b.datetime - a.datetime desc
limit 2