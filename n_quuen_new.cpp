#include<iostream>
using namespace std;
int grid[10][10];
void print(int n) {
    for (int i = 0;i <= n-1; i++) {
        for (int j = 0;j <= n-1; j++) {
            
                cout <<grid[i][j]<< " ";
            
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
bool isSafe(int row, int col, int n) {
  //check for same column
    for (int i = 0; i < n; i++) {
        if (grid[row][i]) {
            return false;
        }
    }
    //check for same row
//    for (int i = 0; i < row; i++) {
//        if (grid[i][col]) {
//            return false;
//        }
//    }
    //check for upper left diagonal
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    //check for lower left diagonal
    for (int i = row, j = col; i <n  && j >= 0; j--, i++) {
        if (grid[i][j]) {
            return false;
        }
    }
    //check for Upper left diagonal
    for (int i = row,j = col;i >= 0 && j <n; i--,j++ ){
        if (grid[i][j]) {
            return false;
        }
    }
    //check for lower Right diagonal
    for (int i = row,j = col;i <n && j <n; i++,j++) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}

bool solve (int n, int col) {
    if (n == col) {
        print(n);
        return true;
    }
    for(int i=0; i<n; i++)
    {
    	if(grid[i][col]==1) return solve(n,col+1);	
	}
    //print(n);   
           
    bool res = false;
    for (int i = 0;i <=n-1;i++) {  // i is for row
        if (isSafe(i, col, n)) {
            grid[i][col] = 1;
            if(solve(n, col+1)) res=true;
            grid[i][col] = 0;
        }
    }
    //print(n);
    return res;
}
int main()
{
        int n, row, col;
        cout<<"Enter the number of queen :"<<endl;
        cin >> n;
        cout<<"Enter the coordinates :"<<endl;
		cin>>row>>col;
        
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
            	if(row==i && j==col) grid[i][j]=1;
                else grid[i][j] = 0;
            }
        }
        cout<<"\nInitial position of queen is\n";
        print(n);
        bool res = solve(n, 0);
        if(res == false) {
            cout <<"\nPlacing of queens does not exit !!" << endl; 
        } else {
            cout << endl;
        }
  return 0;
}
