import sqlite3

conn = sqlite3.connect('my.db')

if conn:
    print ("Opened database successfully")
else:
    print ("failed")

sql = "CREATE table account ( id int primary key);"

conn.execute(sql)

sql = "SELECT * FROM account;"

cursor = conn.execute(sql)

for row in cursor:
    print row

conn.close()
