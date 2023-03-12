#include<stdio.h>
#include<string.h>

#define max_length 20//表示字符串长度
#define max_station 500//表示最多地铁站数
#define INFINITY 32767//大数

struct station{
	char name[max_length];//站点名称 
	int state;//换乘状态，0 非换乘，1 换乘 
}sta[max_station];
//存站点

struct weight{
	int wei;//权重，可以理解为两站点之间的相差站数 
	int line;//两站点间的线路所在线号 
}vertex[max_station+5][max_station+5];
//存边权重

FILE *in;

int k,spath[max_station];//spath[]数组存路径

void read(){
	in=fopen("bgstations.txt","r");
	int max_line;
	fscanf(in,"%d",&max_line);
	int i,j,v1,v2;
	//初始化 
	for(i=1;i<=max_station;i++){
		for(j=1;j<=max_station;j++){
			vertex[i][j].wei=INFINITY;
			vertex[i][j].line=0;
		}
	}
	
	for(i=1;i<=max_line;i++){
		int line_num,station_num;
		v1=v2=-1;      //前后两个站点
		fscanf(in,"%d%d",&line_num,&station_num);
		for(j=1;j<=station_num;j++){
			//判断该站点是否是之前读过
			char s[max_station];
			int ii,flag=1,change;
			fscanf(in,"%s%d",s,&change);
			for(ii=1;ii<=k;ii++){
				if(strcmp(sta[ii].name,s)==0){//读过
					flag=0;
					v1=ii;
					break;
				}
			}
			if(flag){//没读过
				k++;
				strcpy(sta[k].name,s);
				sta[k].state=change;
				v1=k;
			}
			if(v2!=-1){//表示当前读入的v1点不是该线路的第一个点
				vertex[v1][v2].line=vertex[v2][v1].line=line_num;
				vertex[v1][v2].wei=vertex[v2][v1].wei=1;
			}
			v2=v1;//记录当前点，之后读入可以用来比较
		}
	}
	fclose(in);
}

//Dijkstra算法
void Dijkstra(int origion,int destination){
	int i,j,v=0;
	int minweight;
	int found[max_station+5]; // 标记是否已经确定最短距离
	memset(found,0,sizeof(found[0])*max_station); // 初始化
	int sweight[max_station+5]; // 存最短距离
	
	for(i=1;i<=max_station;i++){ // 初始化
		sweight[i]=vertex[origion][i].wei;
		spath[i]=origion;// i 的前驱结点为 origion 
	}
	sweight[origion]=0;//标记距离 
	found[origion]=1;//标记已找到 
	for(i=1;i<max_station;i++){//还要找max_station-1个结点 
		minweight=INFINITY;
		for(j=1;j<=max_station;j++){
			if(!found[j]&&sweight[j]<minweight){
				minweight=sweight[j];
				v=j;
			}
		}
		found[v]=1;
		if(v==destination)	return ;// 到达目的地
		for(j=1;j<=max_station;j++){
			if( (!found[j]) && (vertex[v][j].line>0) && (minweight+vertex[v][j].wei<sweight[j]) ){
				sweight[j]=minweight+vertex[v][j].wei;
				spath[j]=v;// j 的前驱为 v 
				//spath数组至为关键
			}
		}
	}
}

void print(int origion,int destination){ // 输出，需要对spath数组进行反向读取
	int i=destination,j=1;
	int temp[max_station];
	for(i=destination,j=0;i!=origion;){
		temp[++j]=spath[i];
		i=spath[i];
	}
	int flag=0,cnt=1;
	temp[0]=destination;
	for(i=j;i>=1;i--){
		if(flag == 0) {
			printf("%s-%d",sta[temp[i]].name,vertex[temp[i]][temp[i-1]].line);
			flag=1;
		}
		else{
			if(vertex[temp[i+1]][temp[i]].line==vertex[temp[i]][temp[i-1]].line){
				cnt++;
			}
			else{
				printf("(%d)-",cnt);
				cnt=1;
				flag=0;
				i++;
			}
		}
	}
	printf("(%d)-%s\n",cnt,sta[destination].name);
}

int main()
{
	read();
	char start[max_length],end[max_length];
	scanf("%s%s",start,end);
	int origion=0,destination=0,cnt=0;
	int i;
	for(i=1;i<=k;i++){
		if(strcmp(sta[i].name,start) == 0){
			origion=i;
			cnt++;
		}
		if(strcmp(sta[i].name,end) == 0){
			destination=i;
			cnt++;
		}
		if(cnt==2) break;
	}
	Dijkstra(origion,destination);
	print(origion,destination);
	return 0;
}
