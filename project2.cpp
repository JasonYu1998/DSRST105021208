#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <vector>
#include<fstream>
#include<cstdlib>

using namespace std;

queue<int> q1,qi,qc,qc2,tr,td,tl;
stack<int> s,si,sl;
vector<stack<int>> sU,sD,sL,sR,v1,v0;
vector<queue<int>> qU,qD,qL,qR,v2,qur,qul,qud,qlr,qld,qdr;
int T=0;

void change(queue<int> qc){
    int r=qc.size()/2;
    int *A= new int[r],*B= new int[r],i=0;
    while(!qc.empty()){A[i]=qc.front();qc.pop();B[i]=qc.front();qc.pop();i++;}
    for(int k=r-1;k>=0;k--){qc.push(A[k]);qc.push(B[k]);}
    delete [] A;delete [] B;
}
void change2(queue<int> qc2,int rx,int ry){
    int r=qc2.size()/2;
    int *A= new int[r],*B= new int[r],i=0;
    while(!qc2.empty()){A[i]=qc2.front();qc2.pop();B[i]=qc2.front();qc2.pop();i++;}
    qc2.push(rx);qc2.push(ry);
    for(int k=r-1;k>=0;k--){qc2.push(A[k]);qc2.push(B[k]);}
    delete [] A;delete [] B;
}

void combine(stack<int> &si,queue<int> &qi,queue<int> &qc){
    int a;
    while(!si.empty()){a=si.top();si.pop();qc.push(a);}
    while(!qi.empty()){a=qi.front();qi.pop();qc.push(a);}
}
void serch1(int **dist,int x,int y,int **visited,stack<int> &si){
    si.push(y);si.push(x);visited[x][y]=true;T++;
    if(dist[x][y]==0) return;
    else if(dist[x][y]>dist[x-1][y] && !visited[x-1][y]){serch1(dist,x-1,y,visited,si);}
    else if(dist[x][y]>dist[x+1][y] && !visited[x+1][y]){serch1(dist,x+1,y,visited,si);}
    else if(dist[x][y]>dist[x][y-1] && !visited[x][y-1]){serch1(dist,x,y-1,visited,si);}
    else if(dist[x][y]>dist[x][y+1] && !visited[x][y+1]){serch1(dist,x,y+1,visited,si);}
    else if(dist[x][y]>dist[x-1][y]  ){serch1(dist,x-1,y,visited,si);}
    else if(dist[x][y]>dist[x+1][y]  ){serch1(dist,x+1,y,visited,si);}
    else if(dist[x][y]>dist[x][y-1]  ){serch1(dist,x,y-1,visited,si);}
    else if(dist[x][y]>dist[x][y+1]  ){serch1(dist,x,y+1,visited,si);}

}
void serch2(int **dist,int x,int y,int **visited,queue<int> &qi,stack<int> &sl){
    qi.push(x);qi.push(y);visited[x][y]=true;T++;sl.push(y);sl.push(x);
    if(dist[x][y]==0) return;
    else if(dist[x][y]>dist[x-1][y] && !visited[x-1][y]){serch2(dist,x-1,y,visited,qi,sl);}
    else if(dist[x][y]>dist[x+1][y] && !visited[x+1][y]){serch2(dist,x+1,y,visited,qi,sl);}
    else if(dist[x][y]>dist[x][y-1] && !visited[x][y-1]){serch2(dist,x,y-1,visited,qi,sl);}
    else if(dist[x][y]>dist[x][y+1] && !visited[x][y+1]){serch2(dist,x,y+1,visited,qi,sl);}
    else if(dist[x][y]>dist[x-1][y]  ){serch2(dist,x-1,y,visited,qi,sl);}
    else if(dist[x][y]>dist[x+1][y]  ){serch2(dist,x+1,y,visited,qi,sl);}
    else if(dist[x][y]>dist[x][y-1]  ){serch2(dist,x,y-1,visited,qi,sl);}
    else if(dist[x][y]>dist[x][y+1]  ){serch2(dist,x,y+1,visited,qi,sl);}

}
void func(int **dist,int n,int m,int x,int y){
    int **visit = new int*[n+2];
    int *tmp = new int[(n+2)*(m+2)];
    for(int i=1;i<=n;i++) visit[i] = &(tmp[i*(m+2)]);
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			visit[i][j]=false;
		}
    }
    q1.push(x);q1.push(y);visit[x][y]=true;
    while(!q1.empty()){
        x=q1.front();q1.pop();y=q1.front();q1.pop();
        s.push(y);s.push(x);
        if(dist[x-1][y]==0 && !visit[x-1][y]){q1.push(x-1);q1.push(y);visit[x-1][y]=true;dist[x-1][y]=dist[x][y]+1;}
        if(dist[x+1][y]==0 && !visit[x+1][y]){q1.push(x+1);q1.push(y);visit[x+1][y]=true;dist[x+1][y]=dist[x][y]+1;}
        if(dist[x][y-1]==0 && !visit[x][y-1]){q1.push(x);q1.push(y-1);visit[x][y-1]=true;dist[x][y-1]=dist[x][y]+1;}
        if(dist[x][y+1]==0 && !visit[x][y+1]){q1.push(x);q1.push(y+1);visit[x][y+1]=true;dist[x][y+1]=dist[x][y]+1;}
    }
    delete [] tmp; delete [] visit;

}
int ti,tj,r1,r2;
bool found=false,turn[6];
stack<int> tmpr,tmpc;

