


const int mod = 1e9+7;
int binpow(int a,int p){
	int r = 1;
	while( n ){
		if( n & 1 ){
			r *= a;
			r %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return r;
}
int add(int x,int y){
	int z = x + y;
	if( z >= mod ){
		z -= mod;
	}
	return z;
}
int sub(int x,int y){
	x-=y;
	if( x < 0 ){
		x+=mod;
	}
	return x;
}
int mul(int x,int y){
	return x * y % mod;
}
int div(int x,int y){
	return mul(x,binpow(y,mod-2));
}
