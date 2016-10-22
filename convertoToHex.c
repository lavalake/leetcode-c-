#include <stdlib.h>
void reverse(char *str, int len);

char* toHex(int num) {

    char *result = (char*)malloc(sizeof(char)*9);

    char look_up[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    unsigned int rmn = (unsigned int)num;

    int index = 0;

    while (rmn) {
    
            result[index++] = look_up[rmn%16];
    
            rmn /= 16;
    
        }

    result[index] = '\0';

    reverse(result, index-1);

    return result;

}

void reverse(char *str, int len)

{

    for (int i=0; i<len/2; i++) {
    
            char temp = str[i];
    
            str[i] = str[len - i -1];
    
            str[len - i -1] = temp;
    
        }

}

int main()
{
	int test = 26;
	toHex(test);
	return 0;


}
