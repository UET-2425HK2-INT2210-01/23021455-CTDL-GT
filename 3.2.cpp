Dùng vòng lap
Vonglap(n);
result <- 1
for i <- 1 to n do
    result <- result * 2
return result
Ð? ph?c tap: O(n)
Dùng de quy
Dequy(n):
	if n = 0 then 
	    return 1
    haft <- Dequy(n//2)
    if n is even then
         return half * half
    else 
         return half * half * 2
Ðo phuc tap: O(log n)

