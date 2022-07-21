 double pow(double x ,int n)
    {
        if(n==0)
            return 1;
        double temp=pow(x,n/2);
        if(n%2!=0)
            return temp*temp*x;
        return temp*temp;
    }
    double myPow(double x, int n) {
        if(n>=0)
            return pow(x,n);
        else
            return 1/pow(x,abs(n));
    }