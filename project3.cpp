class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            int i;
            int j;
            int c=0;

            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == White ){
                    x = i;
                    y = j;
                    c++;
					return;
                }

        }
        //(i=4;i>=0;i--) for(j=5;j>=0;j--)
        	for(i=4;i>=0;i--) for(j=5;j>=0;j--){
                if(color[i][j] == inputColor){
                    x = i;
                    y = j;
                    c++;
					return;
                }


            }
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
    private:
        int x;
        int y;
    };
