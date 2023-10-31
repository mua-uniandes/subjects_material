MAX_N = 2 #change for larger matrices

def multiply(A, B):
	ans = [[0 for i in range(MAX_N)] for j in range(MAX_N)] 
	for i in range(MAX_N): 
		for j in range(MAX_N): 
			for k in range(MAX_N):
				ans.mat[i][j] += A[i][k] * B[k][j];
	return ans;


def power(F, n):
    if n <= 1:
        return
    power(F, n // 2)
    multiply(F, F)
    if n % 2 != 0:
        F = multiply(F, F)
    



