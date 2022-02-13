#include "common.h"
using namespace std;
#define BUF_SIZE 1024
#define OPSZ 4
int calculate(int opnum, int opnds[], char op);

int main(int argc, char ** argv) {
    int serv_sock;
    int clnt_sock;
    char opinfo[BUF_SIZE];
    int result;
    int opnd_cnt;
    int recv_cnt;
    int recv_len;
    sockaddr_in serv_adr{}, clnt_adr{};
    socklen_t clnt_adr_sz;
    if (argc < 2) {
        cerr << "Usage:" << argv[0] << "<port>" << endl;
        exit(1);
    }
    serv_sock = socket(PF_INET, SOCK_STREAM,IPPROTO_TCP);
    if (serv_sock == -1){
        error_handling("socket() error!");
    }
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(std::stoi(argv[1]));
    if (bind(serv_sock,reinterpret_cast<sockaddr *>(&serv_adr), sizeof(serv_adr)) == -1){
        error_handling("bind() error!");
    }
    if(listen(serv_sock, 5) == -1)
    {
        error_handling("listen() error!");
    }
    clnt_adr_sz = sizeof(clnt_adr);
    for (int i = 0; i < 5; ++i ) {
        opnd_cnt = 0;
        clnt_sock = accept(serv_sock, reinterpret_cast < sockaddr * >(& clnt_adr), &clnt_adr_sz);
        cout << "Clients connected to: " << i + 1 << endl;

        cout << inet_ntoa(clnt_adr.sin_addr) << ":";
        printf("%#x\n",clnt_adr.sin_port);
        read(clnt_sock, &opnd_cnt,1);
        recv_len = 0;
        while ((opnd_cnt * OPSZ + 1) > recv_len){
            recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
            recv_len += recv_cnt;
        }
        result = calculate(opnd_cnt, (int *)opinfo, opinfo[recv_len - 1]);
        write(clnt_sock, (char*)&result, sizeof(result));
        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
int calculate(int opnum, int opnds[], char op){
    int result = opnds[0];
    switch (op) {
        case '+':
            for (int i = 1; i < opnum; i++) {
                result += opnds[i];
            }
            break;
        case '-':
            for (int i = 1; i < opnum; i++) {
                result -= opnds[i];
            }
            break;
        case '*':
            for (int i = 1; i < opnum; i++) {
                result *= opnds[i];
            }
            break;
        case '/':
            for (int i = 1; i < opnum; i++) {
                result /= opnds[i];
            }
            break;
    }
    return result;
}
