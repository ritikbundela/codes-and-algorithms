-- Last updated: 26/11/2025, 22:31:04
# Write your MySQL query statement below
select distinct author_id as id
from views
where author_id = viewer_id
ORDER BY id ASC;

-- SELECT DISTINCT article_id AS id
-- FROM Views
-- WHERE author_id = viewer_id
-- ORDER BY id ASC;
