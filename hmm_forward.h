typedef struct
{
int N; /* 隐藏状态数目;Q={1,2,...,N} */
int M; /* 观察符号数目; V={1,2,...,M}*/
double **A; /* 状态转移矩阵A[1..N][1..N]. a[i][j] 是从t时刻状态i到t+1时刻状态j的转移概率 */
double **B; /* 混淆矩阵B[1..N][1..M]. b[j][k]在状态j时观察到符合k的概率。*/
double *pi; /* 初始向量pi[1..N]，pi[i] 是初始状态概率分布 */
} HMM
