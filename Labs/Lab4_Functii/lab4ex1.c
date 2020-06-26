    #include <stdio.h>                                                              
     
    int sum_recursive(int n)                                                        
    {                                                                               
        if (n == 0) {                                                           
            return 0;                                                       
        }  

        if(n % 2 != 0){

            n = 0;

            return sum_recursive(n);
        }

        return sum_recursive(n /10) + n % 10;                             
    }                                                                               
     
     
    int main(void)                                                                  
    {                                                                               
        int nr;                                                                 
     
        scanf("%d", &nr);                                                       
     
        printf("%d\n", sum_recursive(nr));                                      
     
        return 0;                                                               
    }

