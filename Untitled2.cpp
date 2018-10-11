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
	int A[3*n];
	queue<int>point;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			test >> A[n*(i%3)+j];
			int z=n*(i%3)+j;
			if(i==1){
				if(A[z-n]>=A[z-n+1] && (z-n)%n==0 && A[z-n]>=A[z] && A[z-n]>=A[(z)]) {num++;point.push(i);point.push(j);}
				else if (A[z-n]>=A[z-n-1] && (z-n)%n==n-1 && A[z-n]>=A[z] && A[z-n]>=A[(z)]) {num++;point.push(i);point.push(j);}
				else if(A[z-n]>=A[z-n+1] && A[z-n]>=A[z-n-1] && A[z-n]>=A[z] && A[z-n]>=A[(z)]) {num++;point.push(i);point.push(j);}
			}
			if(i>1){
				if(i%3==0){
					if((z+2*n)%n==0 && A[z+2*n]>=A[z+2*n+1] && A[z+2*n]>=A[(z+2*n)%n] && A[z+2*n]>=A[(z+2*n)%n+n] && A[z+2*n]>=A[(z+2*n)%n+2*n]) {num++;point.push(i);point.push(j);}
					else if((z+2*n)%n==n-1 && A[z+2*n]>=A[z+2*n-1] && A[z+2*n]>=A[(z+2*n)%n] && A[z+2*n]>=A[(z+2*n)%n+n] && A[z+2*n]>=A[(z+2*n)%n+2*n]) {num++;point.push(i);point.push(j);}
					else if(A[z+2*n]>=A[z+2*n-1] && A[z+2*n]>=A[z+2*n+1] && A[z+2*n]>=A[(z+2*n)%n] && A[z+2*n]>=A[(z+2*n)%n+n] && A[z+2*n]>=A[(z+2*n)%n+2*n]) {num++;point.push(i);point.push(j);}
				}
				else {
					if((z-n)%n==0 && A[z-n]>=A[z-n+1] && A[z-n]>=A[(z-n)%n] && A[z-n]>=A[(z-n)%n+n] && A[z-n]>=A[(z-n)%n+2*n]) {num++;point.push(i);point.push(j);}
					else if((z-n)%n==n-1 && A[z-n]>=A[z-n-1] && A[z-n]>=A[(z-n)%n] && A[z-n]>=A[(z-n)%n+n] && A[z-n]>=A[(z-n)%n+2*n]) {num++;point.push(i);point.push(j);}
					else if(A[z-n]>=A[z-n+1] && A[z-n]>=A[z-n-1] && A[z-n]>=A[(z-n)%n] && A[z-n]>=A[(z-n)%n+n] && A[z-n]>=A[(z-n)%n+2*n]) {num++;point.push(i);point.push(j);}
				}
			}
		}
	
	}
	for(int j=0;j<n;j++){
	int z=n*((m-1)%3)+j;
	if((m-1)%3==0){
					if(j==0 && A[z]>=A[z+1] && A[z]>=A[z+2*n]) {num++;point.push(m);point.push(j);}
					else if(j==n-1 && A[z]>=A[z-1] && A[z]>=A[z+2*n]) {num++;point.push(m);point.push(j);}
					else if(A[z]>=A[z-1] && A[z]>=A[z+1] && A[z]>=A[z+2*n]) {num++;point.push(m);point.push(j);}
				}
	else {
					if(j==0 && A[z]>=A[z+1] && A[z]>=A[z-n]) {num++;point.push(m);point.push(j);}
					else if(j==n-1 && A[z]>=A[z-1] && A[z]>=A[z-n]) {num++;point.push(m);point.push(j);}
					else if(A[z]>=A[z-1] && A[z]>=A[z+1] && A[z]>=A[z-n]) {num++;point.push(m);point.push(j);}
 
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
		return 0;
}