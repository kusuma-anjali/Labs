from socket import *

file_list = ["f1.txt", "f2.txt", "f3.txt", "f4.txt", "f5.txt"]

serverName = gethostname()
serverPort = 12001
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind((serverName, serverPort))
print("The server is ready")
 
while True:

    word, addr = serverSocket.recvfrom(1024)
    word = word.decode()
    ret_message = ''
    for file in file_list:
        with open(file, "r") as f:
            if word.upper() in f.read().upper():
                ret_message += file+" "
    serverSocket.sendto(ret_message.encode(), addr)
