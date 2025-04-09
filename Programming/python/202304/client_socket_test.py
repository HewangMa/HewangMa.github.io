import socket

client_socket = socket.socket()
client_socket.connect(("localhost", 8888))

while True:
    msg = input("输入你要发送的消息")
    if msg == 'exit':
        break
    client_socket.send(msg.encode("UTF-8"))
    data = client_socket.recv(1024)
    print(f"接收到的消息是{data.decode('UTF-8')}")

client_socket.close()
