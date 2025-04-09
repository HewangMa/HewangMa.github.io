import socket

# 创建socket服务器对象
socket_server = socket.socket()

# 把服务器对象绑定到本地
socket_server.bind(("localhost", 8888))

# 开始监听,把连接对象和地址放到conn和address中
socket_server.listen(1)
conn, address = socket_server.accept()

print(f"接收到了客户端的链接，客户端的信息是：{address}")

while True:
    data = conn.recv(1024).decode("UTF-8")
    if data == "end":
        break
    print(f"客户端发来的消息是：{data}")
    msg = input("你要回复的信息是：")
    if msg == "end":
        break
    conn.send(msg.encode("UTF-8"))

conn.close()
socket_server.close()
