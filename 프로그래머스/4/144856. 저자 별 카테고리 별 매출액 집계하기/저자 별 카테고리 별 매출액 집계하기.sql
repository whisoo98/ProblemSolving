-- 코드를 입력하세요
SELECT AUTHOR.author_id, AUTHOR.author_name, A.category, A.sales
FROM (SELECT BOOK.category, BOOK.author_id, sum(BOOK.price * SALES.sales) sales
FROM(
    SELECT book_id, SUM(sales) sales
    FROM BOOK_SALES
    WHERE TO_CHAR(sales_date,'YYYY-MM') = '2022-01'
    GROUP BY book_id) SALES, BOOK
WHERE SALES.book_id = BOOK.book_id
GROUP BY BOOK.category, BOOK.author_id) A, AUTHOR
WHERE A.author_id = AUTHOR.author_id
ORDER BY AUTHOR.author_id ASC, A.category DESC