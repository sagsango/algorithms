//  https://codeforces.com/contest/1285/submission/68510783
int mxsum = -1e18;
		int mxsofar = 0;
		for(int i=0;i<n;i++){
			mxsofar+=v[i];
		    mxsum=max(mxsum,mxsofar);
			if( mxsofar < 0 ){
				mxsofar = 0;
			}
		}
