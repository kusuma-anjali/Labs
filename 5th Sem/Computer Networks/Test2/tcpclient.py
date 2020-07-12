from socket import *

serverName = gethostname()
serverPort = 12001
clientSocket = socket(AF_INET, SOCK_STREAM)
print("Establishing connection...")
clientSocket.connect((serverName, serverPort))
file_name = input("Enter the file name ")
word = input("Enter the word to be searched ")
message = file_name + " " + word
message = message.encode()
clientSocket.send(message)
word_count = int(clientSocket.recv(1024).decode())
print("the word count is",word_count)
clientSocket.close()
