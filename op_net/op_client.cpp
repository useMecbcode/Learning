//
// Created by dev on 25/1/2022.
//
#include "common.h"
#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4
using namespace std;
int main(int argc, char **argv){
    int sock;
    char opmsg[BUF_SIZE];
    int result;
    int opnd_cnt;
    sockaddr_in serv_adr{};
    if (argc != 3){
        cerr << "Usage: " << argv[0] << "<IP> <port>" << endl;
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == -1){
        error_handling("socket() error!");
    }
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(std::stoi(argv[2]));

    if (connect(sock, reinterpret_cast<sockaddr *>(&serv_adr), sizeof(serv_adr)) == -1){
        error_handling("connect() error!");
    }else {
        cout << "Connected......" << endl;
    }
    cout << "Operand Count: " ;
    cin >> opnd_cnt;
    opmsg[0] = static_cast<char>(opnd_cnt);
    for (int i = 0; i < opnd_cnt; ++i) {
        cout << "Operand " << i + 1 << ":";
        scanf("%d",reinterpret_cast<int*>(&opmsg[i * OPSZ + 1]));
    }
    fgetc(stdin);
    fputs("Operator: ", stdout);
    scanf("%c", &opmsg[opnd_cnt * OPSZ + 1]);
    write(sock, opmsg, opnd_cnt * OPSZ + 2);
    read(sock, &result, RLT_SIZE);
    cout << "Operation result:" << result;
    return 0;

}