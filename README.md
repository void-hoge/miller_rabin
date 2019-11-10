## Miller-Rabin Primality Test
実装しただけ  
https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test  
　以下のようにコマンドラインから入力する。  
` $ ./isprime.out 89`  
　素数なら`prime`, 合成数もしくは1以下の整数ならば`composite`と表示される。  
数字でないものが含まれている場合、内部的には0になるので`composite`になる。  (mpz_get_strを使っている関係)  
　多倍長整数の演算にはGNU Multi Precision Arithmetic Library(https://gmplib.org/ )を使っている。コンパイルにはGMPが必要。
