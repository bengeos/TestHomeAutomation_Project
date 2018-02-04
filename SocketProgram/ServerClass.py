import socket
from threading import *
class client(Thread):
    message_data = 'SERVER_DATA'
    def __init__(self, socket, address):
        Thread.__init__(self)
        self.sock = socket
        self.addr = address
        self.send_data = "PORT1ON"
        print address[0]
        self.start()

    def run(self):
        if self.addr[0] == "192.168.2.17":
            while 1:
                self.message_data = self.sock.recv(1024).decode()
                print('Client Address:', self.addr)
                print('Client sent:', self.message_data)
                self.sock.send("New Message Data: " + str(self.message_data))
                # print text
        else:
            while 1:
                print('Client Address:', self.addr)
                print('Client sent:', self.sock.recv(1024).decode())
                print 'Sending Client:->'
                text = raw_input("send your command: ")
                self.sock.send(text.encode())


class ServerClass():
    def __init__(self, port):
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.host = "192.168.2.17"
        self.port = port
        self.server_socket.bind((self.host, self.port))
    def connect(self):
        self.server_socket.listen(10)
        print ('server started and listening')
        while 1:
            clientsocket, address = self.server_socket.accept()
            client(clientsocket, address)

# benServer = ServerClass(9999)
# benServer.connect()
