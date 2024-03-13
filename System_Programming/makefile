CC = gcc
CFLAGS = -pthread
LDFLAGS = 

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_BIN = BibakBOXServer
CLIENT_BIN = BibakBOXClient

all: $(SERVER_BIN) $(CLIENT_BIN) 

$(SERVER_BIN): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(CLIENT_BIN): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(SERVER_BIN) $(CLIENT_BIN)