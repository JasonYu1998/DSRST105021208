#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <time.h> 
using namespace std;

int main(int argc,char* argv[]){
	int m,n,num=0;
    string str(argv[1]); 
	ifstream test(str+"/matrix.data");
test >> m >> n;
	int A[3*n+4];
	A[0]=-2147483648;
	for(int i=n+1;i<3*n+4;i++) A[i]=-2147483648;
	queue<int>point;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			test >> A[(n+1)*(i%3)+j+1];
			int z=(n+1)*(i%3)+j+1;
			if(i==0) continue;
			else if(i==1){
				if((z-n-1)%(n+1)==0 && A[z-(n+1)]>=A[z-(n+1)+1] && A[z-(n+1)]>=A[z] && A[z-(n+1)]>=A[(z)]) {num++;point.push(i);point.push(j+1);}
				else if ((z-(n+1))%(n+1)==(n+1)-1 && A[z-(n+1)]>=A[z-(n+1)-1] && A[z-(n+1)]>=A[z] && A[z-(n+1)]>=A[(z)]) {num++;point.push(i);point.push(j+1);}
				else if(A[z-(n+1)]>=A[z-(n+1)+1] && A[z-(n+1)]>=A[z-(n+1)-1] && A[z-(n+1)]>=A[z] && A[z-(n+1)]>=A[(z)]) {num++;point.push(i);point.push(j+1);}
			}
			else {
				if(i%3==0){
					if((z+2*(n+1))%(n+1)==0 && A[z+2*(n+1)]>=A[z+2*(n+1)+1] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)+(n+1)] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)+2*(n+1)]) {num++;point.push(i);point.push(j+1);}
					else if((z+2*(n+1))%(n+1)==(n+1)-1 && A[z+2*(n+1)]>=A[z+2*(n+1)-1] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)+(n+1)] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)+2*(n+1)]) {num++;point.push(i);point.push(j+1);}
					else if(A[z+2*(n+1)]>=A[z+2*(n+1)-1] && A[z+2*(n+1)]>=A[z+2*(n+1)+1] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)+(n+1)] && A[z+2*(n+1)]>=A[(z+2*(n+1))%(n+1)+2*(n+1)]) {num++;point.push(i);point.push(j+1);}
				}
				else {
					if((z-(n+1))%(n+1)==0 && A[z-(n+1)]>=A[z-(n+1)+1] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)+(n+1)] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)+2*(n+1)]) {num++;point.push(i);point.push(j+1);}
					else if((z-(n+1))%(n+1)==(n+1)-1 && A[z-(n+1)]>=A[z-(n+1)-1] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)+(n+1)] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)+2*(n+1)]) {num++;point.push(i);point.push(j+1);}
					else if(A[z-(n+1)]>=A[z-(n+1)+1] && A[z-(n+1)]>=A[z-(n+1)-1] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)+(n+1)] && A[z-(n+1)]>=A[(z-(n+1))%(n+1)+2*(n+1)]) {num++;point.push(i);point.push(j+1);}
				}
			}
		}
	
	}
	for(int j=1;j<n+1;j++){
	int z=((n+1)*((m-1)%3))+j;
	if((m-1)%3==0){
					if(j==0 && A[z]>=A[z+1] && A[z]>=A[z+2*(n+1)]) {num++;point.push(m);point.push(j);}
					else if(j==(n+1)-1 && A[z]>=A[z-1] && A[z]>=A[z+2*(n+1)]) {num++;point.push(m);point.push(j);}
					else if(A[z]>=A[z-1] && A[z]>=A[z+1] && A[z]>=A[z+2*(n+1)]) {num++;point.push(m);point.push(j);}
				}
	else {
					if(j==0 && A[z]>=A[z+1] && A[z]>=A[z-(n+1)]) {num++;point.push(m);point.push(j);}
					else if(j==(n+1)-1 && A[z]>=A[z-1] && A[z]>=A[z-(n+1)]) {num++;point.push(m);point.push(j);}
					else if(A[z]>=A[z-1] && A[z]>=A[z+1] && A[z]>=A[z-(n+1)]) {num++;point.push(m);point.push(j);}

				}
	}
	ofstream peak(str+"/final.peak");
	peak << num <<endl;
	while(!point.empty()){
		peak << point.front() << " ";
		point.pop();
		peak << point.front() << endl;
		point.pop();
	} 
    cout << (double)clock() / CLOCKS_PER_SEC << " S";
    peak.close();
		return 0;
}