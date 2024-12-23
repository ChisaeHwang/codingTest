N = input()       
cur = 0         
num = 1            

while cur != len(N):              
    num_string = str(num)            
    
    for i in range(len(num_string)):  
        if N[cur] == num_string[i]:
            cur += 1                
            if cur >= len(N):      
                print(num)         
                exit()              
    
    num += 1                    
