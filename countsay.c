#include <stddef.h>
#include <stdlib.h>
char* countAndSay(int n) {

    char *buf1 = NULL;

    char *buf2 = NULL;

    char *result = NULL;

    char *next = NULL;

    int len = 1;

    

    

    buf1 = (char*)malloc(sizeof(char)*1024000);

    buf2 = (char*)malloc(sizeof(char)*1024000);

    result = buf2;

    next = buf1;

    result[0] = '1';

    result[1] = '\0';

    while (--n) {
    
            char *temp = result;
    
            int result_index=0;
    
            result = next;
    
            next = temp;
    
    
            for (int i=0; i<len; i++) {
            int count=1;
	    
	                while (i+1 < len && next[i] == next[i+1]) {
			
			                count++;
			
			                i++;
			
			            }
	    
	                result[result_index++] = '0' + count;
	    
	                result[result_index++] = next[i];
	    
	            }
    
            len = result_index;
    
            result[result_index] = '\0';
    
        }

    

    return result;

}
int main()
{
	countAndSay(6);
}
