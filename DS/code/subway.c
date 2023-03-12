#include<stdio.h>
#include<string.h>

#define max_length 20//��ʾ�ַ�������
#define max_station 500//��ʾ������վ��
#define INFINITY 32767//����

struct station{
	char name[max_length];//վ������ 
	int state;//����״̬��0 �ǻ��ˣ�1 ���� 
}sta[max_station];
//��վ��

struct weight{
	int wei;//Ȩ�أ��������Ϊ��վ��֮������վ�� 
	int line;//��վ������·�����ߺ� 
}vertex[max_station+5][max_station+5];
//���Ȩ��

FILE *in;

int k,spath[max_station];//spath[]�����·��

void read(){
	in=fopen("bgstations.txt","r");
	int max_line;
	fscanf(in,"%d",&max_line);
	int i,j,v1,v2;
	//��ʼ�� 
	for(i=1;i<=max_station;i++){
		for(j=1;j<=max_station;j++){
			vertex[i][j].wei=INFINITY;
			vertex[i][j].line=0;
		}
	}
	
	for(i=1;i<=max_line;i++){
		int line_num,station_num;
		v1=v2=-1;      //ǰ������վ��
		fscanf(in,"%d%d",&line_num,&station_num);
		for(j=1;j<=station_num;j++){
			//�жϸ�վ���Ƿ���֮ǰ����
			char s[max_station];
			int ii,flag=1,change;
			fscanf(in,"%s%d",s,&change);
			for(ii=1;ii<=k;ii++){
				if(strcmp(sta[ii].name,s)==0){//����
					flag=0;
					v1=ii;
					break;
				}
			}
			if(flag){//û����
				k++;
				strcpy(sta[k].name,s);
				sta[k].state=change;
				v1=k;
			}
			if(v2!=-1){//��ʾ��ǰ�����v1�㲻�Ǹ���·�ĵ�һ����
				vertex[v1][v2].line=vertex[v2][v1].line=line_num;
				vertex[v1][v2].wei=vertex[v2][v1].wei=1;
			}
			v2=v1;//��¼��ǰ�㣬֮�������������Ƚ�
		}
	}
	fclose(in);
}

//Dijkstra�㷨
void Dijkstra(int origion,int destination){
	int i,j,v=0;
	int minweight;
	int found[max_station+5]; // ����Ƿ��Ѿ�ȷ����̾���
	memset(found,0,sizeof(found[0])*max_station); // ��ʼ��
	int sweight[max_station+5]; // ����̾���
	
	for(i=1;i<=max_station;i++){ // ��ʼ��
		sweight[i]=vertex[origion][i].wei;
		spath[i]=origion;// i ��ǰ�����Ϊ origion 
	}
	sweight[origion]=0;//��Ǿ��� 
	found[origion]=1;//������ҵ� 
	for(i=1;i<max_station;i++){//��Ҫ��max_station-1����� 
		minweight=INFINITY;
		for(j=1;j<=max_station;j++){
			if(!found[j]&&sweight[j]<minweight){
				minweight=sweight[j];
				v=j;
			}
		}
		found[v]=1;
		if(v==destination)	return ;// ����Ŀ�ĵ�
		for(j=1;j<=max_station;j++){
			if( (!found[j]) && (vertex[v][j].line>0) && (minweight+vertex[v][j].wei<sweight[j]) ){
				sweight[j]=minweight+vertex[v][j].wei;
				spath[j]=v;// j ��ǰ��Ϊ v 
				//spath������Ϊ�ؼ�
			}
		}
	}
}

void print(int origion,int destination){ // �������Ҫ��spath������з����ȡ
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
