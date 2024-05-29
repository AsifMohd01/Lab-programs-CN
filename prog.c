// 1. Write a Program to find the shortest path in a network of 6 to 10 nodes.
// (Dijkstra’s algorithm is used here)

#include <iostream>
using namespace std;
class dj
{
    int n, cost[10][10], d[10], p[10], v[10];

public:
    void read_matrix();
    void short_path(int);
    void display(int);
};
void dj::read_matrix()
{
    int i, j;
    cout << "Enter the number of vertices\n";
    cin >> n;
    cout << "Enter the cost adjacency matrix\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> cost[i][j];
}
void dj::short_path(int src)
{
    int i, j, min, u, s;
    for (i = 0; i < n; i++)
    {
        d[i] = cost[src][i];
        v[i] = 0;
        p[i] = src;
    }
    v[src] = 1;
    for (i = 0; i < n; i++)
    {
        min = 99;
        u = 0;
        for (j = 0; j < n; j++)
        {
            if (!v[j])
                if (d[j] < min)
                {
                    min = d[j];
                    u = j;
                }
        }
        v[u] = 1;
        for (s = 0; s < n; s++)
            if (!v[s] && (d[u] + cost[u][s] < d[s]))
            {
                d[s] = d[u] + cost[u][s];
                p[s] = u;
            }
    }
}
void dj::display(int src)
{
    int i, k, parent;
    for (i = 0; i < n; i++)
    {
        if (i == src)
            continue;
        cout << "The shortest path from " << src << " to " << i << " is " << endl;
        k = i;
        cout << k << "<----";
        while (p[k] != src)
        {
            cout << p[k] << "<---";
            k = p[k];
        }
        cout << src << endl;
        cout << "and the distance is " << d[i] << endl;
    }
}
int main()
{
    int source;
    dj dij;
    dij.read_matrix();
    cout << "enter the source" << endl;
    cin >> source;
    dij.short_path(source);
    dij.display(source);
    return 0;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 2. Write a program for error detecting code using CRC-CCITT (16-bits).

#include <stdio.h>
#include <string.h>
                                                                                                                                                                                                                           char
                                                                                                                                                                                                                               data[100],
    concatdata[117], src_crc[17], dest_crc[17], frame[120], divident[18], divisor[18] = "10001
                                                                          000000100001 ",res[17]=" 0000000000000000 ";
                                                                          void
                                                                          crc_cal(int node)
{
    int i, j;
    for (j = 17; j <= strlen(concatdata); j++)
    {
        if (divident[0] == '1')
        {
            for (i = 1; i <= 16; i++)
                if (divident[i] != divisor[i])
                    divident[i - 1] = '1';
                else
                    divident[i - 1] = '0';
        }
        else
        {
            for (i = 1; i <= 16; i++)
                divident[i - 1] = divident[i];
        }
        if (node == 0)
            divident[i - 1] = concatdata[j];
        else
            divident[i - 1] = frame[j];
    }
    divident[i - 1] = '\0';
    printf("\ncrc is %s\n", divident);
    if (node == 0)
    {
        strcpy(src_crc, divident);
    }
    else
        strcpy(dest_crc, divident);
}

int main()
{
    int i, len, rest;
    printf("\n\t\t\tAT SOURCE NODE\n\nenter the data to be send :");
    gets(data);
    strcpy(concatdata, data);
    strcat(concatdata, "0000000000000000");
    for (i = 0; i <= 16; i++)
        divident[i] = concatdata[i];
    divident[i + 1] = '\0';
    crc_cal(0);
    printf("\ndata is :\t");
    puts(data);
    printf("\nthe frame transmitted is :\t");
    printf("\n%s%s", data, src_crc);
    printf("\n\t\tSOURCE NODE TRANSMITTED THE FRAME ---->");
    printf("\n\n\n\n\t\t\tAT DESTINATION NODE\nenter the received frame:\t");
    gets(frame);
    for (i = 0; i <= 16; i++)
        divident[i] = frame[i];
    divident[i + 1] = '\0';
    crc_cal(1);
    if (strcmp(dest_crc, res) == 0)
        printf("\nreceived frame is error free ");
    else
        printf("\nreceived frame has one or more error");
    return 1;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 3. Write a program for distance vector algorithm to find suitable path for transmission.

#include <stdio.h>
                                                                                                                                                                                                                           struct rtable
{
    int dist[20], nextnode[20];
} table[20];
int cost[10][10], n;
void distvector()
{
    int i, j, k, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            table[i].dist[j] = cost[i][j];
            table[i].nextnode[j] = j;
        }
    }
    do
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (table[i].dist[j] > cost[i][k] + table[k].dist[j])
                    {
                        table[i].dist[j] = table[i].dist[k] + table[k].dist[j];
                        table[i].nextnode[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);
}
int main()
{
    int i, j;
    printf("\nenter the no of vertices:\t");
    scanf("%d", &n);
    printf("\nenter the cost matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    distvector();
    for (i = 0; i < n; i++)
    {
        printf("\nstate value for router %c \n", i + 65);
        printf("\ndestnode\tnextnode\tdistance\n");
        for (j = 0; j < n; j++)
        {
            if (table[i].dist[j] == 99)
                printf("%c\t\t-\t\tinfinite\n", j + 65);
            else
                printf("%c\t\t%c\t\t%d\n", j + 65, table[i].nextnode[j] + 65, table[i].dist[j]);
        }
    }
    return 0;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 4. Using TCP/IP sockets, write a client – server program to make the client send the file name and to make the server send back the contents of the requested file if present.

// SERVER

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

                                                                                                                                                                                                                           void
                                                                                                                                                                                                                           error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, n, i = 0;
    char buffer[256], c[2000], ch;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    FILE *fd;
    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR,opening socket");
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    printf("Server: waiting for client....\n");
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
        perror("EROOR on accept");
    }
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0)
    {
        perror("Error reading from socket");
    }
    printf("SERVER: %s\n", buffer);
    if ((fd = freopen(buffer, "r", stdin)) != NULL)
    {
        printf("SERVER: %s found!\n Transfering the contents...\n", buffer);
    }
    while ((ch = getc(stdin)) != EOF)
        c[i++] = ch;
    c[i] = '\0';
    printf("File content %s\n", c);
    n = write(newsockfd, c, 1999);
    if (n < 0)
        perror("ERROR in writing to the socket");
    else
    {
        printf("SERVER: file not found");
        n = write(newsockfd, "File not found! ", 15);
        if (n < 0)
            perror("ERROR writing to socket");
    }
    return 0;
}

