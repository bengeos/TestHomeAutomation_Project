import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host ="192.168.2.17"
port =8700
s.connect((host, port))
count = 0
count = count + 3
def ts(str):
   s.send('{"name":"biniam Kassahun"}'.encode())
   data = ''
   data = s.recv(1024).decode()
   print (data)
while 2:
   ts(s)
s.close ()