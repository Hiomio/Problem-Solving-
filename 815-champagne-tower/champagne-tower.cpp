class Solution {

    double champ(int& poured , int i , int  j , vector <vector <double>>& dp){

        if(i == 0 && j == 0){
            return (double)poured;
        }

        if(dp[i][j] != -1)return dp[i][j];

        double aboveL = 0;
        double aboveR = 0;

        if(i > 0 && j > 0)aboveL = (champ(poured , i-1 , j -1 , dp) - 1.0)/2.0;
        if(i > 0 && j < i)aboveR = (champ(poured , i-1 , j , dp) - 1.0)/2.0;

        if(aboveL < 0)aboveL = 0;
        if(aboveR < 0)aboveR = 0;

        return dp[i][j] = aboveL + aboveR;

    }

public:
    double champagneTower(int poured, int i, int j) {

        vector <vector <double>> dp(i+1,vector <double> (j+1,-1));
        double ans = champ(poured , i, j , dp);
        if(ans > 1.0)return 1.0;
        return ans;

    }
};