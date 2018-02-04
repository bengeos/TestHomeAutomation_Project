import socket
import time
class ClientClass():
    def __init__(self):
        self.data = 4566
        self.host = "192.168.2.17"
        self.port = 9995
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.connect((self.host, self.port))
    def getNextData(self):
        return self.data
    def run(self):
        while 1:
            print 'serial readed'
            text = raw_input("put ur value here")
            self.socket.send(text.encode())
            data = self.socket.recv(1024).decode()
            print ('Server Sent This:\n', data)
            time.sleep(2)
ben = ClientClass()
ben.run()