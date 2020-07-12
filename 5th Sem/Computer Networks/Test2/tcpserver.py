from socket import *

serverName = gethostname()
serverPort = 12001
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind((serverName, serverPort))
serverSocket.listen(1)
print("Server is ready ")
while True:
    conn, addr = serverSocket.accept()
    print("connected to "+str(addr))
    file_name, word = conn.recv(1024).decode().split()
    with open(file_name, "r") as f:
        file_content = f.read().split()
    word_count = 0
    for ele in file_content:
        if ele.upper() == word.upper():
            word_count += 1
    word_count = str(word_count)
    conn.send(word_count.encode())
    print("disconnecting from "+str(addr))
    conn.close()
