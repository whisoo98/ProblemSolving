-- 코드를 입력하세요

SELECT HISTORY.history_id, history.fee * (1-NVL(DISCOUNT.discount_rate,0)/100) FEE
FROM
    (SELECT HISTORY.history_id, CAR.DAILY_FEE * (TO_NUMBER(HISTORY.end_date - HISTORY.start_date) + 1) AS FEE, 
    CASE WHEN TO_NUMBER(HISTORY.end_date - HISTORY.start_date) + 1 >= 90 THEN 90
         WHEN TO_NUMBER(HISTORY.end_date - HISTORY.start_date) + 1 >= 30 THEN 30
         WHEN TO_NUMBER(HISTORY.end_date - HISTORY.start_date) + 1 >= 7 THEN 7
         ELSE 0 END AS days
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY HISTORY, CAR_RENTAL_COMPANY_CAR CAR
    WHERE CAR.car_type = '트럭'
    AND HISTORY.car_id = car.car_id) HISTORY, 
    (SELECT REPLACE(duration_type,'일 이상','') AS duration_type, discount_rate
    FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
     WHERE car_type = '트럭'
     ) DISCOUNT
WHERE HISTORY.days = DISCOUNT.duration_type (+)
ORDER BY FEE DESC, HISTORY.history_id DESC