#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_TIME

enum TokenizerMode {
    WHITESPACE,
    NUMBER
};

bool is_digit(char c){
    return c >= '0' && c <= '9';
}

double sec(){
    return clock()/(double)CLOCKS_PER_SEC;
}

int main() {

#ifdef PRINT_TIME
    double t = sec();
#endif

    int *numbers = new int[16*1024*1024];

    size_t n_numbers = 0;

    TokenizerMode mode = NUMBER;

    mode = WHITESPACE;
    int x = 0;

    size_t buffer_size = 16*1024*1024;
    char *buffer = new char[buffer_size + 1];

    while (1){
        size_t n = fread(buffer, 1, buffer_size, stdin);

        if (n == 0) break;

        for (size_t i = 0; i < n; i++){
            char c = buffer[i];
            switch (mode){
            case NUMBER:
                if (!is_digit(c)){
                    buffer[i] = '\0';
                    numbers[n_numbers++] = x;
                    mode = WHITESPACE;
                }else{
                    x *= 10;
                    x += c - '0';
                }
                break;
            case WHITESPACE:
                if (is_digit(c)){
                    x = c - '0';
                    mode = NUMBER;
                }
                break;
            }
        }
    }

    for (size_t i = 0; i < n_numbers; ){

        int N = numbers[i++];
        int M = numbers[i++];

        int duplicates = 0;

        if (N == 0 && M == 0) break;

        int b = 0;
        for (int a = 0; a < N; a++){

            int x = numbers[i + a];

            while (b < M){
                int y = numbers[i + N + b];
                if (x < y) break;
                if (x == y) duplicates++;
                b++;
            }
        }

        printf("%i\n", duplicates);

        i += M + N;
    }

#ifdef PRINT_TIME
    double dt = sec() - t;
    printf("%f seconds\n", dt);
#endif

	return 0;
}


/*

  [00:06:52] <zebbiz> can you explain why yours is so much faster than mine?
  [00:07:54] <Waynes> yes
  [00:08:18] <Waynes> here's the one with stdin for completeness sake http://pastebin.com/Ni1sKUxf
  [00:08:26] <Waynes> doesn't work with copy&paste though, only piping
  [00:08:32] <Waynes> yours uses cin which is slow
  [00:08:42] <Waynes> mine uses fread which is faster
  [00:08:50] <Waynes> that's pretty much it
  [00:09:02] <Waynes> except I also parse the numbers myself
  [00:09:10] <Waynes> and for some reason the standard functions for that suck
  [00:09:50] <zebbiz> whats' with the enum mode?
  [00:10:24] <Waynes> I read stdin as raw bytes so I have to parse the numbers by hand
  [00:10:33] <Waynes> to do that I have to find out what's number and what's whitespace


*/
