
SELECT SALE.year, SALE.month, USER_INFO.gender, count(1) users
FROM 
    (SELECT DISTINCT user_id, TO_CHAR(sales_date,'YYYY') year, TO_NUMBER(TO_CHAR(sales_date,'MM')) month  
    FROM ONLINE_SALE) SALE, USER_INFO 
WHERE USER_INFO.gender IS NOT NULL
AND USER_INFO.user_id = SALE.user_id
GROUP BY SALE.year, SALE.month, USER_INFO.gender
ORDER BY SALE.year, SALE.month, USER_INFO.gender