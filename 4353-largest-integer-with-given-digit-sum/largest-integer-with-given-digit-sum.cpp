class Solution {
public:
    int largestInteger(int n, int s) {
        int x = s;

        if( (9*n) < x) return -1;
        int w =0;
        int i =0;
        while(x)
        {   
            w = w*10;
            int z;
            z = (x>9)? 9 : x;
            x -=z;
            w +=z;
            i++;
        }
        while(i<n)
        {
            w = w*10;
            i++;
        }
        return w;
    }
};