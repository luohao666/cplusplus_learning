#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char* argv[])
{
    cout<<"io test"<<endl;

  int m, n, i, j; //n为行数，m为列数
  cin >> n >> m;
  int map[n][m];
  int mark[n][m];
//输入
  for(i = 0 ; i < n; i ++)
    for(j = 0 ; j < m ; j ++){
      cin >> map[i][j];
      mark[i][j] = map [i][j];
    }

//判断
  for(i = 0 ; i < n ; i ++)
    for(j = 0 ; j < m ; j++){
      if(j + 2 < m) //判断随后是否有2个数
        if(map[i][j] == map[i][j + 1] && map[i][j + 1] == map[i][j + 2]){//横行判断
          mark[i][j] = 0;
          mark[i][j + 1] = 0;
          mark[i][j + 2] = 0;
        }
      if(i + 2 < n)//判断随后是否有2个数
        if(map[i][j] == map[i + 1][j] && map[i + 1][j] == map[i + 2][j]){//竖行判断
          mark[i][j] = 0;
          mark[i + 1][j] = 0;
          mark[i + 2][j] = 0;
        }
    }
    
//下沉
    i=n-1;
    for(j = 0; j < m ; j ++)
    {
        if(mark[i][j]==0)
        {
            for(int k=i;k>0;k--)
            {
                mark[k][j]=mark[k-1][j];
            }
            mark[0][j]=-1;
        }
        else
            i--;
        
    }


//输出
  for(i = 0 ; i < n; i ++){
    for(j = 0 ; j < m ; j ++)
     cout << mark[i][j] << " ";
    cout << endl;
  }


    return 0;
}
