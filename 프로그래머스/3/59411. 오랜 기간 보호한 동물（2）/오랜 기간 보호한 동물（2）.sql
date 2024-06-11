-- 코드를 입력하세요
SELECT *
FROM(
    SELECT OUTS.animal_id, OUTS.name
    FROM ANIMAL_INS INS, ANIMAL_OUTS OUTS
    WHERE INS.animal_id = OUTS.animal_id
    ORDER BY OUTS.datetime - INS.datetime DESC
)
WHERE ROWNUM < 3
