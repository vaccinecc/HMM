/*
　函数参数说明：
　*phmm：已知的HMM模型；T：观察符号序列长度；
　*O：观察序列；**alpha：局部概率；*pprob：最终的观察概率
*/
void Forward(HMM *phmm,int T,int *O,double **alpha,double *pprob)
{
	int i,j; //状态索引
	int t;	 //时间索引
	double sum;		//求局部概率时的中间值
	
	//1.初始化：计算t=1时刻所有状态的局部概率
	for (i = 1; i<=phmm->N; i++)
		alpha[1][i] = phmm->pi[i] * phmm->B[i][O[1]];
	
	//2.递归：递归计算每一个时间点的局部概率
	for (t=1; t<T;t++)
	{
		for (j = 1; j<=phmm->N;j++)
		{
			sum = 0.0;
			for(i=1;i<=phmm->N;i++)
				sum += alpha[t][i] * (phmm->A[i][j]);
			alpha[t+1][j] = sum * (phmm->B[j][O[t+1]]);
		}
	}
	
	//终止：观察序列的概率等于T时刻所有局部概率之和
	*pprob = 0.0;
	for(i=1;i<phmm->N;i++)
		*pprob += alpha[T][i];
}
