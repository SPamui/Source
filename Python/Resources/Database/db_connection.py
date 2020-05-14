import sqlite3

conn = sqlite3.connect('my.db')
cursor = conn.cursor()

if conn:
    print ("Opened database successfully")
else:
    print ("failed")

sql = "CREATE table account ( id int primary key);"

cursor.execute(sql)

sql = "SELECT * FROM account;"

count = cursor.execute(sql)

for row in count:
    print row
    
conn.commit()
conn.close()
