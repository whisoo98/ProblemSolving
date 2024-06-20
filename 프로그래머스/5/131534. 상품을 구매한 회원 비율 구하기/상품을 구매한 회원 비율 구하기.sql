-- 코드를 입력하세요
-- SELECT user_id, joined, COUNT(user_id) OVER (PARTITION BY TO_CHAR(joined,'YYYY')) AS alluser
-- FROM USER_INFO
-- WHERE TO_CHAR(joined,'YYYY') = '2021'

-- TO_CHAR(SALES_DATE,'YYYY') , TO_CHAR(SALES_DATE,'MM') 



SELECT DISTINCT year, TO_NUMBER(month) month, PURCHASED_USERS, ROUND(purchased_users/alluser,1) as PURCHASED_RATIO
FROM (
    SELECT year, month, count(1) purchased_users
    FROM (
        SELECT DISTINCT SALE.user_id, TO_CHAR(SALES_DATE,'YYYY') year, TO_CHAR(SALES_DATE,'MM') month
        FROM ONLINE_SALE SALE, USER_INFO USERS
        WHERE TO_CHAR(USERS.joined,'YYYY') = '2021'
        AND SALE.user_id = USERS.user_id)
    GROUP BY year, month) PURCHASED,
    (SELECT COUNT(user_id) OVER (PARTITION BY TO_CHAR(joined,'YYYY')) AS alluser
    FROM USER_INFO
    WHERE TO_CHAR(joined,'YYYY') = '2021') ALLUSERS
ORDER BY year ASC, month ASC

-- SELECT year, month, count(month) purchased_users
-- FROM (
--     SELECT DISTINCT SALE.user_id, TO_CHAR(SALES_DATE,'YYYY') year, TO_CHAR(SALES_DATE,'MM') month
--     FROM ONLINE_SALE SALE, USER_INFO USERS
--     WHERE TO_CHAR(USERS.joined,'YYYY') = '2021'
--     AND SALE.user_id = USERS.user_id
--     )
-- GROUP BY year, month
-- ORDER BY year ASC, month ASC