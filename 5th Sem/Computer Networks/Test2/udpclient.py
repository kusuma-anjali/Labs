from socket import *

serverName = gethostname()
serverPort = 12001
clientSocket = socket(AF_INET, SOCK_DGRAM)
word = input("Enter the word ").encode()
print("Establishing the connection with the server... ")
clientSocket.sendto(word, (serverName, serverPort))
message, serverAddr = clientSocket.recvfrom(1024)
print("Files are "+ message.decode())
clientSocket.close()

