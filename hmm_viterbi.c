void Viterbi(HMM *phmm, int T, int *O, double **delta, int **psi, int *q,double *pprob)
{
	int i,j; //状态索引
	int t;   //时间索引
	
	int maxvalind;
	double maxval,val;
	
	//初始化
	for (i=1; i<=phmm->N;i++)
	{
		delta[1][i] = phmm->pi[i] * (phmm->B[i][O[1]]);
		psi[1][i] = 0;
	}
	
	//递归
	for (t = 2; t<=T;t++)
	{
		for(j=1;j<=phmm->N; j++)
		{
			maxval = 0.0;
			maxvalind = 1;
			for (i=1; i<=phmm->N; i++)
			{
				val = delta[t-1][i] * (phmm->A[i][j]);
				if (val > maxval)
				{
					maxval = val;
					maxvalind = i;
				}	
			}
			delta[t][j] = maxval * (phmm->B[j][O[t]]);
			psi[t][j] = maxvalind;
		}
	}
	
	//终止
	*pprob =0.0;
	q[T] = 1;
	for (i=1; i<=phmm->N; i++)
	{
		if (delta[T][i] > *pprob)
		{
			*pprob = delta[T][i];
			q[T] = i;
		}
	}
	
	//回溯
	for (t=T-1;t >= 1; t--)
		q[t] = psi[t+1][q[t+1]];
	
	
	
}