// CLIENT

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void error(char *msg)
{
    perror(msg);
    exit(0);
}
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char filepath[256], buf[3000];
    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("\nerror in opening socket");
    printf("\nclient online");
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "error ,no such host");
        exit(0);
    }
    printf("\n server online");
    bzero((struct sockaddr *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        perror("error writing to socket");
    printf("\nclient:enter path with filename:\n");
    scanf("%s", filepath);
    n = write(sockfd, filepath, strlen(filepath));
    if (n < 0)
        perror("\nerror writing to socket");
    bzero(buf, 3000);
    n = read(sockfd, buf, 2999);
    if (n < 0)
        perror("\nerror reading to socket");
    printf("\nclient:displaying from socket");
    fputs(buf, stdout);
    return 0;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 5. Write a program for error detecting using Hamming Code.

#include <stdio.h>
#include <math.h>
                                                                                                                                                                                                                           void
                                                                                                                                                                                                                           genhamcode();
void makeerror();
void correcterror();
int h[12];
int main()
{
    int i, ch;
    printf("\n enter the message in bits\n");
    for (i = 1; i < 12; i++)
        if (i == 3 || i == 5 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11)
            scanf("%d", &h[i]);
    for (i = 1; i < 12; i++)
        printf("%d", h[i]);
    genhamcode();
    printf("\n do you want to make error\n(0 or 1)\n");
    scanf("%d", &ch);
    if (ch)
    {
        makeerror();
        correcterror();
    }
    else
        printf("\n no error");
    return (0);
}
void genhamcode()
{
    int temp, i;
    temp = h[3] + h[5] + h[7] + h[9] + h[11];
    (temp % 2 != 0) ? (h[1] = 1) : (h[1] = 0);
    temp = h[3] + h[6] + h[7] + h[10] + h[11];
    (temp % 2 != 0) ? (h[2] = 1) : (h[2] = 0);
    temp = h[5] + h[6] + h[7];
    (temp % 2 != 0) ? (h[4] = 1) : (h[4] = 0);
    temp = h[9] + h[10] + h[11];
    (temp % 2 != 0) ? (h[8] = 1) : (h[8] = 0);
    printf("\n transmitted codeword is:\n");
    for (i = 1; i < 12; i++)
        printf(" %d ", h[i]);
}
void makeerror()
{
    int pos, i;
    printf("\n enter the position you want to make error\n");
    scanf("%d", &pos);
    if (h[pos] == 1)
        h[pos] = 0;
    else
        h[pos] = 1;
    printf("\n Error occured and the error codeword is\n");
    for (i = 1; i < 12; i++)
        printf(" %d ", h[i]);
}
void correcterror()
{
    int r1, r2, r4, r8, i, errpos;
    r1 = (h[1] + h[3] + h[5] + h[7] + h[9] + h[11]) % 2;
    r2 = (h[2] + h[3] + h[6] + h[7] + h[10] + h[11]) % 2;
    r4 = (h[4] + h[5] + h[6] + h[7]) % 2;
    r8 = (h[8] + h[9] + h[10] + h[11]) % 2;
    errpos = r8 * 8 + r4 * 4 + r2 * 2 + r1 * 1;
    printf("\n Error occured in pos %d\n", errpos);
    printf("\n\n............ correction starts now........\n");
    if (h[errpos] == 1)
        h[errpos] = 0;
    else
        h[errpos] = 1;
    printf("\n Original codeword is :");
    for (i = 1; i < 12; i++)
        printf(" %d ", h[i]);
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 6. Write a Program to implement sliding window protocol.

// SENDER

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
                                                                                                                                                                                                                           int
                                                                                                                                                                                                                           main()
{
    int sock, bytes_received, connected, true = 1, i = 1, s, f = 0, sin_size;
    char send_data[1024], data[1024], c, fr[30] = " ";
    struct sockaddr_in server_addr, client_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket not created");
        exit(1);
    }
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int)) == -1)
    {
        perror("Setsockopt");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(17000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Unable to bind");
        exit(1);
    }
    if (listen(sock, 5) == -1)
    {
        perror("Listen");
        exit(1);
    }
    fflush(stdout);
    sin_size = sizeof(struct sockaddr_in);
    connected = accept(sock, (struct sockaddr *)&client_addr, &sin_size);
    while (strcmp(fr, "exit") != 0)
    {
        printf("Enter Data Frame %d:(Enter exit for End):", i);
        scanf("%s", fr);
        send(connected, fr, strlen(fr), 0);
        recv(sock, data, 1024, 0);
        if (strlen(data) != 0)
            printf("I got an acknowledgment : %s\n", data);
        fflush(stdout);
        i++;
    }
    close(sock);
    return (0);
}

