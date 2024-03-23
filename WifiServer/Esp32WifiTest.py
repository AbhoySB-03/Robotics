import socket

# Define server address and port
SERVER_ADDRESS = '192.168.1.1'
SERVER_PORT = 80

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client_socket.connect((SERVER_ADDRESS, SERVER_PORT))
print("Connected to server.")

# Send messages to server
while True:
    message = input("Enter message to send to server (type 'exit' to quit): ")+"\n"
    client_socket.sendall(message.encode())
    if message.lower() == 'exit\n':
        break

# Close the connection
client_socket.close()