void go(int ti, int tj, int r1, int r2, int B, int **dist, stack<int> &tmpr, stack<int> &tmpc, bool &found,int m,int n){

	if(found == false){
		if(ti == r1 && tj == r2 && dist[ti][tj] == 0){
			tmpr.push(ti); tmpc.push(tj);
			found = true;
		}
		else if(dist[ti][tj] == 0 && tmpr.size() < B)
		{
			dist[ti][tj] = m*n;
			tmpr.push(ti); tmpc.push(tj);

			go(ti+1,tj,r1,r2,B,dist,tmpr,tmpc,found,m,n);
			go(ti,tj+1,r1,r2,B,dist,tmpr,tmpc,found,m,n);
			go(ti,tj-1,r1,r2,B,dist,tmpr,tmpc,found,m,n);
			go(ti-1,tj,r1,r2,B,dist,tmpr,tmpc,found,m,n);

			dist[ti][tj] = 0;
			if(found == false){
				tmpr.pop();tmpc.pop();
			}
		}
	}
}
int main(int argc,char* argv[]){
    int i,j,B,co=0;
    int n,m,rx,ry;
    char c;
    queue<int> point;
    string str(argv[1]);
	ifstream data(str+"/floor.data");
    data>>n>>m>>B;
    int **dist = new int*[n+2];
    int *tmp = new int[(n+2)*(m+2)];
    for(i=0;i<n+2;i++) dist[i] = &(tmp[i*(m+2)]);
    for(i=0;i<n+2;i++) for(j=0;j<m+2;j++) dist[i][j]=0;
    for(j=1;j<=m;j++) { dist[0][j] = n*m; dist[n+1][j] = n*m; }
    for(i=1;i<=n;i++) {
        dist[i][0] = n*m;
        for(j=1;j<=m;j++){
            data>>c;
            if(c=='1') dist[i][j]=m*n;
            else if(c=='R'){dist[i][j]=m*n;rx=i;ry=j;}
            else dist[i][j]=0;
        }
        dist[i][m+1] = n*m;
    }
    data.close();
    go(rx,ry+1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);

    go(rx,ry+1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n); while(!tmpr.empty()){tmpr.pop();tmpc.pop();}//上到右是否有路徑
	turn[0] = found; found = false;
	go(rx+1,ry,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n); while(!tmpr.empty()){tmpr.pop();tmpc.pop();}//右到下是否有路徑
	turn[1] = found; found = false;
	go(rx,ry-1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n); while(!tmpr.empty()){tmpr.pop();tmpc.pop();}//下到左是否有路徑
	turn[2] = found; found = false;
	go(rx-1,ry,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n); while(!tmpr.empty()){tmpr.pop();tmpc.pop();}//左到上是否有路徑
	turn[3] = found; found = false;
	go(rx+1,ry,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n); while(!tmpr.empty()){tmpr.pop();tmpc.pop();}//上到下是否有路徑
	turn[4] = found; found = false;
	go(rx,ry+1,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n); while(!tmpr.empty()){tmpr.pop();tmpc.pop();}//左到右是否有路徑
	turn[5] = found; found = false;

    if(turn[0]){ //UR
		go(rx,ry+1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
		while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
    }
    else if(turn[4] && turn[1]){
        go(rx+1,ry,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
        tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
        found = false;
        go(rx,ry+1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
        tr.push(rx);tr.push(ry);
		while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
		}
    else if(turn[3] && turn[5]){
		go(rx,ry-1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry+1,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[4] && turn[2] && turn[5]){
		go(rx+1,ry,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry-1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry+1,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[3] && turn[2] && turn[1]){
		go(rx,ry-1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx+1,ry,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry+1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tr.push(rx);tr.push(ry);
        while(!tmpr.empty()){tr.push(tmpr.top());tmpr.pop();tr.push(tmpc.top());tmpc.pop();}
		found = false;
	}
    if(turn[1]){ //RD
		go(rx+1,ry,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[0] && turn[4]){
		go(rx-1,ry,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx+1,ry,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[5] && turn[2]){
		go(rx,ry-1,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx+1,ry,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[0] && turn[3] && turn[2]){
		go(rx-1,ry,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry-1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx+1,ry,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[5] && turn[3] && turn[4]){
		go(rx,ry-1,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx-1,ry,rx,ry-1,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx+1,ry,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		td.push(rx);td.push(ry);while(!tmpr.empty()){td.push(tmpr.top());tmpr.pop();td.push(tmpc.top());tmpc.pop();}
		found = false;
	}
    if(turn[2]){ //DL
		go(rx,ry-1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[4] && turn[3]){
		go(rx-1,ry,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry-1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[1] && turn[5]){
		go(rx,ry+1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry-1,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[4] && turn[0] && turn[5]){
		go(rx-1,ry,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry+1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry-1,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
	}
	else if(turn[1] && turn[0] && turn[3]){
		go(rx,ry+1,rx+1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx-1,ry,rx,ry+1,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
		go(rx,ry-1,rx-1,ry,B-1,dist,tmpr,tmpc,found,m,n);
		tl.push(rx);tl.push(ry);while(!tmpr.empty()){tl.push(tmpr.top());tmpr.pop();tl.push(tmpc.top());tmpc.pop();}
		found = false;
	}












    dist[rx][ry]=0;
    func(dist,n,m,rx,ry);
    int **visited = new int*[n+2];
    int *tmp1 = new int[(n+2)*(m+2)];
    for(int g=1;g<=n;g++) visited[g] = &(tmp1[g*(m+2)]);
    for(int g=1;g<=n;g++){
		for(int h=1;h<=m;h++){
			visited[g][h]=false;
		}
    }

    while(!s.empty()){
        int x,y;
        x=s.top(); s.pop();
        y=s.top(); s.pop();
        if(!visited[x][y]){
          serch1(dist,x,y,visited,si);
          serch2(dist,x,y,visited,qi,sl);
          qi.pop();qi.pop();
          int a1=si.top();si.pop();int a2=si.top();si.pop();int ax=si.top();si.pop();int ay=si.top();si.push(ax);si.push(a2);si.push(a1);
          int b1=sl.top();sl.pop();int b2=sl.top();sl.pop();int bx=sl.top();sl.pop();int by=sl.top();sl.push(bx);sl.push(b2);sl.push(b1);
          if(ax==bx && ay==by){
            if(ax==rx-1 && ay==ry) {sU.push_back(si);qU.push_back(qi);}//UU
            else if(ax==rx && ay==ry+1) {sR.push_back(si);qR.push_back(qi);}//RR
            else if(ax==rx+1 && ay==ry) {sD.push_back(si);qD.push_back(qi);}//DD
            else if(ax==rx && ay==ry-1) {sL.push_back(si);qL.push_back(qi);}//LL
          }
          else if(ax==rx-1 && ay==ry){//UX
            if(bx==rx && by==ry+1){combine(si,qi,qc);qur.push_back(qc);}
            if(bx==rx && by==ry-1){combine(si,qi,qc);qul.push_back(qc);}
            if(bx==rx+1 && by==ry){combine(si,qi,qc);qud.push_back(qc);}
          }
          else if(ax==rx && ay==ry-1){//L
            if(bx==rx && by==ry+1){combine(si,qi,qc);qlr.push_back(qc);}
            if(bx==rx-1 && by==ry){combine(si,qi,qc);change(qc);qul.push_back(qc);}
            if(bx==rx+1 && by==ry){combine(si,qi,qc);qld.push_back(qc);}
          }
          else if(ax==rx+1 && ay==ry){//D
            if(bx==rx && by==ry+1){combine(si,qi,qc);qdr.push_back(qc);}
            if(bx==rx-1 && by==ry){combine(si,qi,qc);change(qc);qud.push_back(qc);}
            if(bx==rx && by==ry-1){combine(si,qi,qc);change(qc);qld.push_back(qc);}
          }
          else if(ax==rx && ay==ry+1){//R
            if(bx==rx && by==ry-1){combine(si,qi,qc);change(qc);qlr.push_back(qc);}
            if(bx==rx-1 && by==ry){combine(si,qi,qc);change(qc);qur.push_back(qc);}
            if(bx==rx+1 && by==ry){combine(si,qi,qc);change(qc);qdr.push_back(qc);}
          }
          //v0.push_back(sl);
          //v1.push_back(si);
          //v2.push_back(qi);
          while(!si.empty()){si.pop();}
          while(!qi.empty()){qi.pop();}
          while(!qc.empty()){qc.pop();}

        }
        else continue;

    }
    stack<int> ss;


    //while(!qur.empty()){for(int i=qur.size()-1;i>=0;i--){change2(qur[i],rx,ry);qU.push_back(qc2);while(!qc2.empty()){qc2.pop();}}}
    //for(i=1;i<=n;i++) { for(j=1;j<=m-1;j++) cout<<setw(2)<<dist[i][j]<<" "; cout<<setw(2)<<dist[i][j]<<endl;}

    //for(int i=0;i<v1.size();i++){
            //cout<<T<<endl;
            //while(!v1[i].empty()){int t=v1[i].top();v1[i].pop();cout<<t<<" ";t=v1[i].top();v1[i].pop();cout<<t<<endl;}
            //while(v2[i].size()!=2){int t=v2[i].front();v2[i].pop();cout<<t<<" ";t=v2[i].front();v2[i].pop();cout<<t<<endl;}
            //v2[i].pop();v2[i].pop();
    //}
        for(int i=0;i<qU.size();i++){//UU
        if(i==0){sU[i].pop();sU[i].pop();}
        while(!sU[i].empty()){int t=sU[i].top();sU[i].pop();point.push(t);co++;t=sU[i].top();sU[i].pop();point.push(t);}
        while(qU[i].size()!=2){int t=qU[i].front();qU[i].pop();point.push(t);co++;t=qU[i].front();qU[i].pop();point.push(t);}
        qU[i].pop();qU[i].pop();
    }

        for(int i=0;i<qur.size();i++){while(!qur[i].empty()){int t1=qur[i].front();qur[i].pop();point.push(t1);co++;int t2=qur[i].front();qur[i].pop();point.push(t2);ss.push(t2);ss.push(t1);}ss.pop();ss.pop();while(ss.size()!=2){int t=ss.top();ss.pop();point.push(t);co++;t=ss.top();ss.pop();point.push(t);}ss.pop();ss.pop();} //RIGHT
        for(int i=0;i<qud.size();i++){while(!qud[i].empty()){int t1=qud[i].front();qud[i].pop();point.push(t1);co++;int t2=qud[i].front();qud[i].pop();point.push(t2);ss.push(t2);ss.push(t1);}ss.pop();ss.pop();while(ss.size()!=2){int t=ss.top();ss.pop();point.push(t);co++;t=ss.top();ss.pop();point.push(t);}ss.pop();ss.pop();} //LEFT
        		while(!tr.empty()){point.push(tr.front());co++;tr.pop();point.push(tr.front());tr.pop();}
        for(int i=0;i<qR.size();i++){//RR
        while(!sR[i].empty()){int t=sR[i].top();sR[i].pop();point.push(t);co++;t=sR[i].top();sR[i].pop();point.push(t);}
        while(qR[i].size()!=2){int t=qR[i].front();qR[i].pop();point.push(t);co++;t=qR[i].front();qR[i].pop();point.push(t);}
        qR[i].pop();qR[i].pop();
    }
        for(int i=0;i<qdr.size();i++){while(!qdr[i].empty()){int t1=qdr[i].front();qdr[i].pop();point.push(t1);co++;int t2=qdr[i].front();qdr[i].pop();point.push(t2);ss.push(t2);ss.push(t1);}ss.pop();ss.pop();while(ss.size()!=2){int t=ss.top();ss.pop();point.push(t);co++;t=ss.top();ss.pop();point.push(t);}ss.pop();ss.pop();} //RIGHT

                        while(!td.empty()){point.push(td.front());co++;td.pop();point.push(td.front());td.pop();}
        for(int i=0;i<qD.size();i++){//DD
        while(!sD[i].empty()){int t=sD[i].top();sD[i].pop();point.push(t);co++;t=sD[i].top();sD[i].pop();point.push(t);}
        while(qD[i].size()!=2){int t=qD[i].front();qD[i].pop();point.push(t);co++;t=qD[i].front();qD[i].pop();point.push(t);}
        qD[i].pop();qD[i].pop();
    }
                while(!tl.empty()){point.push(tl.front());co++;tl.pop();point.push(tl.front());tl.pop();}
        for(int i=0;i<qL.size();i++){//LL
        while(!sL[i].empty()){int t=sL[i].top();sL[i].pop();point.push(t);co++;t=sL[i].top();sL[i].pop();point.push(t);}
        while(qL[i].size()!=2){int t=qL[i].front();qL[i].pop();point.push(t);co++;t=qL[i].front();qL[i].pop();point.push(t);}
        qL[i].pop();qL[i].pop();
    }
        for(int i=0;i<qlr.size();i++){while(!qlr[i].empty()){int t1=qlr[i].front();qlr[i].pop();point.push(t1);co++;int t2=qlr[i].front();qlr[i].pop();point.push(t2);ss.push(t2);ss.push(t1);}ss.pop();ss.pop();while(ss.size()!=2){int t=ss.top();ss.pop();point.push(t);co++;t=ss.top();ss.pop();point.push(t);}ss.pop();ss.pop();} //LEFT
        for(int i=0;i<qul.size();i++){while(!qul[i].empty()){int t1=qul[i].front();qul[i].pop();point.push(t1);co++;int t2=qul[i].front();qul[i].pop();point.push(t2);ss.push(t2);ss.push(t1);}ss.pop();ss.pop();while(ss.size()!=2){int t=ss.top();ss.pop();point.push(t);co++;t=ss.top();ss.pop();point.push(t);}ss.pop();ss.pop();} //LEFT
        for(int i=0;i<qld.size();i++){while(!qld[i].empty()){int t1=qld[i].front();qld[i].pop();point.push(t1);co++;int t2=qld[i].front();qld[i].pop();point.push(t2);ss.push(t2);ss.push(t1);}ss.pop();ss.pop();while(ss.size()!=2){int t=ss.top();ss.pop();point.push(t);co++;t=ss.top();ss.pop();point.push(t);}ss.pop();ss.pop();} //LEFT



    point.push(rx);point.push(ry);co++;
    ofstream peak(str+"/final.path");
	peak << co <<endl;
	while(!point.empty()){
		peak << point.front() << " ";
		point.pop();
		peak << point.front() << endl;
		point.pop();
	}
    peak.close();
		return 0;

    //cout<<v1.size()<<endl<<sU.size()<<endl<<sR.size()+sD.size()+sL.size()<<endl<<qur.size()<<endl<<qul.size()<<endl<<qud.size()<<endl<<qlr.size()<<endl<<qld.size()<<endl<<qdr.size();

    delete [] dist; delete [] tmp;
    return 0;
}

