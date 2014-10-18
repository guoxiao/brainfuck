#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return -1;
    }

    char* filename = argv[1];
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }

    int ch;
    puts("#include <stdio.h>\nint main(){");
    puts("char s[10000] = {0};");
    puts("char p = 0;");
    while ((ch = getc(f)) != EOF) {
        switch (ch) {
            case '+':
                puts("s[p] ++;");
                break;
            case '-':
                puts("s[p] --;");
                break;
            case '>':
                puts("p++;");
                break;
            case '<':
                puts("p--;");
                break;
            case '[':
                puts("while(s[p]){");
                break;
            case ']':
                puts("}");
                break;
            case '.':
                puts("putchar(s[p]);");
                break;
            case ',':
                puts("s[p] = getc();");
                break;
            default:
                break;
        }
    }
    puts("}\n");
    fclose(f);
}
