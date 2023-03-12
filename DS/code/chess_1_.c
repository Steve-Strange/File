#include <stdio.h>

int sheet[22][22];
int main()
{
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<22;j++)
		{
			sheet[i][j]=-1;
		}
	}
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=19;j++)
		{
			scanf("%d",&sheet[i][j]);
		}
	}

//	int cnt[3]={0};
//	
//	for(int i=1;i<=19;i++)
//	{
//		for(int j=1;j<=19;j++)
//		{
//			if(sheet[i][j]==1) cnt[1]++;
//			if(sheet[i][j]==2) cnt[2]++;
//		}
//	}
//	
//	int turn;
//	if(cnt[1]==cnt[2]) turn=1;
//	else turn=2;
//	

	for(int turn=1;turn<=2;turn++)
	{
		
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=19;j++)
		{
			if(sheet[i][j]==turn)
			{
				int flag=1;
				for(int k=1;k<4;k++)
				{
					if(sheet[i+k][j]!=turn)
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					if(sheet[i-1][j]*sheet[i+4][j]!=0) flag=0;
				}
				if(flag)
				{
					printf("%d:%d,%d\n",turn,i,j);
					return 0;
				}


				flag=1;
				for(int k=1;k<4;k++)
				{
					if(sheet[i][j+k]!=turn)
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					if(sheet[i][j-1]*sheet[i][j+4]!=0) flag=0;
				}
				if(flag)
				{
					printf("%d:%d,%d\n",turn,i,j);
					return 0;
				}


				flag=1;
				for(int k=1;k<4;k++)
				{
					if(sheet[i+k][j+k]!=turn)
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					if(sheet[i-1][j-1]*sheet[i+4][j+4]!=0) flag=0;
				}
				if(flag)
				{
					printf("%d:%d,%d\n",turn,i,j);
					return 0;
				}

				
				flag=1;
				for(int k=1;k<4;k++)
				{
					if(sheet[i+k][j-k]!=turn)
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					if(sheet[i-1][j+1]*sheet[i+4][j-4]!=0) flag=0;
				}
				if(flag)
				{
					printf("%d:%d,%d\n",turn,i,j);
					return 0;
				}

			}
		}
	}
	}
	printf("No\n");
	return 0;
}



