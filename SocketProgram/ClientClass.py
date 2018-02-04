import socket
import time
import serial
class ClientClass():
    def __init__(self):
        self.data = 4566
        self.host = "192.168.2.17"
        self.port = 9999
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.connect((self.host, self.port))
        self.serial_port = serial.Serial(port='/dev/master1', baudrate=9600, parity=serial.PARITY_ODD, stopbits=serial.STOPBITS_TWO, bytesize=serial.SEVENBITS, timeout=10)
        if(self.serial_port.is_open()):
            exit()
    def getNextData(self):
        self.data = self.data + 345
        return self.data
    def run(self):
        while 1:
            print 'start reading serial port'
            new_serial_data = self.serial_port.readline()
            print 'serial readed'
            self.socket.send('{"name":"Arduino1","data":' + str(new_serial_data) + '}'.encode())
            data = self.socket.recv(1024).decode()
            self.serial_port.write(tobi)
            print (data)
            time.sleep(2)
ben = ClientClass()
ben.run()