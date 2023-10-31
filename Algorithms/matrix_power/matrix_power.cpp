

#define MAX_N 2  //example for matrix fibonnaci numbers


struct Matrix { int mat[MAX_N[MAX_N]; };

Matrix matrixMultiplication(Matrix A, Matrix B) {
	Matrix ans; 
	for(int i=0; i<MAX_N; ++i) 
		for(int j=0; j<MAX_N; ++j) 
			for(int k=0; k<MAX_N; ++k) 
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
	return ans;
}

Matrix matrixPower(Matrix Base, int p) {
	Matrix ans;
	for(int i=0; i< MAX_N; ++i)
		for(int j=0; j< MAX_N; ++j)
			ans.mat[i][j] = (i==j);
	while(p) {
		if(p&1)
			ans = matrixMultiplication(ans, Base);
		Base = matrixMultiplication(Base, Base);
		p >>=1;
	}
	return ans;
}