// RECEIVER

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main()
{
    int sock, bytes_received, i = 1;
    char receive[30];
    struct hostent *host;
    struct sockaddr_in server_addr;
    host = gethostbyname("127.0.0.1");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket not created");
        exit(1);
    }
    printf("Socket created");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(17000);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_addr.sin_zero), 8);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Connect");
        exit(1);
    }
    while (1)
    {
        bytes_received = recv(sock, receive, 20, 0);
        receive[bytes_received] = '\0';
        if (strcmp(receive, "exit") == 0)
        {
            close(sock);
            break;
        }
        else
        {
            if (strlen(receive) < 10)
            {
                printf("\nFrame %d data %s received\n", i, receive);
                send(0, receive, strlen(receive), 0);
            }
            else
            {
                send(0, "negative", 10, 0);
            }
            i++;
        }
    }
    close(sock);
    return (0);
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// 7. Write a program to implement FIFO-Client and FIFO-Server to transfer files.

// SERVER

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"
                                                                                                                                                                                                                        int
                                                                                                                                                                                                                        main()
{
    char p[100], f[100], c[300], ch;
    int num, num2, f1, fd, fd2, i = 0;
    mknod(FIFO1_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO2_NAME, S_IFIFO | 0666, 0);
    printf("\nSERVER ONLINE");
    fd = open(FIFO1_NAME, O_RDONLY);
    printf("client online\nwaiting for request\n\n");
    while (1)
    {
        if ((num = read(fd, p, 100)) == -1)
            perror("\nread error");
        else
        {
            p[num] = '\0';
            if ((f1 = open(p, O_RDONLY)) < 0)
            {
                printf("\nserver: %s not found", p);
                exit(1);
            }
            else
            {
                printf("\nserver:%s found \ntranfering the contents", p);
                stdin = fdopen(f1, "r");
                while ((ch = getc(stdin)) != EOF)
                    c[i++] = ch;
                c[i] = '\0';
                printf("\nfile contents %s\n ", c);
                fd2 = open(FIFO2_NAME, O_WRONLY);
                if (num2 = write(fd2, c, strlen(c)) == -1)
                    perror("\ntranfer error");
                else
                    printf("\nserver :tranfer completed");
            }
            exit(1);
        }
    }
}

// CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"
int main()
{
    char p[100], f[100], c[3000];
    int num, num2, f1, fd, fd2;
    mknod(FIFO1_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO2_NAME, S_IFIFO | 0666, 0);
    printf("\n waiting for server...\n");
    fd = open(FIFO1_NAME, O_WRONLY);
    printf("\n SERVER ONLINE !\n CLIENT:Enter the path\n");
    while (gets(p), !feof(stdin))
    {
        if ((num = write(fd, p, strlen(p))) == -1)
            perror("write error\n");
        else
        {
            printf("Waiting for reply....\n");
            fd2 = open(FIFO2_NAME, O_RDONLY);
            if ((num2 = read(fd2, c, 3000)) == -1)
                perror("Transfer error!\n");
            else
            {
                printf("File recieved! displaying the contents:\n");
                if (fputs(c, stdout) == EOF)
                    perror("print error\n");
                exit(1);
            }
        }
    }
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 8. Using UDP Sockets write client server program to transfer files.

// SERVER

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
                                                                                                                                                                                                                           void
                                                                                                                                                                                                                           error(char *msg)
{
    perror(msg);
    exit(0);
}
int main(int argc, char *argv[])
{
    int sock, length, fromlen, n;
    struct sockaddr_in server;
    struct sockaddr_in from;
    char buf[1024];
    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(0);
    }
    Sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        error("Opening socket");
    }
    length = sizeof(server);
    bzero(&server, length);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));
    if (bind(sock, (struct sockaddr *)&server, length) < 0)
    {
        error("binding");
    }
    fromlen = sizeof(struct sockaddr_in);
    while (1)
    {
        n = recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
        if (n < 0)
        {
            error("recvfrom");
        }
        write(1, "Received a datagram: ", 21);
        write(1, buf, n);
        n = sendto(sock, "Got your message\n", 17,
                   0, (struct sockaddr *)&from, fromlen);
        if (n < 0)
        {
            error("sendto");
        }
    }
}

