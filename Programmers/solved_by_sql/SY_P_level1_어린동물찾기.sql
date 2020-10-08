/*
프로그래머스 - 어린 동물 찾기
by SY
DATE : 2020.10.08
*/
-- 정답 1
SELECT ANIMAL_ID, NAME
from ANIMAL_INS
where INTAKE_CONDITION <> 'Aged'
order by ANIMAL_ID asc
-- 정답 2, 이미 ID 로 정렬되어 있음으로 order by 안해줘도 괜찮음
SELECT ANIMAL_ID, NAME
from ANIMAL_INS
where INTAKE_CONDITION <> 'Aged'