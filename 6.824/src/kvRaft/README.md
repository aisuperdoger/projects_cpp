编译：
g++ server.cpp -lzmq -pthread -o server
g++ client.cpp -lzmq -pthread -o client

如果运行server，发生段错误，我是通过重启解决的。