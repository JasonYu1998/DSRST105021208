class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            int i;
            int j;
            int c=0;
            Color otherColor;

            if(inputColor == Red) otherColor = Blue;
            else if(inputColor == Blue) otherColor = Red;



            if(color[0][0] == White ){
                    x = 0;
                    y = 0;
                    c++;
                    return;
                }
            else if(color[0][5] == White ){
                    x = 0;
                    y = 5;
                    c++;
                    return;
                }
            else if(color[4][0] == White ){
                    x = 4;
                    y = 0;
                    c++;
                    return;
                }
			else if(color[4][5] == White ){
                    x = 4;
                    y = 5;
                    c++;
					return;
                }
            else if(color[0][2] == White ){
                    x = 0;
                    y = 2;
                    c++;
					return;
                }
            else if(color[4][2] == White ){
                    x = 4;
                    y = 2;
                    c++;
					return;
                }
            else if(color[1][1] == White ){
                    x = 1;
                    y = 1;
                    c++;
					return;
                }
            else if(color[4][3] == White ){
                    x = 4;
                    y = 3;
                    c++;
					return;
                }
            else if(color[2][0] == White ){
                    x = 2;
                    y = 0;
                    c++;
					return;
                }
            else if(color[2][5] == White ){
                    x = 2;
                    y = 5;
                    c++;
					return;
                }
            else if(color[2][2] == White ){
                    x = 2;
                    y = 2;
                    c++;
					return;
                }
            else if(color[2][3] == White ){
                    x = 2;
                    y = 3;
                    c++;
					return;
                }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == inputColor ){
                	if((color[i+1][j] == otherColor && ((Max[i][j]-Record[i][j]) == (Max[i+1][j]-Record[i+1][j]))) ||
					   (color[i-1][j] == otherColor && ((Max[i][j]-Record[i][j]) == (Max[i-1][j]-Record[i-1][j]))) ||
					   (color[i][j+1] == otherColor && ((Max[i][j]-Record[i][j]) == (Max[i][j+1]-Record[i][j+1]))) ||
					   (color[i][j-1] == otherColor && ((Max[i][j]-Record[i][j]) == (Max[i][j-1]-Record[i][j-1])))){
                    x = i;
                    y = j;
                    c++;
					return;
                }
                }
            }

			for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == inputColor && (Record[i][j] < Max[i][j])-1 ) {
                    x = i;
                    y = j;
                    c++;
					return;
                }

        }
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
