from pymysql import Connection

conn = Connection(
    host='localhost',
    port=3306,
    user='root',
    password='zx18956497165'
)
# 创建游标对象
cursor = conn.cursor()
conn.select_db("world")
# 使用游标对象查询表的状态
cursor.execute("select * from city")

result: tuple = cursor.fetchall()
for r in result:
    print(r)

conn.close()
