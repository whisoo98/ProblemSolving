-- 코드를 입력하세요
SELECT ANIMAL_TYPE, count(1) count
FROM ANIMAL_INS
WHERE ANIMAL_TYPE = 'Dog' OR ANIMAL_TYPE = 'Cat'
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE ASC