SELECT C.member_name, B.review_text, TO_CHAR(B.review_date,'YYYY-MM-DD') review_date
FROM (SELECT member_id member_ids, COUNT(1) counts
FROM REST_REVIEW
GROUP BY member_id) A, REST_REVIEW B, MEMBER_PROFILE C
WHERE A.member_ids = B.member_id
AND A.member_ids = C.member_id
AND A.counts >= ALL (SELECT COUNT(1) counts
FROM REST_REVIEW
GROUP BY member_id)
ORDER BY B.review_date ASC, B.review_text ASC