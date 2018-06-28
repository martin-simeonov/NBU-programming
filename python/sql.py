import sqlite3


conn=sqlite3.connect('Chinook_Sqlite.sqlite')
curs=conn.cursor()

query = 'SELECT * FROM Customer'
print query
print sqlite3.apilevel
curs.execute(query)
