#include <stdio.h>
#include <stdint.h> // for uint32_t
#include <netinet/in.h> // for ntohl

void usage() {
    printf("example : ./add_nbo file1.bim file2.bin \n");
}

uint32_t read_file(char *argv) {

    FILE *a;
    uint32_t by_data, by_result;
    int by_len;

    a = fopen(argv,"rb");
    if ( a == NULL ) {
        printf("file open error! ");
    }

    by_len = fread(&by_data,4,1,a);
    if (by_len==1) {  // 4바이트라면 한번만 읽는다!
        by_result = ntohl(by_data);
	fclose(a);
        return by_result;
    }
    else  {
        printf("please 4byte file!");
        return -1;
    }
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        usage();
        return -1;
    }

    uint32_t n1,n2;

    n1 = read_file(argv[1]);
    n2 = read_file(argv[2]);

    printf("%d(%#x) + %d(%#x) = %d(%#x)\n",n1,n1,n2,n2,n1+n2,n1+n2);

}

