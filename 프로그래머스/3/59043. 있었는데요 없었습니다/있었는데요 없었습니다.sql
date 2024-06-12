-- 코드를 입력하세요
SELECT INS.animal_id, INS.name
FROM ANIMAL_INS INS, ANIMAL_OUTS OUTS
WHERE INS.animal_id = OUTS.animal_id
AND INS.datetime > OUTS.datetime
ORDER BY INS.datetime ASC