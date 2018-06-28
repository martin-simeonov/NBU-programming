import socket
import datetime


now = datetime.datetime.now()
s = socket.socket()
host = '127.0.0.1'
port = 1234
s.bind((host, port))

s.listen(5)
while True:
    c, addr = s.accept()
    print 'Got connection from', addr
    c.send('Now is ' + str(now.day) + '-' + str(now.month) + '-'
        + str(now.year) + ' ' + str(now.hour) + ':'
        + str(now.minute) + ':' + str(now.second))

c.close()
