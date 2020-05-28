1. (a^n)%mod       = (a^(n%(mod-1)))%mod : Fermets Little Theorem.
2. ( P/Q )%mod (Where P and Q are Relativily Prime) :
              (px)*(qx)^(-1) = p * q^(-1) % mod
              https://codeforces.com/blog/entry/57889     https://codeforces.com/gym/282114/submission/81680869
              so (P/Q)%mod = P Q^(-1) %mod
