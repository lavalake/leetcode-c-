#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** fizzBuzz(int n, int* returnSize) {

    char **result = (char**)malloc(sizeof(char*)*n);

    int exp = 1;

    int len = 0;

    for (int i=1; i<=n; i++) {
    
            int temp = i;
    
            while (temp) {
	    
	                exp++;
	    
	                temp /= 10;
	    
	            }
    
            if (i%3 == 0 && i%5 == 0) {
	    
	                len = 9;
	    
	                result[i-1] = (char*)malloc(len);
	    
	                strncpy(result[i-1],"FizzBuzz",len);
	    
	                
	    
	            } else if (i%3 == 0) {
		    
		                len = 5;
		    
		                result[i-1] = (char*)malloc(len);
		    
		                strncpy(result[i-1],"Buzz",len);
		    
		                
		    
		            } else if (i%5 == 0) {
			    
			                len = 5;
			    
			                result[i-1] = (char*)malloc(len);
			    
			                strncpy(result[i-1],"Buzz",len);
			    
			                
			    
			            } else {
				    
				                len = exp;
				    
				                result[i-1] = (char*)malloc(len);
				    
				                snprintf(result[i-1],len,"%d",i);
				    
				            }
    
            //result[i-1][len] = '\0';
    
            
    
        }
    *returnSize = n;
    return result;

}

int main()
{
	int size;
        fizzBuzz(5,&size);
	return 0;
}