// CLIENT

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void error(char *);
int main(int argc, char *argv[])
{
    int sock, length, n;
    struct sockaddr_in server, from;
    struct hostent *hp;
    char buffer[256];
    if (argc != 3)
    {
        printf("Usage: server port\n");
        exit(1);
    }
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        error("socket");
    }
    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);

    if (hp == 0)
    {
        error("Unknown host");
    }
    bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    length = sizeof(struct sockaddr_in);
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    n = sendto(sock, buffer, strlen(buffer), 0, &server, length);
    if (n < 0)
    {
        error("Sendto");
    }
    n = recvfrom(sock, buffer, 256, 0, &from, &length);
    if (n < 0)
    {
        error("recvfrom");
    }
    write(1, "Got an ack: ", 12);
    write(1, buffer, n);
}
void error(char *msg)
{
    perror(msg);
    exit(0);
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// 9.Write a program to implement Congestion Control using leaky bucket.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <error.h>
#include <sys/stat.h>
#include <unistd.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX 25
                                                                                                                                                                                                                  int
                                                                                                                                                                                                                  main()
{
    int cap, oprt, cont, i = 0, inp[MAX], ch, nsec, drop;
    printf("LEAKY BUCKET ALGORITM\n");
    printf("\nEnter the bucket size:\n");
    scanf("%d", &cap);
    printf("\nEnter the output rate:");
    scanf("%d", &oprt);
    do
    {
        printf("\nEnter the number of packets entering at %d seconds\n", i + 1);
        scanf("%d", &inp[i]);
        i++;
        printf("\nEnter 1 to insert packet or 0 to quit\n");
        scanf("%d", &ch);
    } while (ch);
    nsec = i;
    printf("\n(SECOND):(PACK RECVD):(PACK SENT):(PACK LEFT IN BUCKET):(PACK
           dROPPED)\n ");
        cont = 0;
    drop = 0;
    for (i = 0; i < nsec; i++)
    {
        cont += inp[i];
        if (cont > cap)
        {
            drop = cont - cap;
            cont = cap;
        }
        printf("(%d): ", i + 1);
        printf("\t\t(%d): ", inp[i]);
        printf("\t\t(%d): ", min(cont, oprt));
        cont = cont - min(cont, oprt);
        printf("\t\t(%d)", cont);
        printf("\t\t(%d)\n", drop);
    }
    for (; cont != 0; i++)
    {
        if (cont > cap)
            cont = cap;
        drop = 0;
        printf("(%d): ", i + 1);
        printf("\t\t(0): ");
        printf("\t\t(%d): ", min(cont, oprt));
        cont = cont - min(cont, oprt);
        printf("\t\t(%d)", cont);
        printf("\t\t(%d)\n", drop);
    }
    return (0);
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

// 10. Write a program to implement DNS.

// SERVER

//////////////////	IMPLEMENT DNS	////////////

// Server Program : dnss.c

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

                                                                                                                                                                                                                           int
                                                                                                                                                                                                                           main()
{

    struct sockaddr_in server, client;
    int s, n;
    char b1[100], b2[100];

    struct hostent *hen;
    char *IPaddr;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 5000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(s, (struct sockaddr *)&server, sizeof(server));
    n = sizeof(client);
    printf("DNS is ready ..\n");
    while (1)
    {

        strcpy(b2, "");
        recvfrom(s, b1, sizeof b1, 0, (struct sockaddr *)&client, &n);

        hen = gethostbyname(b1);

        printf("\n Client request for Domain Name: %s \n", hen->h_name);
        IPaddr = inet_ntoa(*((struct in_addr *)hen->h_addr));

        printf("DNS IP address is:%s \n", IPaddr);
        strcpy(b2, IPaddr);

        sendto(s, b2, sizeof b2, 0, (struct sockaddr *)&client, n);
    }
    return 0;
}

//  output
/*
> gcc dnss.c

./a.out
DNS is ready ..

 Client request for Domain Name: google.com
DNS IP address is:142.250.193.142

 Client request for Domain Name: uvce.ac.in
DNS IP address is:134.209.146.145

 Client request for Domain Name: netflix.com
DNS IP address is:54.246.79.9

 Client request for Domain Name: wikipedia.com
DNS IP address is:103.102.166.226


*/

// CLIENT

// Client Program : dnsc.c

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
    struct sockaddr_in server, client;
    int s, n;
    char b1[100], b2[100];
    s = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 5000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    n = sizeof(server);

    while (1)
    {
        printf("\nEnter canonical Domain Name: ");
        scanf("%s", b2);
        sendto(s, b2, sizeof(b2), 0, (struct sockaddr *)&server, n);
        recvfrom(s, b1, sizeof(b1), 0, NULL, NULL);
        printf("%s \n", b1);
    }
    return 0;
}

// output

/*
> gcc dnsc.c
> ./a.out

Enter canonical Domain Name: google.com
142.250.193.142

Enter canonical Domain Name: uvce.ac.in
134.209.146.145

Enter canonical Domain Name: netflix.com
54.246.79.9

Enter canonical Domain Name: wikipedia.com
103.102.166.226

*/
